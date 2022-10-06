#include <stdio.h>

int main(){
    union flexType{
        int intEl;
        float floatEl;
    };

    union flexType el1;
    float x;

    el1.intEl = 287;
    x = el1.floatEl;

    printf("%i\n", el1.intEl );
    printf("%f\n", x);
}
