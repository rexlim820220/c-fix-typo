#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_priority_level_configuration_condition.h"



v1beta2_priority_level_configuration_condition_t *v1beta2_priority_level_configuration_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    v1beta2_priority_level_configuration_condition_t *v1beta2_priority_level_configuration_condition_local_var = malloc(sizeof(v1beta2_priority_level_configuration_condition_t));
    if (!v1beta2_priority_level_configuration_condition_local_var) {
        return NULL;
    }
    v1beta2_priority_level_configuration_condition_local_var->last_transition_time = last_transition_time;
    v1beta2_priority_level_configuration_condition_local_var->message = message;
    v1beta2_priority_level_configuration_condition_local_var->reason = reason;
    v1beta2_priority_level_configuration_condition_local_var->status = status;
    v1beta2_priority_level_configuration_condition_local_var->type = type;

    return v1beta2_priority_level_configuration_condition_local_var;
}


void v1beta2_priority_level_configuration_condition_free(v1beta2_priority_level_configuration_condition_t *v1beta2_priority_level_configuration_condition) {
    if(NULL == v1beta2_priority_level_configuration_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_priority_level_configuration_condition->last_transition_time) {
        free(v1beta2_priority_level_configuration_condition->last_transition_time);
        v1beta2_priority_level_configuration_condition->last_transition_time = NULL;
    }
    if (v1beta2_priority_level_configuration_condition->message) {
        free(v1beta2_priority_level_configuration_condition->message);
        v1beta2_priority_level_configuration_condition->message = NULL;
    }
    if (v1beta2_priority_level_configuration_condition->reason) {
        free(v1beta2_priority_level_configuration_condition->reason);
        v1beta2_priority_level_configuration_condition->reason = NULL;
    }
    if (v1beta2_priority_level_configuration_condition->status) {
        free(v1beta2_priority_level_configuration_condition->status);
        v1beta2_priority_level_configuration_condition->status = NULL;
    }
    if (v1beta2_priority_level_configuration_condition->type) {
        free(v1beta2_priority_level_configuration_condition->type);
        v1beta2_priority_level_configuration_condition->type = NULL;
    }
    free(v1beta2_priority_level_configuration_condition);
}

cJSON *v1beta2_priority_level_configuration_condition_convertToJSON(v1beta2_priority_level_configuration_condition_t *v1beta2_priority_level_configuration_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_priority_level_configuration_condition->last_transition_time
    if(v1beta2_priority_level_configuration_condition->last_transition_time) {
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v1beta2_priority_level_configuration_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1beta2_priority_level_configuration_condition->message
    if(v1beta2_priority_level_configuration_condition->message) {
    if(cJSON_AddStringToObject(item, "message", v1beta2_priority_level_configuration_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_priority_level_configuration_condition->reason
    if(v1beta2_priority_level_configuration_condition->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1beta2_priority_level_configuration_condition->reason) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_priority_level_configuration_condition->status
    if(v1beta2_priority_level_configuration_condition->status) {
    if(cJSON_AddStringToObject(item, "status", v1beta2_priority_level_configuration_condition->status) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_priority_level_configuration_condition->type
    if(v1beta2_priority_level_configuration_condition->type) {
    if(cJSON_AddStringToObject(item, "type", v1beta2_priority_level_configuration_condition->type) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta2_priority_level_configuration_condition_t *v1beta2_priority_level_configuration_condition_parseFromJSON(cJSON *v1beta2_priority_level_configuration_conditionJSON){

    v1beta2_priority_level_configuration_condition_t *v1beta2_priority_level_configuration_condition_local_var = NULL;

    // v1beta2_priority_level_configuration_condition->last_transition_time
    cJSON *last_transition_time = cJSON_GetObjectItemCaseSensitive(v1beta2_priority_level_configuration_conditionJSON, "lastTransitionTime");
    if (last_transition_time) { 
    if(!cJSON_IsString(last_transition_time) && !cJSON_IsNull(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1beta2_priority_level_configuration_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1beta2_priority_level_configuration_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1beta2_priority_level_configuration_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1beta2_priority_level_configuration_conditionJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v1beta2_priority_level_configuration_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1beta2_priority_level_configuration_conditionJSON, "status");
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // v1beta2_priority_level_configuration_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1beta2_priority_level_configuration_conditionJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }


    v1beta2_priority_level_configuration_condition_local_var = v1beta2_priority_level_configuration_condition_create (
        last_transition_time && !cJSON_IsNull(last_transition_time) ? strdup(last_transition_time->valuestring) : NULL,
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        status && !cJSON_IsNull(status) ? strdup(status->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL
        );

    return v1beta2_priority_level_configuration_condition_local_var;
end:
    return NULL;

}
