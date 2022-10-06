#include<stdio.h>
 // We can assign values to some name in any order. All unassigned names get value as value of previous name plus one. 
enum year{Jan =1, Feb, Mar, Apr, May, Jun, Jul, 
          Aug, Sep, Oct, Nov, Dec};

enum boolean {NO, YES};
  
int main()
{
    enum year month;
    month = Apr;
    printf("number of April = %d\n", month);

   int i;
   for (i=Jan; i<=Dec; i++)      
      printf("%d ", i);
    
   enum colors {red, blue, green, yellow, black};

   enum colors myColor = red;
   enum colors yourColor = blue;

   myColor ++;
   yourColor = 4;

   printf("\n myColor = %d\n", myColor);
   printf("yourColor = %d\n", yourColor);
        
   return 0;
}
