#include <stdio.h>

int x,y;

void func(int x, int y){
    x++, y++;
printf("%i %i \n", x, y);
}
int main(){
    x=0,y=0;
    func(x,y);
    printf("%i %i \n", x, y);

}
