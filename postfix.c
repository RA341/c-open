#include <stdio.h>
#include<ctype.h>

enum token {Lpar, Rpar, Operand, Operator};

int tokentype(char x)
{
    if (isalpha(x) || isdigit(x))
        return Operand;
    else
        if (x=='(')
            return Lpar;
        else
            if (x==')')
                return Rpar;
            else
                return Operator;
}

int pre(char x){
    switch(x){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case '(': return 0;
        case '#': return -1;
    }

}

void Infix_Postfix  (char infix[], char postfix[])
// Output the postfix form of the infix expression e.
 Also, ‘#’ is used at the bottom of the stack
{
	char s[50];
	char x,y;
	int j=0;
	Push('#');
	for (int i=0, x=infix[i]; x!='\0'; i++, x=infix[i])
	{

		switch(tokentype(x))
		{
		case Operand:
		    postfix[j++]=x; break;
		case Rpar:
		    // unstack until ‘(‘
            y = Pop();
            while (y!='('){
                postfix[j++]= y;
                y = Pop();
            }
            break;



 case Lpar:
            s.Push('(');
            break;
		case Operator:
		    y = Pop();
            while(pre(y) >= pre(x)){
                postfix[j++]= y;
                y = Pop();
            }
            Push(y); // re-stack the last y that was unstacked
            Push(x); //push the incoming operator
		}
	}
	 // end of expression; empty stack
	 y = Pop();
	 while (y != '#'){
        postfix[j++]= y;
        y = Pop();
    }
	postfix[j]='\0';
}





int main()
{
    char infix[100], postfix[100];
    printf("Enter an infix expression: “);
    scanf(“%s”,infix);
    Infix_Postfix(infix,postfix);
    printf(“%s”,postfix);

}

