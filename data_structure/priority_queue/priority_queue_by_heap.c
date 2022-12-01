/* priority queue heap ADT
 * 히프의 효율은 O(log2n)로, 우선순위 큐에서 상당히 유리
 * 여기선 최대히프만 다루자.
 *
 * 히프는 완전 이진 트리.  
 * 부모 노드의 키 값이 자식 노드의 키 값보다 항상 크거나 같다.
 * 이진탐색트리와 달리 노드간의 중복된 값을 허용한다.
 * 왼쪽 자식의 index = parent index * 2
 * 오른쪽 자식의 index = parent index * 2 + 1
 * 부모 노드의 index = 자식 노드의 index / 2
 *
 * data
 * 히프는 1차원 배열로 표현될 수 있다. (index 0은 비어있음)
 * 각 원소의 1차원 배열과 heap_size를 묶은 구조체가 heap가 된다.
 *
 * operation
 * 삽입
 * 1. 새로운 노드를 생성
 * 2. 히프의 마지막 노드로 삽입
 * 3. 히프 트리의 성질을 만족시키는 과정..
 *      새로운 노드를 부모 노드들과 반복 교환(재구성)
 * 
 * 삭제
 * 1. 최대 히프이므로 삭제는 최대값을 갖는 요소
 * 최대 히프에서 최대값은 루트노드이므로 루트노드를 삭제. 
 * 2. 히프 트리의 성질을 만족시키기 위해 재구성.
 *      자식 노드들과 반복 비교, 교환
 * */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEGNTH 200

// type definition
typedef struct {
int key
} element;

typedef struct {
    element arr[MAX_LEGNTH];
    int heapSize;
}Heap;

// insert
void insert_max_heap(Heap *h, element item){
    // 새로운 index는 마지막 index
    int i = ++(h->heapSize);
    // 부모 노드와 비교하면서 올라가는 과정
    while ((i!=1) && item.key > h->arr[i/2].key){
        h->arr[i] = h->arr[i/2];
        i /= 2;
    }
    h->arr[i]=item;
}

element delete_max_heap(Heap *h){
    int parent=1, child=2;
    element item, temp;

    item = h->arr[1];
    temp = h->arr[h->heapSize --];

    while (child <=h->heapSize){
    // 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.

    }
}
