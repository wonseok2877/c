#include <stdio.h>
#include <stdint.h>

int main() {
  /* 1. pointer declaration
   * * operator
   * every pointer have constraint to point to a specific data type. */
  int *ip;
  double *dp;
  float *fp;
  char *ch;

  int var = 20;
  /* 2. refer to address
   * & operator
   * store address (&) of var in a pointer variable (int type)*/
  ip = &var;
  /* pointer to a pointer (**) */
  int **pp = &ip;
  printf("Address of var variable: %p\n", &var);
  printf("=====Address stored in ip variable: %p\n", ip);

  /* * operator
   * : access the value using the pointer */
  printf("Value of *ip var. %d = %d\n", *ip, var);

  int x = 1, y = 2, z[10];

  /* pointer을 이용해 값을 바꾸면, 처음에 pointer된 단 하나의 memory cell에 담긴
   * 값만 바뀐다. 어찌보면 *ip는 x와 동일한 변수 역할을 하는 것. */
  ip = &x;
  printf("value ip pointing to : %i\t address ip pointing to : %p\n", *ip, ip);
  printf("*&ip : %p\t &x : %p\t**&p : %i\t x:%i\n", *&ip, &x, **&ip, x);
  y = *ip;
  printf("y is now %i \n", y);
  *ip = *ip + 10;
  printf("x is now %i, \t y is still %i\n", x, y);
  *ip *= *ip;
  printf("x is now %i, \t y is still %i\n", x, y);

  /* point nothing (nil)
   * 어떨때 쓰는거지? 메모리를 아낄 수 있는건가 */
  ip = NULL;
  printf("ip is pointing to : %p\n", ip);
  ip = 0;
  printf("ip is pointing to : %p\n", ip);

  ip = &z[0];
  printf("ip is pointing to : %p\n", ip);
  printf("z[0] : %i\n", z[0]);

  z[0] = 10;
  z[1] = 100;
  z[2] = 1000;
  printf("z[0] : %i\n", z[0]);

  /* pointer 연산자 우선순위 */
  printf("*ip : %i\t ip : %p\n", *ip, ip);
  // 1. Precedence of prefix ++ and * is same. Associativity of both is right to
  // left.
  // ++(*ip) 따라서 여전히 ip는 z[0]을 가리키고 그 값이 1 증가해서 11이다.
  ++*ip;
  printf("*ip : %i\t ip : %p\n", *ip, ip);

  // 2. Precedence of postfix ++ is higher than both * and prefix ++.
  // Associativity of postfix ++ is left to right. = *(ip++) 따라서 이제 ip는
  // z[1]을 가리키게 된다.
  *ip++;
  printf("*ip : %i\t ip : %p\n", *ip, ip);

  // 3. has two operators of same precedence, so compiler looks for
  // associativity. Associativity of operators is right to left. Therefore the
  // expression is treated as
  // *(++ip) 따라서 이제 ip는 z[2]을 가리키게 된다.
  *++ip;
  printf("*ip : %i\t ip : %p\n", *ip, ip);

  int i, j = 5, *p = &i, *q = &j, *r;
  i = 4;

  printf("%i %i\n", **&p, *(*(&p)));

  printf("%i %i\n", 7 * *p / *q + 7, ((7 * (*p)) / (*q)) + 7);

  printf("address of j : %p \t value of pointer r : %p \n", &j, r = &j);

  *(r = &i) *= *p;
  printf("value of pointer r : %p\t value of r pointing : %i \n", r, *r);

  int k = 11;
  i = k;

  *p = -1;
  printf("*p : %i\t i:%i\t k:%i \n", *p, i, k);

  /* memory address 직접 할당.. 그냥 기교인듯 */
  printf("p : %p\n", p);
  p = (int *)1;
  printf("p : %p\n", p);
  p = (int *)4;
  printf("p : %p\n", p);
  p = (int *)8;
  printf("p : %p\n", p);
  p = (int *)&k;
  printf("p : %p\n", p);

  /* 다른 type인 pointer끼리 할당하기.
   * void type pointer 을 매개로 해야 한다.
   * 근데 값이 짤려서 의미는 별로 없다. */
  void *v;
  double vaaar = 3.141592, *d = &vaaar;
  printf("p : %p\t d:%p\t v : %p\n", p, d, v);
  p = v = d;
  printf("p : %p\t d:%p\t v : %p\n", p, d, v);
  printf("*d : %f\t *p : %i\n", *d, *p);

  /* pointer 연산
   * */

  int a[] = {5,15,25,43,12,1,7,89,32,11};

  printf("a:%p\n", a);
  p = a + 2;
  q = p + 3;
  printf("p : %p\t *p: %i\t q:%p\t *q:%i\n", p, *p, q, *q);
  p += 6;
  printf("p : %p\t *p: %i\t q:%p\t *q:%i\n", p, *p, q, *q);

  p = &a[8];
  q = p - 3;
    printf("p : %p\t *p: %i\t q:%p\t *q:%i\n", p, *p, q, *q);

  p -= 6;
    printf("p : %p\t *p: %i\t q:%p\t *q:%i\n", p, *p, q, *q);

    p = &a[1], q=&a[5];

    printf("1. %i\n", *(p+3) );
        printf("2. %i\n", *(q-2));
    printf("3. %lu\n", q-p);
        printf("4. %i\n", p>q);
    printf("5. %i\n", *p>*q);


        printf("%lu \n",  (uintptr_t)q - (uintptr_t)p );


    printf("p : %p\t *p: %i\t q:%p\t *q:%i\n", p, *p, q, *q);
  printf("%lu\n", p-q);

    p =a+5, q=a+1;
        printf("p : %p\t *p: %i\t q:%p\t *q:%i\n", p, *p, q, *q);
  printf("p-q = %lu\n", p-q);

    double b[2], *e,*f;
    e=&b[0];
    f=e+1;

    printf("%lu\n", f-e);
    // https://stackoverflow.com/questions/26805461/why-do-i-get-cast-from-pointer-to-integer-of-different-size-error
    printf("%lu\n",  (uintptr_t)f - (uintptr_t)e );
    printf("%lu\n", sizeof(double));

    int c[3] = {20, 7,-9}, w;
    p = &c[1];
    w= *p++;
    printf("%d %d \n", w,*p);

      p = &c[1];
    w= *++p;
    printf("%d %d \n", w,*p);

      p = &c[1];
    w=++*p;
    printf("%d %d \n", w,*p);

      p = &c[1];
    w=(*p)++;
    printf("%d %d \n", w,*p);

    char mychar='a', *pc = &mychar;

    *pc='a';

    printf("%c \n", *pc);

  return 0;
}
