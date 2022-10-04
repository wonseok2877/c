#include <stdio.h>
#include <string.h>

// Structures (also called structs) are a way to group several related variables into one place. Each variable in the structure is known as a member of the structure.

// 그러면.. python의 dictionary와 같은건가?

// Unlike an array, a structure can contain many different data types. 
// template 개념!

struct MyStructure { // MyStructure : tag(structure의 이름)
                     // 멤버를 선언할 때엔 메모리를 갖지 않는다. 변수가 선언될 때 메모리를 갖는다.
  int myNum;         // Member (int variable)
  char myLetter;     // Member (char variable)
  char myString[30];
};                   // End the structure with a semicolon

struct Car {
  char brand[50];
  char model[50];
  int year;
};
                     
int main() {
  struct MyStructure s1 = {1, 'a', "Hello this is s1 structure."};

  // Dot(.) is a structure member operator.
  printf("%i %c %s \n", s1.myNum, s1.myLetter, s1.myString);

  struct MyStructure s2;
  s2.myNum = 2;
  s2.myLetter = 'b';

  char arr[10] = "Hello";

  strcpy(s2.myString,"Hello this is s2 structure." );
  printf("%i %c  %s \n", s2.myNum, s2.myLetter, s2.myString);

  struct Car car1 = {"BMW", "X5", 1999};
  struct Car car2 = {"Ford", "Mustang", 1969};
  struct Car car3 = {"Toyota", "Corolla", 2011};

  printf("%s %s %d\n", car1.brand, car1.model, car1.year);
  printf("%s %s %d\n", car2.brand, car2.model, car2.year);
  printf("%s %s %d\n", car3.brand, car3.model, car3.year);

  // Dot(.) has higher precednece then &
  printf("%p \n", &car1.year);
  return 0;
}
