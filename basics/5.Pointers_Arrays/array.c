#include <stdio.h>

 
/* any operation that can be achieved by array subscripting can also be done with pointers! */ 
int main(){

    /* defines an array a of size 10,
     * a block of 10 consecutive objects named a[0], ... , a[9] */
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("arr : %p\n", arr);
    // 배열을 선언한 순간, c언어에선 그 배열의 식별자가 곧 첫번째 element로의 address를 가리키는 pointer.
    // p + i : points i elements after p
    // p=arr 과 p=&arr[0]은 같다.
    int *p = arr;
    printf("p : %p\t *p: %i\n", p, *p);
    p=&arr[0];
    printf("p : %p\t *p: %i\n", p,*p);
    p=&arr[1];
    printf("p : %p\t *p: %i\n", p,*p);
    ++p;
    printf("p : %p\t *p: %i\n", p,*p);

    // copy the content of arr[2] to x
    int x= *p;
    printf("x:%i\n", x);
    
    p=arr;

    /* array indexing은 본질적으로 pointer arithmetic이다.
     * In evaluating arr[i], C converts in to *(a+i) immediately.
     * 
     * 마찬가지로 &arr[i] = (arr+i)
     *
     * pointer은 arr 식별자와 사실상 같다. 따라서 pointer을 통한 array indexing도 가능함.*/
    for (int i=0; i<10; i++){
        printf("arr[i] : %i \t *(arr+i) : %i\t p[i]:%i\t *(p+i) :%i\n", arr[i], *(arr+i), p[i], *(p+i));
        printf("&arr[i] : %p \t (arr+i) : %p \n", &arr[i], arr+i);
    }

    int list[] = {1,1,1,2};
    char name[]="freddie";
    char *a[]={"Bob", "Jake", "Darcie"};
   
    printf("%i\n", list[0] );
    printf("%s\n", name);
    for(int i=0;i<=2;i++){
      printf("%s\n",a[i]);
   };
}
