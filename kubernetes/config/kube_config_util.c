#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/apiClient.h"

#define KUBE_CONFIG_TEMPFILE_NAME_TEMPLATE "/tmp/kubeconfig-XXXXXX"

static bool is_cert_or_key_base64_encoded(const char *data)
{
    if (NULL == strstr(data, "BEGIN")) {
        return true;
    } else {
        return false;           // e.g. "-----BEGIN CERTIFICATE-----\n...\n-----END CERTIFICATE-----"
    }
}

char *kubeconfig_mk_cert_key_tempfile(const char *data)
{
    static char fname[] = "kubeconfig_mk_tempfile()";

    const char *cert_key_data = NULL;
    int cert_key_data_bytes = 0;

    bool is_data_base64_encoded = is_cert_or_key_base64_encoded(data);
    if (true == is_data_base64_encoded) {
        int decoded_bytes = 0;
        char *b64decode = base64decode(data, strlen(data), &decoded_bytes);
        if (!b64decode || 0 == decoded_bytes) {
            fprintf(stderr, "%s: Base64 decodes failed.\n", fname);
            return NULL;
        }
        cert_key_data = b64decode;
        cert_key_data_bytes = decoded_bytes;
    } else {                    // plain text, no need base64 decode
        cert_key_data = data;
        cert_key_data_bytes = strlen(cert_key_data);
    }

    char tempfile_name_template[] = KUBE_CONFIG_TEMPFILE_NAME_TEMPLATE;
    int fd = mkstemp(tempfile_name_template);
    if (-1 == fd) {
        fprintf(stderr, "%s: Creating temp file for kubeconfig failed with error [%s]\n", fname, strerror(errno));
        return NULL;
    }

    int rc = write(fd, cert_key_data, cert_key_data_bytes);
    close(fd);
    if (true == is_data_base64_encoded && cert_key_data) {
        free((char *) cert_key_data);   // cast "const char *" to "char *" 
        cert_key_data = NULL;
    }
    if (-1 == rc) {
        fprintf(stderr, "%s: Writing temp file failed with error [%s]\n", fname, strerror(errno));
        return NULL;
    }

    return strdup(tempfile_name_template);
}

static void kubeconfig_rm_tempfile(const char *filename)
{
    if (filename) {
        unlink(filename);
    }
}

void unsetSslConfig(sslConfig_t * sslConfig)
{
    if (!sslConfig) {
        return;
    }

    if (sslConfig->clientCertFile) {
        kubeconfig_rm_tempfile(sslConfig->clientCertFile);
    }
    if (sslConfig->clientKeyFile) {
        kubeconfig_rm_tempfile(sslConfig->clientKeyFile);
    }
    if (sslConfig->CACertFile) {
        kubeconfig_rm_tempfile(sslConfig->CACertFile);
    }
}

void clear_and_free_string_pair_list(list_t * list)
{
    if (!list) {
        return;
    }

    listEntry_t *listEntry = NULL;
    list_ForEach(listEntry, list) {
        keyValuePair_t *pair = listEntry->data;
        if (pair->key) {
            free(pair->key);
            pair->key = NULL;
        }
        if (pair->value) {
            free(pair->value);
            pair->value = NULL;
        }
        keyValuePair_free(pair);
        pair = NULL;
    }
    list_free(list);
}
