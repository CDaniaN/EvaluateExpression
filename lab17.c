/*
Dania Nasereddin
4-20-21
This progeram evaluates an expression from the command line,
only includes addition and subtraction.
*/
#include <stdio.h>
#include <string.h>

int atoi(char s[]) //converts string to int
{
  int i;
  int n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
  {
    n = 10 * n + (s[i] - '0');
  }
  return n;
}

int main(int argc, char *argv[])
{
  // checks to see if the expression is valid
  int invalidInput = 0;//if its 0 is valid, if its invalid its set to 1
  int operator; // 1 is + and 2 is -
  int answer = atoi(argv[1]); //answer of operation set to first number

  for(int i = 1; i < argc; i++)
  {
    //to be valid, the length must be even
    if(argc % 2 != 0) //if not even
    {
      invalidInput = 1; //set invalid to true
      break;
    }
    // checks if operators are at valid positions
    if(strcmp("+", argv[i]) == 0 || strcmp("-", argv[i]) == 0)
    {
      if(i % 2 == 0) //if its even
      {
        invalidInput = 0; //is valid
      }
      else
      {
        invalidInput = 1; //invalid
        break;
      }
    }
    else
    {
      if(i % 2 == 0)
      {
        invalidInput = 1; //invalid
        break;
      }
    }
  }

  if(invalidInput == 0)//if the expression is valid
  {
    for(int i = 2; i < argc; i++)
    {
      operator = 0;

      if(strcmp("+", argv[i]) == 0)
      {
        operator = 1; //set to addition
      }
      else if(strcmp("-", argv[i]) == 0)
      {
        operator = 2; //set to subtraction
      }

      if(operator != 0) //checks if there is an operator
      {
        switch(operator)
        {
          case 1: //addition
            answer += atoi(argv[i+1]);
            break;
          case 2: //subtraction
            answer -= atoi(argv[i+1]);
            break;
        }
      }
    }
    printf("The answer to this expression is %d\n", answer); //prints answer
  }
  else //not valid
  {
    printf("Invaild expression entered.\n"); //prints if invaild
  }

  return 0;
}
