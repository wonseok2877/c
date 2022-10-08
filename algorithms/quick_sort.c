#include <stdio.h>

/* swap : swap ith element with jth element */
void swap(int v[], int i, int j, int length) {
  printf("---------swap--------------\n");
  printf("v[%i]=%i\t v[%i]=%i\n", i, v[i], j, v[j]);

  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;

  printf("v[%i]=%i\t v[%i]=%i\n\n", i, v[i], j, v[j]);

  printf("[ ");
  for (int i = 0; i < length; i++) {
    printf("%i ", v[i]);
  }
  printf("] \n\n");
}

/* quick sort : sort v[left]...v[right] into increasing order */
void quick_sort(int v[], int left, int right, int length) {
  printf("---------quick_sort--------------\n");
  printf("\n left=%i\t right=%i\n\n", left, right);

  // do nothing if array contains fewer than two elements
  if (left >= right)
    return;

  // move partition(left) element to middle
  swap(v, left, (left + right) / 2, length);

  int last = left;

  // left + 1부터, right 번째까지 반복
  for (int i = left + 1; i <= right; i++) {
    printf("last=%i\t v[%i]=%i\t v[%i]=%i\n", last, i, v[i], left, v[left]);
    // 핵심 분기임. left+1 번째가 left번째보다 작을 경우, last+1번째와 i번째끼리 swap
    if (v[i] < v[left])
      swap(v, ++last, i, length);
  }
  swap(v, left, last, length);

  // recursive call
  quick_sort(v, left, last - 1, length);
  quick_sort(v, last + 1, right, length);
}

/* main */
int main() {
  int length = 9;
  int arr[9] = {10, 4, 5, 1, 9, 6, 3, 8, 2};
  int left = 0, right = 8;

  printf("[ ");
  for (int i = 0; i < 9; i++) {
    printf("%i ", arr[i]);
  }
  printf("] \n\n");

  quick_sort(arr, left, right, length);

  printf("[ ");
  for (int i = 0; i < 9; i++) {
    printf("%i ", arr[i]);
  }
  printf("] \n\n");
}
