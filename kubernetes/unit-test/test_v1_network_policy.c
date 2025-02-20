#ifndef v1_network_policy_TEST
#define v1_network_policy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_network_policy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_network_policy.h"
v1_network_policy_t* instantiate_v1_network_policy(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_network_policy_spec.c"
#include "test_v1_network_policy_status.c"


v1_network_policy_t* instantiate_v1_network_policy(int include_optional) {
  v1_network_policy_t* v1_network_policy = NULL;
  if (include_optional) {
    v1_network_policy = v1_network_policy_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_network_policy_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_network_policy_status(0)
    );
  } else {
    v1_network_policy = v1_network_policy_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_network_policy;
}


#ifdef v1_network_policy_MAIN

void test_v1_network_policy(int include_optional) {
    v1_network_policy_t* v1_network_policy_1 = instantiate_v1_network_policy(include_optional);

	cJSON* jsonv1_network_policy_1 = v1_network_policy_convertToJSON(v1_network_policy_1);
	printf("v1_network_policy :\n%s\n", cJSON_Print(jsonv1_network_policy_1));
	v1_network_policy_t* v1_network_policy_2 = v1_network_policy_parseFromJSON(jsonv1_network_policy_1);
	cJSON* jsonv1_network_policy_2 = v1_network_policy_convertToJSON(v1_network_policy_2);
	printf("repeating v1_network_policy:\n%s\n", cJSON_Print(jsonv1_network_policy_2));
}

int main() {
  test_v1_network_policy(1);
  test_v1_network_policy(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_network_policy_MAIN
#endif // v1_network_policy_TEST
