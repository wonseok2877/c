/** NOTE
 * You need to link with the math library:  gcc -o calculator calculator.c -lm */

#include <stdio.h>
#include <math.h>

int main()
{
  // two operands and result
  float valueOne, valueTwo, answer;
  // operator character
  char operator;

  printf("Enter calculation:\n\n");
  // scanf
  scanf("%f %c %f", &valueOne, &operator, &valueTwo);
  printf("valueOne: %f\t operator: %c\t valueTwo: %f\n", valueOne, operator, valueTwo);

  // switch : operator(정해진 ASCII char값)에 따라 분기처리.
  switch(operator)
    {
    case '/': answer = valueOne/valueTwo;
      break;
    case '*': answer = valueOne*valueTwo;
      break;
    case '+': answer = valueOne+valueTwo;
      break;
    case '-': answer = valueOne-valueTwo;
      break;
    case '^': answer = pow(valueOne,valueTwo);
      break;
    case ' ': answer = sqrt(valueTwo);
      break;
    default: goto fail;
    }
  printf("%.9g%c%.9g =  %.6g\n\n",valueOne,operator, valueTwo, answer);
  goto exit;
/**
 * label. goto명령어를 이용해서 특이하게 분기처리를 할 수 있다. 
 * 어떤 scope에 있던지간에 같은 함수에 있으면 가능한듯?*/
 fail:
  printf("Fail.\n");
 exit:
  return 0;
}
