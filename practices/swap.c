#include <stdio.h>

void swap(int a, int b) {
	printf("-------swap-----\n");
    int temp;
	temp = a;
    printf("temp : %d\n", temp);
	a = b;
    printf("a : %d\n", a);
	b = temp;
    printf("b : %d\n", b);
}

int main() {
	int value = 1, list[5] = {2, 4, 6, 8, 10};
	swap(value, list[0]);
    printf("value : %d\n", value);
    /* for (int i; i<5; i++){printf("%d", list[i]);}; */
	swap(list[0], list[1]);
	swap(value, list[value]);    
    printf("value : %d\n", value);

}
