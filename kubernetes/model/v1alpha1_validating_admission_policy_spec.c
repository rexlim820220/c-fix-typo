#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_validating_admission_policy_spec.h"



v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec_create(
    char *failure_policy,
    v1alpha1_match_resources_t *match_constraints,
    v1alpha1_param_kind_t *param_kind,
    list_t *validations
    ) {
    v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec_local_var = malloc(sizeof(v1alpha1_validating_admission_policy_spec_t));
    if (!v1alpha1_validating_admission_policy_spec_local_var) {
        return NULL;
    }
    v1alpha1_validating_admission_policy_spec_local_var->failure_policy = failure_policy;
    v1alpha1_validating_admission_policy_spec_local_var->match_constraints = match_constraints;
    v1alpha1_validating_admission_policy_spec_local_var->param_kind = param_kind;
    v1alpha1_validating_admission_policy_spec_local_var->validations = validations;

    return v1alpha1_validating_admission_policy_spec_local_var;
}


void v1alpha1_validating_admission_policy_spec_free(v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec) {
    if(NULL == v1alpha1_validating_admission_policy_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_validating_admission_policy_spec->failure_policy) {
        free(v1alpha1_validating_admission_policy_spec->failure_policy);
        v1alpha1_validating_admission_policy_spec->failure_policy = NULL;
    }
    if (v1alpha1_validating_admission_policy_spec->match_constraints) {
        v1alpha1_match_resources_free(v1alpha1_validating_admission_policy_spec->match_constraints);
        v1alpha1_validating_admission_policy_spec->match_constraints = NULL;
    }
    if (v1alpha1_validating_admission_policy_spec->param_kind) {
        v1alpha1_param_kind_free(v1alpha1_validating_admission_policy_spec->param_kind);
        v1alpha1_validating_admission_policy_spec->param_kind = NULL;
    }
    if (v1alpha1_validating_admission_policy_spec->validations) {
        list_ForEach(listEntry, v1alpha1_validating_admission_policy_spec->validations) {
            v1alpha1_validation_free(listEntry->data);
        }
        list_freeList(v1alpha1_validating_admission_policy_spec->validations);
        v1alpha1_validating_admission_policy_spec->validations = NULL;
    }
    free(v1alpha1_validating_admission_policy_spec);
}

cJSON *v1alpha1_validating_admission_policy_spec_convertToJSON(v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_validating_admission_policy_spec->failure_policy
    if(v1alpha1_validating_admission_policy_spec->failure_policy) {
    if(cJSON_AddStringToObject(item, "failurePolicy", v1alpha1_validating_admission_policy_spec->failure_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_validating_admission_policy_spec->match_constraints
    if(v1alpha1_validating_admission_policy_spec->match_constraints) {
    cJSON *match_constraints_local_JSON = v1alpha1_match_resources_convertToJSON(v1alpha1_validating_admission_policy_spec->match_constraints);
    if(match_constraints_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "matchConstraints", match_constraints_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_validating_admission_policy_spec->param_kind
    if(v1alpha1_validating_admission_policy_spec->param_kind) {
    cJSON *param_kind_local_JSON = v1alpha1_param_kind_convertToJSON(v1alpha1_validating_admission_policy_spec->param_kind);
    if(param_kind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "paramKind", param_kind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_validating_admission_policy_spec->validations
    if (!v1alpha1_validating_admission_policy_spec->validations) {
        goto fail;
    }
    cJSON *validations = cJSON_AddArrayToObject(item, "validations");
    if(validations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *validationsListEntry;
    if (v1alpha1_validating_admission_policy_spec->validations) {
    list_ForEach(validationsListEntry, v1alpha1_validating_admission_policy_spec->validations) {
    cJSON *itemLocal = v1alpha1_validation_convertToJSON(validationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(validations, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec_parseFromJSON(cJSON *v1alpha1_validating_admission_policy_specJSON){

    v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec_local_var = NULL;

    // define the local variable for v1alpha1_validating_admission_policy_spec->match_constraints
    v1alpha1_match_resources_t *match_constraints_local_nonprim = NULL;

    // define the local variable for v1alpha1_validating_admission_policy_spec->param_kind
    v1alpha1_param_kind_t *param_kind_local_nonprim = NULL;

    // define the local list for v1alpha1_validating_admission_policy_spec->validations
    list_t *validationsList = NULL;

    // v1alpha1_validating_admission_policy_spec->failure_policy
    cJSON *failure_policy = cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_specJSON, "failurePolicy");
    if (failure_policy) { 
    if(!cJSON_IsString(failure_policy) && !cJSON_IsNull(failure_policy))
    {
    goto end; //String
    }
    }

    // v1alpha1_validating_admission_policy_spec->match_constraints
    cJSON *match_constraints = cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_specJSON, "matchConstraints");
    if (match_constraints) { 
    match_constraints_local_nonprim = v1alpha1_match_resources_parseFromJSON(match_constraints); //nonprimitive
    }

    // v1alpha1_validating_admission_policy_spec->param_kind
    cJSON *param_kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_specJSON, "paramKind");
    if (param_kind) { 
    param_kind_local_nonprim = v1alpha1_param_kind_parseFromJSON(param_kind); //nonprimitive
    }

    // v1alpha1_validating_admission_policy_spec->validations
    cJSON *validations = cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_specJSON, "validations");
    if (!validations) {
        goto end;
    }

    
    cJSON *validations_local_nonprimitive = NULL;
    if(!cJSON_IsArray(validations)){
        goto end; //nonprimitive container
    }

    validationsList = list_createList();

    cJSON_ArrayForEach(validations_local_nonprimitive,validations )
    {
        if(!cJSON_IsObject(validations_local_nonprimitive)){
            goto end;
        }
        v1alpha1_validation_t *validationsItem = v1alpha1_validation_parseFromJSON(validations_local_nonprimitive);

        list_addElement(validationsList, validationsItem);
    }


    v1alpha1_validating_admission_policy_spec_local_var = v1alpha1_validating_admission_policy_spec_create (
        failure_policy && !cJSON_IsNull(failure_policy) ? strdup(failure_policy->valuestring) : NULL,
        match_constraints ? match_constraints_local_nonprim : NULL,
        param_kind ? param_kind_local_nonprim : NULL,
        validationsList
        );

    return v1alpha1_validating_admission_policy_spec_local_var;
end:
    if (match_constraints_local_nonprim) {
        v1alpha1_match_resources_free(match_constraints_local_nonprim);
        match_constraints_local_nonprim = NULL;
    }
    if (param_kind_local_nonprim) {
        v1alpha1_param_kind_free(param_kind_local_nonprim);
        param_kind_local_nonprim = NULL;
    }
    if (validationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, validationsList) {
            v1alpha1_validation_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(validationsList);
        validationsList = NULL;
    }
    return NULL;

}
