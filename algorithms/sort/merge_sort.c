/* 합병 정렬
 * 분할 정복 기법에 바탕을 둔 정렬 방법.
 * 기본적으로 분할 과정에서 재귀 호출을 쓴다.
 *
 * 1. 분할: 입력 배열을 같은 크기의 2개 부분 배열로 분할
 * 2. 정복: 부분 배열을 정렬. 부분 배열의 크기가 충분히 작지 않으면, 순환호출을
 * 이용해 다시
 * 3. 결합: 정렬된 부분 배열들을 하나의 배열에 통합.
 *
 * TODO 연결리스트로 구현해보기. 가장 효율적일 수 있다.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

int myList[SIZE];
int sorted[SIZE];

void randomize() {
  srand(time(NULL));
  for (int i = 0; i < SIZE; i++)
    myList[i] = rand() % 100;
}
void printList(int list[], int left, int right) {
  printf("[ ");
  for (int i = left; i < right; i++)
    printf("%i ", list[i]);
  printf("]\n");
}

// 2개의 인접한 배열 list[left...mid], list[mid+1...right]를 합병
void merge(int list[], int left, int mid, int right) {
  printf("merge--\n");
  printList(list, left, right);

  int l, i = left, j = mid + 1, k = left;

  // 핵심: 분할 정렬된 list의 합병
  // 왼쪽(left~mid)과 오른쪽(mid+1 ~ right) 중에 더 작은 값을 계속해서 sorted 배열에 넣는다.
  while (i <= mid && j <= right) {
    if (list[i] <= list[j])
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }

  printf("i > mid : %i\n", i>mid);

  // 남아있는 레코드의 일괄 복사
  if (i > mid)
    for (l = j; l <= right; l++)
      sorted[k++] = list[l];
  else
    for (l = i; l <= mid; l++)
      sorted[k++] = list[l];

  // 배열 sorted[] 리스트를 배열 list[]로 다시 복사
  for (l = left; l <= right; l++)
    list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right) {
          printf("\nmerge_sort--left=%i\tright=%i\n", left,right);
    printList(list, left, right);
    // 반으로 쪼개기
  if (left < right) {


    int mid = (left + right) / 2;
    merge_sort(list, left, mid);
    merge_sort(list, mid + 1, right);
    // 실제로 정렬이 이루어지는 시점
    merge(list, left, mid, right);
  }
}

int main() {
    randomize();

    printList(myList, 0, SIZE);
  merge_sort(myList, 0, SIZE-1 );

  printList(myList, 0, SIZE);
}
