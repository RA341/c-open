#include"char_STACK.h"

int type(char p)
{
    switch(p)
    {
        case '(':
        case ')':return 1;
        case '[':
        case ']':return 2;
        case '{':
        case '}':return 3;
    }
}

int main()
{
  char exp[50],x,y;
  printf("\n Input an expression with parenthesis");
  scanf("%s",exp);
  for( int i=0;exp[i];i++)
  {
       x=exp[i];
      switch(x)
      {
          case '{':
          case '[':
          case '(': push(x); 
                       printf("\n Parenthesis pushed");break;
          case ')':
          case ']':
          case '}': y=pop(); 
                       if(type(y)!=type(x)) 
                           {
               printf("\n Parenthesis match does not found");
                            return;
                          }
      }
  }
  if (isEmpty())
    printf("\n Parenthesis match found");
}
