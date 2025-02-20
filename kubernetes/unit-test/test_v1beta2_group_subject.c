#ifndef v1beta2_group_subject_TEST
#define v1beta2_group_subject_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_group_subject_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_group_subject.h"
v1beta2_group_subject_t* instantiate_v1beta2_group_subject(int include_optional);



v1beta2_group_subject_t* instantiate_v1beta2_group_subject(int include_optional) {
  v1beta2_group_subject_t* v1beta2_group_subject = NULL;
  if (include_optional) {
    v1beta2_group_subject = v1beta2_group_subject_create(
      "0"
    );
  } else {
    v1beta2_group_subject = v1beta2_group_subject_create(
      "0"
    );
  }

  return v1beta2_group_subject;
}


#ifdef v1beta2_group_subject_MAIN

void test_v1beta2_group_subject(int include_optional) {
    v1beta2_group_subject_t* v1beta2_group_subject_1 = instantiate_v1beta2_group_subject(include_optional);

	cJSON* jsonv1beta2_group_subject_1 = v1beta2_group_subject_convertToJSON(v1beta2_group_subject_1);
	printf("v1beta2_group_subject :\n%s\n", cJSON_Print(jsonv1beta2_group_subject_1));
	v1beta2_group_subject_t* v1beta2_group_subject_2 = v1beta2_group_subject_parseFromJSON(jsonv1beta2_group_subject_1);
	cJSON* jsonv1beta2_group_subject_2 = v1beta2_group_subject_convertToJSON(v1beta2_group_subject_2);
	printf("repeating v1beta2_group_subject:\n%s\n", cJSON_Print(jsonv1beta2_group_subject_2));
}

int main() {
  test_v1beta2_group_subject(1);
  test_v1beta2_group_subject(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_group_subject_MAIN
#endif // v1beta2_group_subject_TEST
