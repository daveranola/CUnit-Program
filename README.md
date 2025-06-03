---

# Assignment 4 – Cunit, Dave Ranola 

---

## How to Compile the Tests

To compile the test program with CUnit and your source files, run:

```bash
gcc -o test_runner test.c MaxAvg.c -lcunit
```

* `-o test_runner` — output executable named `test_runner`
* `test.c` — contains your test cases
* `MaxAvg.c` — contains the implementations of `avgArray` and `maxArray`
* `-lcunit` — links the CUnit testing framework library

Run tests with:

```bash
./test_runner
```

---

## Test Cases – Average Function (`avgArray`)

* **Empty Array**

  ```c
  double *arr = NULL;
  CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 0), 0.0, 0.0001);
  ```

  Returns pass as function correctly returns `0.0`.

* **Single Element**

  ```c
  double arr[] = {5.5};
  CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 1), 5.5, 0.0001);
  ```

  Pass, function returns `5.5`.

* **Multiple Elements**

  ```c
  double arr[] = {1.0, 2.0, 3.0};
  CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), 2.0, 0.0001);
  CU_ASSERT(maxArray(arr, 3) == 2.0); // fails due to double precision issues
  ```

  First passes; second fails due to precision — demonstrates why `CU_ASSERT_DOUBLE_EQUAL` is preferred.

* **All Zeros**

  ```c
  double arr[] = {0.0, 0.0, 0.0};
  CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), 0.0, 0.0001);
  ```

  Pass, returns `0.0`.

* **Negative Numbers**

  ```c
  double arr[] = {-1.0, -2.0, -3.0};
  CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), -2.0, 0.0001);
  ```

  Pass, returns `-2.0`.

* **Mixed Numbers**

  ```c
  double arr[] = {2.5, -1.5, 3.0, -2.0};
  CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 4), 0.5, 0.0001);
  ```

  Pass, returns `0.5`.

* **All Same**

  ```c
  double arr[] = {4.2, 4.2, 4.2};
  CU_ASSERT_DOUBLE_EQUAL(avgArray(arr, 3), 4.2, 0.0001);
  ```

  Pass, returns `4.2`.

---

## Test Cases – Max Function (`maxArray`)

* **Empty Array**

  ```c
  double *arr = NULL;
  CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 0), 0.0, 0.0001);
  ```

  Pass, function returns `0.0`.

* **Single Element**

  ```c
  double arr[] = {7.3};
  CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 1), 7.3, 0.0001);
  ```

  Pass, returns `7.3`.

* **Multiple Elements**

  ```c
  double arr[] = {1.5, 3.0, 2.0};
  CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 3), 3.0, 0.0001);
  ```

  Pass, returns `3.0`.

* **All Zeros**

  ```c
  double arr[] = {0.0, 0.0, 0.0};
  CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 3), 0.0, 0.0001);
  ```

  Pass, returns `0.0`.

* **Negative Numbers**

  ```c
  double arr[] = {-5.0, -3.0, -1.5};
  CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 3), -1.5, 0.0001);
  ```

  Pass, returns `-1.5`.

* **Mixed Numbers**

  ```c
  double arr[] = {-2.0, 4.5, 3.0, -1.0};
  CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 4), 4.5, 0.0001);
  ```

  Pass, returns `4.5`.

* **All Same**

  ```c
  double arr[] = {2.2, 2.2, 2.2};
  CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 3), 2.2, 0.0001);
  ```

  Pass, returns `2.2`.

* **Fail Example**

  ```c
  CU_ASSERT_DOUBLE_EQUAL(maxArray(arr, 3), 0.0, 0.0001);
  ```

  Fails because function returns `2.2`, but assertion expects `0.0`.

---

