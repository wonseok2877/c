#include <stdio.h>

/* shellsort : sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n) {
  int gap, i, j, temp;
  printf("length=%i\n", n);

  // 1. length /2 를 gap에 할당. gap이 0이 되기 전까지, gap을 2로 나누면서 반복
  for (gap = n / 2; gap > 0; gap /= 2) {
    printf("gap=%i\n", gap);
    // 2. i가 length안에서 gap index부터 끝 index까지 반복
    for (i = gap; i < n; i++) {
      printf("\t i=%i\n", i);
      // 3. j index의 element가 gap만큼 뒤 index의 element보다 클 때 반복
      // 두 element의 값을 서로 바꿈.
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        printf("v[j]=%i\t v[j+gap]=%i\n", v[j], v[j + gap]);
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
        printf("v[j]=%i\t v[j+gap]=%i\n", v[j], v[j + gap]);
      }
    }
  }
}

int main() {

  int arr[] = {10, 1, 49, 100, 6, 34};

  shellsort(arr, sizeof arr / sizeof arr[0]);

  for (int i = 0; i < sizeof arr / sizeof arr[0]; i++) {
    printf("%i\n", arr[i]);
  }
}
