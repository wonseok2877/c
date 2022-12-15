/*Following are some interesting facts about function pointers.


.*/

#include <stdio.h>
#include <stdlib.h>

// A normal function with an int parameter and void return type
void fun(int a) { printf("Value of a is %d\n", a); }

void add(int a, int b) { printf("Addition is %d\n", a + b); }
void subtract(int a, int b) { printf("Subtraction is %d\n", a - b); }
void multiply(int a, int b) { printf("Multiplication is %d\n", a * b); }

/* A sample comparator function that is used */
/* for sorting an integer array in ascending order. */
/* To sort any array for any other data type and/or */
/* criteria, all we need to do is write more compare */
/* functions.  And we can use the same qsort() */
// 타입 변환을 위해 void pointer로 바꾸는듯? 메모리 크기 때문인가
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
/*
1) Unlike normal pointers, a function pointer points to code, not data.
Typically a function pointer stores the start of executable code. 
2) Unlike
normal pointers, we do not allocate de-allocate memory using function pointers.
*/
  // fun_ptr is a pointer to function fun()
  void (*fun_ptr)(int) = &fun;

  /* The above line is equivalent of following two
     void (*fun_ptr)(int);
     fun_ptr = &fun;
  */

  // Invoking fun() using fun_ptr
  (*fun_ptr)(10);

  /*3) A function’s name can also be used to get functions’ address. For example, in
the below program, we have removed address operator ‘&’ in assignment. We have
also changed function call by removing *, the program still works */
  void (*fun_ptr2)(int) = fun; // & removed. &fun과 같은 의미!! 함수 주솟값은 특별하게 처리하네.

  fun_ptr2(10000); // * removed

  /*4) Like normal pointers, we can have an array of function pointers. Below example in point 5 shows syntax for array of pointers. */
  // array of function pointers
  void (*fun_ptr_arr[])(int, int) = {&add, &subtract, &multiply};
  // 내 버전
  void *fun_ptr_arr2[] = {&add, &subtract, &multiply};

  unsigned int ch, a = 15, b = 10;

  printf("Enter Choice: 0 for add, 1 for subtract and 2 "
         "for multiply\n");
  scanf("%d", &ch);

  if (ch > 2)
    return 0;

  // Invoking function using fun_ptr
  // fun_ptr_arr[0] : a pointer to function add
  (*fun_ptr_arr[ch])(a, b);

  // quick sort
  int arr[] = {10, 5, 15, 12, 90, 80};
  int n = sizeof(arr) / sizeof(arr[0]);

/*  6) Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function. */
  qsort(arr, n, sizeof(int), &compare);

  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  return 0;
}

// 7) Many object oriented features in C++ are implemented using function pointers in C. For example virtual functions.
