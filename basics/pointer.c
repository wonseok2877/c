#include <stdio.h>

int main() {
  /* pointer declaration
   * * operator
   * every pointer have constraint to point to a specific data type. */
  int *ip;
  double *dp;
  float *fp;
  char *ch;

  int var = 20;
  /* & operator
   * store address (&) of var in a pointer variable (int type)*/
  ip = &var; 
  /* pointer to a pointer (**) */
  int **pp = &ip; 
  /* address stored in a pointer*/
  printf("Address of var variable: %p\n", &var);
  printf("=====Address stored in ip variable: %p\n", ip);

  /* * operator 
   * : access the value using the pointer */
  printf("Value of *ip var. %d = %d\n", *ip, var);

  int x = 1, y = 2, z[10];

  /* pointer을 이용해 값을 바꾸면, 처음에 pointer된 단 하나의 memory cell에 담긴
   * 값만 바뀐다. 어찌보면 *ip는 x와 동일한 변수 역할을 하는 것. */
  ip = &x;
  printf("value that ip pointing to : %i\t address that ip pointing to : %p\n",
         *ip, ip);
  y = *ip;
  printf("y is now %i \n", y);
  *ip = *ip + 10;
  printf("x is now %i, \t y is still %i\n", x, y);
  *ip *= *ip;
  printf("x is now %i, \t y is still %i\n", x, y);

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

  return 0;
}
