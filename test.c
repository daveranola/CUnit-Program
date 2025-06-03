#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>
#include <math.h>
#include "MaxAvg.h"

// avgArray Tests

// Empty Array Test
void test_avgArray_empty_array(void) {
    double *arr = NULL;
    CU_ASSERT_TRUE(isnan(avgArray(arr, 0)));
}

// Single Element Test
void test_avgArray_single_element(void) {
    double arr[] = {5.5};
    CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 1), 5.5, 0.0001);
}

// Multiple Elements 
void test_avgArray_multiple_elements(void) {
    double arr[] = {1.0, 2.0, 3.0};
    CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), 2.0, 0.0001);
}

// All zeros
void test_avgArray_with_zeros(void) {
    double arr[] = {0.0, 0.0, 0.0};
    CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), 0.0, 0.0001);
}

// Mixed Negative Numbers
void test_avgArray_negative_numbers(void) {
    double arr[] = {-1.0, -2.0, -3.0};
    CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), -2.0, 0.0001);
}

// Mixed Positive And Negative Numbers
void test_avgArray_mixed_numbers(void) {
    double arr[] = {2.5, -1.5, 3.0, -2.0};
    CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 4), 0.5, 0.0001); 
}

// Some Elements the same
void test_avgArray_some_elements_same(void) {
    double arr[] = {1.0, 2.0, 1.0};
    CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), (1.0+2.0+1.0)/3.0, 0.0001);
    
}

// All elements the same
void test_avgArray_all_same(void) {
    double arr[] = {4.2, 4.2, 4.2};
    CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), 4.2, 0.0001);
}

// Mix of positve negative and zero 
void test_avgArray_zero_positive_negative_mix(void) {
    double arr[] = {-1.0, 0.0, 2.5};
    CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), (-1.0 + 0.0 + 2.5)/3.0, 0.0001);
}

void fail_test_avgArray(void) {
    double arr[] = {1.0, 2.0, 1.0};
    CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), 1.3, 0.0001); // fail case double inaccuracy
    CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), 5, 0.0001); // fail case wrong calculation
}

// maxArray tests

/// Empty array
void test_maxArray_empty_array(void) {
    double *arr = NULL;
    CU_ASSERT_TRUE(isnan(maxArray(arr, 0)));
}

// Single Element
void test_maxArray_single_element(void) {
    double arr[] = {7.3};
    CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 1), 7.3, 0.0001);
}

// Multiple Elements
void test_maxArray_multiple_elements(void) {
    double arr[] = {1.5, 3.0, 2.0};
    CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 3), 3.0, 0.0001);
}

// Mixture of negative and positve 0's
void test_maxArray_with_zeros(void) {
    double arr[] = {0.0, -0.0, 0.0};
    CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 3), 0.0, 0.0001);
}

// All negative numbers
void test_maxArray_negative_numbers(void) {
    double arr[] = {-5.0, -3.0, -1.5};
    CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 3), -1.5, 0.0001);
}

// Mixed Positive and Negative numbers
void test_maxArray_mixed_numbers(void) {
    double arr[] = {-2.0, 4.5, 3.0, -1.0};
    CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 4), 4.5, 0.0001);
}

// Some Elements the same
void test_maxArray_some_elements_same(void) {
    double arr[] = {1.0, 2.0, 1.0};
    CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 3), 2.0, 0.0001);
}

// All Elememts the same
void test_maxArray_all_same(void) {
    double arr[] = {2.2, 2.2, 2.2};
    CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 3), 2.2, 0.0001);
}

// Mix of positve negative and zero 
void test_maxArray_zero_positive_negative_mix(void) {
    double arr[] = {-1.0, 0.0, 2.5};
    CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 3), 2.5, 0.0001);
}

void fail_test_maxArray(void) {
    double arr[] = {1.0, 2.0, 1.0};
    CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), 5, 0.0001); // fail case wrong calculation
}

int main() {
    // initialize CUnit registry
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // add test suites
    CU_pSuite avgArraySuite = CU_add_suite("avgArray Test Suite", NULL, NULL);
    CU_pSuite maxArraySuite = CU_add_suite("maxArray Test Suite", NULL, NULL);

    // avgArray tests
    CU_add_test(avgArraySuite, "Empty Array",        test_avgArray_empty_array);
    CU_add_test(avgArraySuite, "Single Element",     test_avgArray_single_element);
    CU_add_test(avgArraySuite, "Multiple Elements",  test_avgArray_multiple_elements);
    CU_add_test(avgArraySuite, "All Zeros",          test_avgArray_with_zeros);
    CU_add_test(avgArraySuite, "Negative Numbers",   test_avgArray_negative_numbers);
    CU_add_test(avgArraySuite, "Mixed Numbers",      test_avgArray_mixed_numbers);
    CU_add_test(avgArraySuite, "Some Same Elements", test_avgArray_some_elements_same);
    CU_add_test(avgArraySuite, "All Same Elements",  test_avgArray_all_same);
    CU_add_test(avgArraySuite, "Mixed positve negative zero",  test_avgArray_zero_positive_negative_mix);
    CU_add_test(avgArraySuite, "Fail Cases",                   fail_test_avgArray);

    // maxArray tests
    CU_add_test(maxArraySuite, "Empty Array",        test_maxArray_empty_array);
    CU_add_test(maxArraySuite, "Single Element",     test_maxArray_single_element);
    CU_add_test(maxArraySuite, "Multiple Elements",  test_maxArray_multiple_elements);
    CU_add_test(maxArraySuite, "All Zeros",          test_maxArray_with_zeros);
    CU_add_test(maxArraySuite, "Negative Numbers",   test_maxArray_negative_numbers);
    CU_add_test(maxArraySuite, "Mixed Numbers",      test_maxArray_mixed_numbers);
    CU_add_test(maxArraySuite, "Some Same Elements", test_maxArray_some_elements_same);
    CU_add_test(maxArraySuite, "All Same Elements",  test_maxArray_all_same);
    CU_add_test(maxArraySuite, "Mixed positve negative zero",  test_maxArray_zero_positive_negative_mix);
    CU_add_test(maxArraySuite, "Fail Cases",                   fail_test_maxArray);

    // run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
