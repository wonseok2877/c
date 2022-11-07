/* front.c – 단순 산술식에 대한 lexical analyzer */

// include headers
#include <stdio.h>
#include <ctype.h>

/* 전역 변수 */
// character class. 여기선  LETTER, DIGIT, UNKNOWN
int charClass;
// lexeme : lexeme이 담기는 string array
// nextChar : 
char lexeme[100], nextChar;
// lexLen : lexeme의 길이
int lexLen, nextToken;
FILE *in_fp, *fopen();

/* 함수 선언 */
void addChar(), getChar(), getNonBlank();
void expr(), term(), factor();
int lex();

/* token codes of character classes */
#define LETTER 0 // character class for 52 characters
#define DIGIT 1 // character class for 10 digits
#define UNKNOWN 99 // class for unknown characters

/* token codes of single-characters */
// predefined EOF : End Of File
#define INT_LIT 10
#define IDENT 11
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

/* 1. main 구동기 */
int main() {
    /* 1-1. 조건문. 파일 열어보고 NULL이면 printf 외에 실행 안함.
     * fopen : 입력 데이터 파일을 열고 그 내용을 처리. 여기는 readonly.
     * in_fp : input contents */
    if (( in_fp = fopen("lexical3.in", "r")) == NULL){
        printf("ERROR – cannot open front.in \n");
    } else {
        // 1-2. getChar 호출
        getChar();        
        // 1-3. nextToken값이 EOF가 될때까지 계속 lex 호출
        do {
            lex();
            // expr : recursive-descent parser 시작
            expr();
        } while (nextToken != EOF);
    }
}

/* 6. lookup
 * 연산자와 괄호를 조사하여 해당 토큰을 반환
 * compute the token code for the single-character tokens.
 * ch : 인자값. switch문에 쓸 용도로.
 * case마다 들어있는 문자열은 table of reserved words라고 할 수 있음. */
void lookup(char ch) {
    // switch & case : addChar호출한 뒤, nextToken에다 각 case에 따른 토큰(괄호 혹은 연산자)의 token code 할당
    switch (ch) {
        case '(' : addChar(); nextToken = LEFT_PAREN; break;
        case ')' : addChar(); nextToken = RIGHT_PAREN; break;
        case '+' : addChar(); nextToken = ADD_OP; break;
        case '-' : addChar(); nextToken = SUB_OP; break;
        case '*' : addChar(); nextToken = MULT_OP; break;
        case '/' : addChar(); nextToken = DIV_OP; break;
        default : addChar(); nextToken = EOF; break;
    }

    if (nextToken == EOF) printf("=======EOF=======\n");
}

/* 4. addChar : nextChar의 문자열을 lexeme에 추가하는 함수 */
void addChar() {
    // lexLen 길이가 98보다 작은 경우, lexeme 맨뒤에 nextChar 할당. 
    if (lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
        /* printf("lexeme after addChar : %s\n", lexeme); */
    }
    else printf("Error - lexeme is too long \n");
}

/* 5. getChar 
 * 다음 입력 문자를 읽어 그 문자의 유형(class)을 결정하는 함수
 * gets the next character of input from the input program
 * puts it in the global variale nextChar
 * determine the character class of the input character*/
void getChar() {
    /* getc : gets the next character (an unsigned char) from the specified stream and advances the position indicator for the stream. */
    // nextChar에다 getc의 결과값, 즉 input의 다음 문자열을 할당.
    if ((nextChar = getc(in_fp)) != EOF) {
        /* isalpha : checks whether a character is an alphabet (a to z and A-Z) or not. */
        // nextChar이 알파벳일 경우, charClass에 LETTER 할당
        if (isalpha(nextChar)){
            charClass = LETTER;
            /* printf("charClass : LETTER \n"); */
        }         
        /* isdigit : checks whether a character is numeric character (0-9) or not. */
        // nextChar이 digit일 경우, charClass에 DIGIT 할당
        else if (isdigit(nextChar)){
            charClass = DIGIT; 
            /* printf("charClass : DIGIT \n"); */
        } // nextChar이 예측되지 않은 string일 경우, charClass에 UNKNOWN 할당
        else {
            charClass = UNKNOWN; 
            /* printf("charClass : UNKNOWN \n"); */
        }    
    }
    // 다음 문자열이 없을 경우 charClass에 EOF 할당
    else charClass = EOF;
}

/* 3. getNonBlank
 * 공백 문자가 아닐 때까지 getChar를 호출 */
void getNonBlank() {
    /* isspace : checks whether a character is a white-space character or not. */
    // nextChar이 공백인 경우, getChar 반복 호출
    while (isspace(nextChar)) getChar();
}

/* 2. lex
 * a simple lexical analyzer */
int lex() {
    // 2-1. lexLen값 0으로 할당
    lexLen = 0; 
    // 2-2. getNonBlank 호출
    getNonBlank();
    // 2-3. switch문. charClass의 case에 따라 
    switch(charClass) {
    /* LETTER case : charClass가 LETTER 혹은 DIGIT인 동안 addChar과 getChar 반복
     * 그 후 nextToken에 식별자라는 뜻인 IDENT의 token code 할당 */
    case LETTER : addChar(); getChar();
        while(charClass == LETTER || charClass == DIGIT) {
            addChar(); getChar();
        }
        nextToken = IDENT;
        break;
    /* DIGIT case : charClass가 DIGIT인 동안, addChar과 getChar 반복
     * 그 후 nextToken에 정수리터럴이라는 뜻인 INT_LIT의 token code 할당 */
    case DIGIT : addChar(); getChar();
        while(charClass == DIGIT) { addChar(); getChar(); }
        nextToken=INT_LIT;
        break;
    /* UNKNOWN case : 괄호, 연산자에 대해 lookup 호출
     * (lookup 안에서 해당 문자열에 대한 addChar 실행되고, nextChar에 해당 token code 할당). 
     * 그 후 getChar 호출.  */
    case UNKNOWN: lookup(nextChar); getChar(); break;
    /* EOF case : 걍 파일 끝났다는거 전달 */
    case EOF : nextToken = EOF; lexeme[0]='E'; lexeme[1]='O'; lexeme[2]='F';
        lexeme[3]=0; break;
    } 
    /* End of switch */
    printf("========= token code is %d, lexeme is %s =========\n", nextToken, lexeme);
    return nextToken;
} /* End of function lex */

/* ------------Recursive-Descent Parsing Process(프로그래밍 언어론 199p.)----------- */

/* Function factor : <factor> -> id | int_constant | (<expr>) */
void factor(){
    printf("Enter <factor> \n");
    if(nextToken==IDENT || nextToken == INT_LIT)
        lex();
    else {
        if(nextToken==LEFT_PAREN){
            lex();
            expr();
            if(nextToken==RIGHT_PAREN) lex();
            else printf("error!");
        }
        /* id, 정수 리터럴, 왼쪽 괄호가 아니면 */
        else printf("error!");
    }
    printf("Exit <factor> \n");
}

/* Function term : <term> -> <factor> {(*|/)<factor>} */
void term() {
    printf("Enter <term> \n");
    factor();
    while(nextToken==MULT_OP || nextToken==DIV_OP){
        lex() ; /* get the next token from the input */
        factor();
    }
    printf("Exit <term> \n");
}

/* Function expr :<expr> -> <term> {(+|-)<term>} */
void expr(){
    printf("Enter <expr> \n");
    term(); /* parse the first term */
    /* As long as the next token is + or -, call lex to get the next token, and parse
    the next term */
    while(nextToken==ADD_OP || nextToken==SUB_OP){
        lex() ; /* get the next token from the input */
        term();
    }
    printf("Exit <expr> \n");
}
