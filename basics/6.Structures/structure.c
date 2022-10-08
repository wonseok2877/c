#include <math.h>
#include <stdio.h>
#include <string.h>

// Structures (also called structs) are a way to group several related variables
// into one place. Each variable in the structure is known as a member of the
// structure.

// 그러면.. python의 dictionary와 같은건가?

// Unlike an array, a structure can contain many different data types.
// template 개념!

struct MyStructure { // MyStructure : tag(structure의 이름)
                     // 멤버를 선언할 때엔 메모리를 갖지 않는다. 변수가 선언될
                     // 때 메모리를 갖는다.
  int myNum;     // Member (int variable)
  char myLetter; // Member (char variable)
  char myString[30];
}; // End the structure with a semicolon

struct Car {
  char brand[50];
  char model[50];
  int year;
};

struct Point {
  int x;
  int y;
} p1 = {3, 4}, p2 = {1, 8}, p3 = {0, 20};

/* nested structure */
struct Rectangle {
  struct Point pt1;
  struct Point pt2;
};

/* make_point : make a Point data from x and y arguments */
struct Point make_point(int x,int y){
struct Point temp;
temp.x=x, temp.y=y;
return temp;
}

struct Point add_point (struct Point pt1,struct Point pt2){
pt1.x += pt2.x;
pt1.y += pt2.y;
return pt1;
}

/* ptinrec : return 1 if p in r, 0 if not 
 * pt1과 pt2 좌표가 작은 순서대로 있어야 작동ㅋㅋ */
int ptinrec(struct Point pt, struct Rectangle rec){
int is = pt.x >= rec.pt1.x && pt.x <= rec.pt2.x && pt.y >= rec.pt1.y && pt.y <= rec.pt2.y;
return is;
}

int main() {
  struct MyStructure s1 = {1, 'a', "Hello this is s1 structure."};

  // Dot(.) is a structure member operator.
  printf("%i %c %s \n", s1.myNum, s1.myLetter, s1.myString);

  struct MyStructure s2;
  s2.myNum = 2;
  s2.myLetter = 'b';

  char arr[10] = "Hello";

  strcpy(s2.myString, "Hello this is s2 structure.");
  printf("%i %c  %s \n", s2.myNum, s2.myLetter, s2.myString);

  struct Car car1 = {"BMW", "X5", 1999};
  struct Car car2 = {"Ford", "Mustang", 1969};
  struct Car car3 = {"Toyota", "Corolla", 2011};

  printf("%s %s %d\n", car1.brand, car1.model, car1.year);
  printf("%s %s %d\n", car2.brand, car2.model, car2.year);
  printf("%s %s %d\n", car3.brand, car3.model, car3.year);

  // Dot(.) has higher precednece then &
  printf("%p \n", &car1.year);

  printf("x=%i\t y=%i\n", p1.x, p1.y);
  // dist : 두 점 사이의 거리
  double dist1 = sqrt((double)p1.x * p1.x + (double)p1.y * p1.y);
  printf("distance=%lf\n", dist1);
  double dist2 = sqrt((double)p2.x * p2.x + (double)p2.y * p2.y);
  printf("distance=%lf\n", dist2);
  double dist3 = sqrt((double)p3.x * p3.x + (double)p3.y * p3.y);
  printf("distance=%lf\n", dist3);

  struct Rectangle r = {{5, 0}, {8, 8}};

  printf("(%i,%i) , (%i,%i) \n", r.pt1.x , r.pt1.y, r.pt2.x, r.pt2.y);

  /* copy a structure */
struct Rectangle copied = r;
  printf("(%i,%i) , (%i,%i) \n", copied.pt1.x , copied.pt1.y, copied.pt2.x, copied.pt2.y);

  /* structure can't be compared */
  /* printf("is they same ?... %i \n", r==copied); */

  struct Point p4 = make_point(0, 8);
    double dist4 = sqrt((double)p4.x * p4.x + (double)p4.y * p4.y);

  printf("distance=%lf\n", dist4);

  struct Rectangle s ;
  s.pt1 = make_point(1, 39);
  s.pt2 = make_point(4, 10);

    printf("(%i,%i) , (%i,%i) \n", s.pt1.x , s.pt1.y, s.pt2.x, s.pt2.y);

    struct Point result = add_point(p1, p2);
      printf("x=%i\t y=%i\n", result.x, result.y);

      printf("is in : %i\n", ptinrec( p4, r));

      struct Point * Pp = &result;
    
      /* member operator
       * . 연산자가 * 연산자보다 높기 때문에 ()를 써야 한다.
       * -> 연산자를 주로 쓴다.*/
      printf("Pp=%p\t Pp->x=%i\t Pp->y=%i\n", Pp, (*Pp).x, Pp->y);

      struct Rectangle *rp = &r;
        
      printf("%i %i %i %i\n", r.pt1.x, rp->pt1.x, (r.pt1).x, (rp->pt1).x);

  return 0;
}
