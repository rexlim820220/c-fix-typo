/*
 * v1alpha1_validating_admission_policy.h
 *
 * ValidatingAdmissionPolicy describes the definition of an admission validation policy that accepts or rejects an object without changing it.
 */

#ifndef _v1alpha1_validating_admission_policy_H_
#define _v1alpha1_validating_admission_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_validating_admission_policy_t v1alpha1_validating_admission_policy_t;

#include "v1_object_meta.h"
#include "v1alpha1_validating_admission_policy_spec.h"



typedef struct v1alpha1_validating_admission_policy_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_validating_admission_policy_spec_t *spec; //model

} v1alpha1_validating_admission_policy_t;

v1alpha1_validating_admission_policy_t *v1alpha1_validating_admission_policy_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_validating_admission_policy_spec_t *spec
);

void v1alpha1_validating_admission_policy_free(v1alpha1_validating_admission_policy_t *v1alpha1_validating_admission_policy);

v1alpha1_validating_admission_policy_t *v1alpha1_validating_admission_policy_parseFromJSON(cJSON *v1alpha1_validating_admission_policyJSON);

cJSON *v1alpha1_validating_admission_policy_convertToJSON(v1alpha1_validating_admission_policy_t *v1alpha1_validating_admission_policy);

#endif /* _v1alpha1_validating_admission_policy_H_ */

