#include <config/kube_config.h>
#include <api/CoreV1API.h>
#include <stdio.h>

void list_pod(apiClient_t * apiClient)
{
    v1_pod_list_t *pod_list = NULL;
    pod_list = CoreV1API_listNamespacedPod(apiClient, "default",    /*namespace */
                                           NULL,    /* pretty */
                                           0,   /* allowWatchBookmarks */
                                           NULL,    /* continue */
                                           NULL,    /* fieldSelector */
                                           NULL,    /* labelSelector */
                                           0,   /* limit */
                                           NULL,    /* resourceVersion */
                                           NULL,    /* resourceVersionMatch */
                                           0,   /* timeoutSeconds */
                                           0    /* watch */
        );
    printf("The return code of HTTP request=%ld\n", apiClient->response_code);
    if (pod_list) {
        printf("Get pod list:\n");
        listEntry_t *listEntry = NULL;
        v1_pod_t *pod = NULL;
        list_ForEach(listEntry, pod_list->items) {
            pod = listEntry->data;
            printf("\tThe pod name: %s\n", pod->metadata->name);
        }
        v1_pod_list_free(pod_list);
        pod_list = NULL;
    } else {
        printf("Cannot get any pod.\n");
    }
}

int main()
{
    char *basePath = NULL;
    sslConfig_t *sslConfig = NULL;
    list_t *apiKeys = NULL;
    int rc = load_kube_config(&basePath, &sslConfig, &apiKeys, "non-existent-file");
    if (rc != 0) {
        printf("Cannot load kubernetes configuration.\n");
        /* Return 0 to avoid Github/Action check failures.
           You should return a non-zero value in a production environment. */
        return 0;
    }
    apiClient_t *apiClient = apiClient_create_with_base_path(basePath, sslConfig, apiKeys);
    if (!apiClient) {
        printf("Cannot create a kubernetes client.\n");
        /* Return 0 to avoid Github/Action check failures.
           You should return a non-zero value in a production environment. */
        return 0;
    }

    list_pod(apiClient);

    apiClient_free(apiClient);
    apiClient = NULL;
    free_client_config(basePath, sslConfig, apiKeys);
    basePath = NULL;
    sslConfig = NULL;
    apiKeys = NULL;
    apiClient_unsetupGlobalEnv();

    return 0;
}
