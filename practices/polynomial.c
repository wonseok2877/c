#include <stdio.h>

#define MAX_DEGREE 101 // 다항식의 최대 차수 + 1
#define MAX(a,b) ( (a>b) ? a : b )

struct Poly{
int degree;
float coef[MAX_DEGREE];
};

/* typedef <type> <name> */
typedef struct Poly polynomial;

polynomial poly_add1(polynomial A, polynomial B){
polynomial C;
int Apos =0, Bpos=0, Cpos=0;
int degree_a = A.degree, degree_b = B.degree;
// MAX 
C.degree = MAX(A.degree, B.degree);


}
int main(){
polynomial mypoly = {5, {10,0,0,0,6,3}};

}

