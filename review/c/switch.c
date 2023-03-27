/* switch statements evaluate ONLY an integer or character;
it is significantly more efficient than if-else statement,
especially when the alternative would be a lot of nested
if-else's; however if-else statements can't always be
substituted with a switch statement*/


#include <stdio.h>


int main() {

  int a=1;

  switch(a) {
	case(1):
	  printf("a is 1\n");
	  break;
	case(2):
	  printf("a is 2\n");
	  break;
	default:
	  printf("a is not 1 or 2\n\n");
	  break;
  }


  char b='+';

  switch(b) {
	case('+'):
	  printf("%d\n", 2+1);
	  break;
	case('-'):
	  printf("%d\n", 2-1);
	  break;
	default:
	  printf("not a valid operator\n");
	  break;
  }

  return 0;
}
