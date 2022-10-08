#include <stdio.h>

void ascii() {
	char c = 65, d = 66, e = 94, f=94;
	printf("%c %c %c %c", c,d,e,f);

	int x = 1234, y = 02322, z = 0x4D2;
	printf("%d\t%o\t%x\n", x, x, x);
	printf("%d\t%d\t%d\n", x, y, z);
}

int main(){
ascii();
}
