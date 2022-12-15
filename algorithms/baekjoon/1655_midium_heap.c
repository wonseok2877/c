/*
 * 백준이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다. 백준이가 정수를
하나씩 외칠때마다 동생은 지금까지 백준이가 말한 수 중에서 중간값을 말해야 한다.
만약, 그동안 백준이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은
수를 말해야 한다.

예를 들어 백준이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면,
동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다. 백준이가 외치는 수가 주어졌을
때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 백준이가 외치는 정수의 개수 N이 주어진다. N은 1보다 크거나 같고,
100,000보다 작거나 같은 자연수이다. 그 다음 N줄에 걸쳐서 백준이가 외치는 정수가
차례대로 주어진다. 정수는 -10,000보다 크거나 같고, 10,000보다 작거나 같다.

출력
한 줄에 하나씩 N줄에 걸쳐 백준이의 동생이 말해야 하는 수를 순서대로 출력한다.


문제접근
heap size와 size/2가 중요. 어차피 나눗셈의 값은 정수로 내림되니
두 수 중의 작은 수는 자동적으로 해결.
최소힙을 쓰자.(상관은 없다)

delete함수는 필요없다.
insert함수: 삽입을 한 이후에 중간값을 출력하면 된다.
index를 정하는게 핵심.
size ++, 막내 자리에서 시작
loop: 윗노드들과 비교
    윗노드가 더 클 경우, 끌어내린다.
    더 작거나 같을 경우, 힙 트리 조건 만족.

문제점
  // 이거 힙이 아니라 다른 배열 정렬방법이 나을 거 같은데?
  // 다른 풀이들을 보니까, 최소힙과 최대힙 둘 다 쓴다.
  // 최소힙의 최소와 최대힙의 최대를 서로 비교..

배운점
!! 오름차순 정렬된 묶음과 내림차순 정렬된 묶음으로 전체를 쪼개야 한다.

최소힙과 최대힙으로 전체를 쪼갠다.
최소힙에는 root보다 큰 수들이 쌓이고,
최대힙에는 root보다 작은 수들이 쌓인다.

서로의 루트 노드끼리 비교한다.

- 틀렸습니다...
https://www.crocus.co.kr/625
https://waves123.tistory.com/59
문제 해결에 필요한 사항

1. 최대 힙, 최소 힙
2. Priority Queue
3. pq로 중간 값 구하는 방식

중간값 구하기 과정

1. 최대 힙의 크기는 최소 힙의 크기와 같거나, 하나 더 크다.
2. 최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.
이때 알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap해준다.
[결과] 이때 이 두가지 규칙을 유지해 준다면 항상 최대 힙 top값이 중간값이 된다.

위 토대로 구현해봄
insert 함수 2개, 각 루트노드를 비교, swap 함수.
insertToMinHeap(int item)
insertToMaxHeap(int item)
swap


궁금한 점
이걸 구현하는 방법에는 뭐가 있을까?
중간값을 위해서 전체를 둘로 쪼개거나, (힙 혹은 배열)
오름차순 정렬을 한 뒤에 index상의 중위에 있는 값을 구하는 방법이 있을 것 같다.
힙을 써야만 할 필요는 없다.
*/
#include <stdio.h>

// x: 최대힙 y: 최소힙
int xHeap[100000];
int yHeap[100000];
int xSize = 0;
int ySize = 0;

// insertToMaxHeap : 최대힙에 삽입
void insertToMaxHeap(int item) {
  int target = ++xSize;
  // 루트노드가 아니고 item이 윗노드보다 큰 동안 반복
  while (target != 1 && item > xHeap[target / 2]) {
    xHeap[target] = xHeap[target / 2];
    target /= 2;
  }
  xHeap[target] = item;
}
// insertToMinHeap : 최소힙에 삽입
void insertToMinHeap(int item) {
  int target = ++ySize;

  // 루트노드가 아니고 item이 윗노드보다 작은동안 반복
  while (target != 1 && item < yHeap[target / 2]) {
    yHeap[target] = yHeap[target / 2];
    target /= 2;
  }
  yHeap[target] = item;
}
// swap : root에 새로운 값을 앉히고,(삭제는 안 함) 
// delete때와 같이 아랫노드와 비교해간다
void swapMaxHeap(int item){
    int parent=1, child=2;
    
            // 최대힙이므로 아랫노드가 더 작거나 같아야 한다.
    while (child <= xSize ){
        // 더 큰 아랫노드 고르기
        if (child < xSize && xHeap[child] < xHeap[child +1])
            child ++;
        if (item >= xHeap[child]) break;
        // 아랫노드가 더 크다면 끌어올리기
        else {
            xHeap[parent] = xHeap[child];
            parent = child;
            child *= 2;
        }
    }
    xHeap[parent]= item;
}
void swapMinHeap(int item){
    int parent=1, child=2;

    while (child <= ySize){
        if (child < ySize && yHeap[child] > yHeap[child+1] )
            child++;

        if (item <= yHeap[child]) break;
        else {
            yHeap[parent] = yHeap[child];
            parent=child;
            child *=2;
        }
    }
    yHeap[parent] = item;
}

void maxHeapify() {
    // index
	int current = 1;
    // 왼쪽 자식 index가 사이즈보다 작을 때
	while (current * 2 < xSize)
	{
        // 아랫노드 index
		int child;
        // 오른쪽 자식 index가 마지막일 때
		if (current * 2 + 1 == xSize) child = current * 2 ;
        // 더 큰 놈으로.
		else child = xHeap[current * 2 ] > xHeap[current * 2 + 1] ? current * 2  : current * 2 + 1;

        // 현재놈이 자식보다 클 경우, 만족이므로 끝
		if (xHeap[current] > xHeap[child]) break;

        // 현재놈과 막내놈을 swap
		int temp = xHeap[current];
		xHeap[current] = xHeap[child];
		xHeap[child] = temp;
		current = child;
	}
}
void minHeapify() {
    // index
	int current = 1;
    // 왼쪽 자식 index가 사이즈보다 작을 때
	while (current * 2 < ySize)
	{
        // 아랫노드 index
		int child;
        // 오른쪽 자식 index가 마지막일 때
		if (current * 2 + 1 == ySize) child = current * 2 ;
        // 더 작은 놈으로.
		else child = yHeap[current * 2 ] < yHeap[current * 2 + 1] ? current * 2  : current * 2 + 1;

        // 현재놈이 자식보다 클 경우, 만족이므로 끝
		if (yHeap[current] < yHeap[child]) break;

        // 현재놈과 막내놈을 swap
		int temp = yHeap[current];
		yHeap[current] = yHeap[child];
		yHeap[child] = temp;
		current = child;
	}
}

int main() {
  int n;
  scanf("%i", &n);
  while (n--) {
    int input;
    scanf("%i", &input);
    // input 값의 범위, size 상관 없이 모두 insert.

    // size % 2 = 0일 땐 최대 힙에, 아닐 땐 최소힙에
    // 각각의 조건에 맞게 1차적으로 정렬
    if (xSize == ySize)
      insertToMaxHeap(input);
    else
      insertToMinHeap(input);


    // 각각의 root node를 비교
    // 최대힙의 root가 최소힙쪽 root보다 크다면, swap.
    // 힙의 조건에 맞게 2차적으로 정렬
    if (xSize >0 && ySize >0 &&  xHeap[1] > yHeap[1]) {
      int temp = xHeap[1];
      // swap: 위의 루트노드를 삭제하고 최소힙의 루트 삽입
      xHeap[1] = yHeap[1];
      yHeap[1] = temp;
      maxHeapify();
      minHeapify();
    }

    printf("%i\n", xHeap[1]);
  }
}
