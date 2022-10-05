#include <stdio.h>
#include <ctype.h>

#define NWORDS 3

int process (int *p, int *nchars_ptr, int *nletters_ptr){
static int cnt = 0, last_char =''; 
if (isspace(last_char) && isspace(*p))
    return 0;

}

int main(){

}
