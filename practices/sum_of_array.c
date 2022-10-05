#include <stdio.h>

/* sum_of_array
 * *arr : pointer to integer array
 * size : c 언어에선 배열 길이를 따로 받아야 한다. 
 * Function parameters never actually have array type. 내부적으로
 * 컴파일러는 pointer로 받아들이기 때문. 따라서 sizeof로 arr의 사이즈를 잴 수 없다. */
int sum_of_array(int *arr, int size) {
    // initialize sum
  int sum = 0;
  
  //  Iterate through all elements, and add them(each *p value) to sum
  for (int *p = arr; p < &arr[size]; p++) 
    sum += *p;
  
  return sum;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  int result = sum_of_array(arr, sizeof arr / sizeof arr[0]);
  printf("Sum of the array = %i\n", result);
}

// array indexing version
int other_solution(int arr[], int n)
{
    int sum = 0; // initialize sum
 
    // Iterate through all elements, and add them to sum
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    return sum;
}
