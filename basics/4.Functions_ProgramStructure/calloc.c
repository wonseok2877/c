#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* calloc
 * calloc함수는 malloc함수와 같은 기능을 지니고 있다. 다만 사용하는 형태가 조금 다를 뿐이다
 * elt_size 크기의 변수를 elt_count 개 만큼 저장할 수 있는 메모리 공간을 할당하라는 의미
 * 값을 바꾸지 않는 malloc과 달리, calloc은 할당된 공간의 값을 모두 0으로 바꾼다.
배열을 할당하고 모두 0으로 초기화할 필요가 있을경우에는 calloc을 쓰면 편하다. */ 

int main() {
	int arr_1[5] = {1,2,3,4,5};	// 배열 선언
	int *arr_2, *arr_3;		// 포인터 변수 선언

    arr_2 = (int*) malloc(sizeof(int)*5);	// 메모리 할당, 배열의 크기만큼 할당하기 위해 5를 곱함
	arr_3 = (int*) calloc(5, sizeof(int));	// sizoe(int)크기의 변수를 5개 저장할 수 있는 공간할당

    printf("%lu %lu \n", sizeof(arr_2), sizeof(arr_3));

    for(int i = 0; i < 5; i++) {
        printf("%d \n", arr_2[i]); // 초기값은 모두 0
		arr_2[i] = arr_1[i]; // 각 element에 할당
		printf("%d \n", arr_2[i]);
	}

    free(arr_2);

	for(int i = 0; i < 5; i++) {
        printf("%d \n", arr_3[i]); // 초기값은 모두 0
		arr_3[i] = arr_1[i]; // 각 element에 할당
		printf("%d \n", arr_3[i]);
	}

	free(arr_3);	// free함수를 이용하여 메모리 해제


	return 0;
}
