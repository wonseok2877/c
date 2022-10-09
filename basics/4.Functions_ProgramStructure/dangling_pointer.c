#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){


    char *c="ccc";
    char *p =  malloc(4 );
        printf("p=%p\t *p=%c\n", p,*p);

    free(p);

    /* dangling pointer 
     * free로 할당 해제한 memory block은 deallocate만 됐을 뿐이다.
     * 실제로 point하던 memory block은 유효하게 된다. */
    p = c;

    printf("p=%p\t p=%s\t *p=%c\n", p,p,*p);

    strcpy(p, "abc");

    printf("p=%p\t *p=%c\n", p,*p);

    /* free
     * malloc, calloc, realloc에 의해 동적 할당된 메모리공간 (포인터)만을 인자로 가질 수 있음
     * 이미 해제된 메모리 공간을 다시 free 할 수 없음 */
    
    /* int *p = arr_3; */
    /* free(p); */

        char *q =  malloc(sizeof(char)*4 ); 

        /* garbage 
         * calloc, malloc으로 할당한 memeory block을 free하지 않고 종료하면, 
         * 다음부터는 해당 memeory에는 접근 불가능.*/

}
