#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_role_binding.h"



v1_role_binding_t *v1_role_binding_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_role_ref_t *role_ref,
    list_t *subjects
    ) {
    v1_role_binding_t *v1_role_binding_local_var = malloc(sizeof(v1_role_binding_t));
    if (!v1_role_binding_local_var) {
        return NULL;
    }
    v1_role_binding_local_var->api_version = api_version;
    v1_role_binding_local_var->kind = kind;
    v1_role_binding_local_var->metadata = metadata;
    v1_role_binding_local_var->role_ref = role_ref;
    v1_role_binding_local_var->subjects = subjects;

    return v1_role_binding_local_var;
}


void v1_role_binding_free(v1_role_binding_t *v1_role_binding) {
    if(NULL == v1_role_binding){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_role_binding->api_version) {
        free(v1_role_binding->api_version);
        v1_role_binding->api_version = NULL;
    }
    if (v1_role_binding->kind) {
        free(v1_role_binding->kind);
        v1_role_binding->kind = NULL;
    }
    if (v1_role_binding->metadata) {
        v1_object_meta_free(v1_role_binding->metadata);
        v1_role_binding->metadata = NULL;
    }
    if (v1_role_binding->role_ref) {
        v1_role_ref_free(v1_role_binding->role_ref);
        v1_role_binding->role_ref = NULL;
    }
    if (v1_role_binding->subjects) {
        list_ForEach(listEntry, v1_role_binding->subjects) {
            v1_subject_free(listEntry->data);
        }
        list_freeList(v1_role_binding->subjects);
        v1_role_binding->subjects = NULL;
    }
    free(v1_role_binding);
}

cJSON *v1_role_binding_convertToJSON(v1_role_binding_t *v1_role_binding) {
    cJSON *item = cJSON_CreateObject();

    // v1_role_binding->api_version
    if(v1_role_binding->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_role_binding->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_role_binding->kind
    if(v1_role_binding->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_role_binding->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_role_binding->metadata
    if(v1_role_binding->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_role_binding->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_role_binding->role_ref
    if (!v1_role_binding->role_ref) {
        goto fail;
    }
    cJSON *role_ref_local_JSON = v1_role_ref_convertToJSON(v1_role_binding->role_ref);
    if(role_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "roleRef", role_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_role_binding->subjects
    if(v1_role_binding->subjects) {
    cJSON *subjects = cJSON_AddArrayToObject(item, "subjects");
    if(subjects == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *subjectsListEntry;
    if (v1_role_binding->subjects) {
    list_ForEach(subjectsListEntry, v1_role_binding->subjects) {
    cJSON *itemLocal = v1_subject_convertToJSON(subjectsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(subjects, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_role_binding_t *v1_role_binding_parseFromJSON(cJSON *v1_role_bindingJSON){

    v1_role_binding_t *v1_role_binding_local_var = NULL;

    // define the local variable for v1_role_binding->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_role_binding->role_ref
    v1_role_ref_t *role_ref_local_nonprim = NULL;

    // define the local list for v1_role_binding->subjects
    list_t *subjectsList = NULL;

    // v1_role_binding->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_role_bindingJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_role_binding->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_role_bindingJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_role_binding->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_role_bindingJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_role_binding->role_ref
    cJSON *role_ref = cJSON_GetObjectItemCaseSensitive(v1_role_bindingJSON, "roleRef");
    if (!role_ref) {
        goto end;
    }

    
    role_ref_local_nonprim = v1_role_ref_parseFromJSON(role_ref); //nonprimitive

    // v1_role_binding->subjects
    cJSON *subjects = cJSON_GetObjectItemCaseSensitive(v1_role_bindingJSON, "subjects");
    if (subjects) { 
    cJSON *subjects_local_nonprimitive = NULL;
    if(!cJSON_IsArray(subjects)){
        goto end; //nonprimitive container
    }

    subjectsList = list_createList();

    cJSON_ArrayForEach(subjects_local_nonprimitive,subjects )
    {
        if(!cJSON_IsObject(subjects_local_nonprimitive)){
            goto end;
        }
        v1_subject_t *subjectsItem = v1_subject_parseFromJSON(subjects_local_nonprimitive);

        list_addElement(subjectsList, subjectsItem);
    }
    }


    v1_role_binding_local_var = v1_role_binding_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        role_ref_local_nonprim,
        subjects ? subjectsList : NULL
        );

    return v1_role_binding_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (role_ref_local_nonprim) {
        v1_role_ref_free(role_ref_local_nonprim);
        role_ref_local_nonprim = NULL;
    }
    if (subjectsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, subjectsList) {
            v1_subject_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(subjectsList);
        subjectsList = NULL;
    }
    return NULL;

}
