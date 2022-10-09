#include <ctype.h>
#include <stdio.h>

void swap_1(int x, int y) {
  int temp;

  temp = x;
  x = y;
  y = temp;
}
void swap_2(int *px, int *py) {
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}
void increment(int *n) { *n += 1; (*n)++; ++(*n); ++*n; }

void increment_element(int *arr){
    printf("%p\n", arr);
(*arr)++;
}
void increment_next_element(int *arr){
 (*++arr)++;
}

/* shellsort : sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n) {
  int gap, i, j, temp;
  printf("length=%i\n", n);

  for (gap = n / 2; gap > 0; gap /= 2) {
    printf("gap=%i\n", gap);
    for (i = gap; i < n; i++) {
      printf("\t i=%i\n", i);
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        printf("v[j]=%i\t v[j+gap]=%i\n", v[j], v[j + gap]);
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
        printf("v[j]=%i\t v[j+gap]=%i\n", v[j], v[j + gap]);
      }
    }
  }
  // v 바꿔치기. 이렇게 해도, copy이기 때문에 원본 (arr)에는 변화가 없다.
  // 그러나 element들의 변화는 남아있다. call by reference였으니까.
  printf("v is pointing to=%p\n", v);
  int new_arr[] = {1};
  v=new_arr;
    printf("v is pointing to=%p\n", v);
v= NULL;
    printf("v is pointing to=%p\n", v);
}

int main() {
  int a = 3, b = 9;

  // call by value
  swap_1(a, b);
  printf("a:%i\tb:%i\n", a, b);
  // call by reference
  swap_2(&a, &b);

  printf("a:%i\tb:%i\n", a, b);

  increment(&a);
  printf("a=%i\n", a);
  increment(&a);
  printf("a=%i\n", a);
  increment(&a);
  printf("a=%i\n", a);
  increment(&a);
  printf("a=%i\n", a);
    

   int arr[] = {10, 1, 49, 100, 6, 34};


    for (int i = 0; i < sizeof arr / sizeof arr[0]; i++) {
    printf("%i\n", arr[i]);
  }
    printf("arr is pointing to=%p\n", arr);

  shellsort(arr, sizeof arr / sizeof arr[0]);
 
  printf("arr is pointing to=%p\n", arr);

  for (int i = 0; i < sizeof arr / sizeof arr[0]; i++) {
    printf("%i\n", arr[i]);
  }


}
