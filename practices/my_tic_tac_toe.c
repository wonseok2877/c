#include <stdio.h>


// TODO : 프로그램 순서 정하기
// 배열에 플레이어들이 차례대로 숫자를 지정해 넣고, 먼저 1줄(당연히 대각선 포함)이 끝나면 이기는 게임. 
// 1. '*'로 채워진 char array를 만든다. 길이 9짜리. (1~9)
// 2. 하나 고른다. (터미널 getchar 입력)
// 2-1. 해당 순서의 array상의 element를 * 에서 o로 바꾼다. 상대편의 경우 x로 바꾼다.
// 2-2. 컴퓨터의 경우, 안 고른 숫자들중에서 1~9 random 생성. 그리고 array에 집어넣는다.
// 3. array상에서 1줄이 찰 때까지, 반복문상에서 2번을 계속 실행.
// 4. 찼을 때, 이긴 플레이어 WIN이라는 문구를 띄우고 게임을 끝낸다. 
// 4-1. 비긴 경우, DRAW라는 문구를 띄우고 게임을 끝낸다.
// 5. 다음 게임에 대한 제안. 1 - YES 2 - NO (getchar)에 따라 1번부터 다시 실행한다. (?)
int singleMode(){
char board[] = "*********";



// ? printf할걸 전제로 하고 board를 만들어야 하나, 아니면 board는 0~8까지의 index만을 다뤄야하나?
// 2차원 배열은 어떨까?
// ? 변수는 어떻게 만드는게 좋지? 각 플레이어가 선택한 index들을 따로 담고, array로 해야 하나?
// ? '1줄'이 됐다는 것은 어떻게 인식하지? 그래픽적으로 다가가선 안 될 듯하다.
}


int main() {

  int mode;
  printf("*************************************** \n");
  printf("*************TIC TAC TOE*************** \n");
  printf("*************************************** \n");
  printf("***********1. YOU vs COMPUTER ********* \n");
  printf("***********2. YOU vs PLAYER *********** \n");
  printf("***********3.EXIT ********************* \n");
  printf("\n \t Enter your choice : \n");

  // switch : char 1,2,3 의 ASCII 숫자 값에 따라
  switch (mode = getchar()) {
  // 1. single mode
  case 49:
      singleMode();
    printf("YOU vs COMPUTER \n");
    break;
    // 2. double mode
  case 50:
    printf("YOU vs PLAYER \n");
    break;
    // 3. exit
  case 51:
    printf("EXIT \n");
    break;
    // default : error
  default:
    printf("oops! error\n");
    return 1;
  }

  printf("switch ended.");

  return 0;
}


