#include <stdio.h>
#define LENGTH_1 3
#define LENGTH_2 3 
int main(){
 /* 2D array declaration*/
   int disp[LENGTH_1][LENGTH_2];
   /*Counter variables for the loop*/
   int i, j;
   for(i=0; i<LENGTH_1; i++) {
      for(j=0;j<LENGTH_2; j++) {
         printf("Enter value for disp[%d][%d]:", i, j);
         scanf("%d", &disp[i][j]);
         printf("%d\n", disp[i][j]);
      }
   }
   //Displaying array elements
   printf("Two Dimensional array elements:\n");
   for(i=0; i<LENGTH_1; i++) {
      for(j=0;j<LENGTH_2;j++) {
         printf("%d ", disp[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }
   return 0;
}
