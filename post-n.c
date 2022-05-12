#define MAX_STACK_SIZE 100 /* maximum stack size */ #define MAX_EXPR_SIZE 100 /* max size of expression */ typedef enum{lparan, rparen, plus, minus, times, divide, mod, eos, operand} precedence;
int stack[MAX_STACK_SIZE]; /* global stack */ char expr[MAX_EXPR_SIZE]; /* input string */

int main(){
char exp[20];
    int result;

    printf("Enter an postfix expression: “);
    scanf(“%s”,exp);

    for(int i=0;exp[i];i++)
    {
        if (isdigit(exp[i]))
            push(exp[i]-'0');
 else
        {
            int op2=pop();
            int op1=pop();
            switch(exp[i])
            {

                case '+': result = op1+op2;break;
                case '-':result = op1-op2;break;
                case '*':result = op1*op2;break;
                case '/':result = op1/op2;break;

            }
            push(result);
        }
    }
    printf(“The result=“);
   pop();


}

int postfixeval(void)
{
precedence token; char symbol;
int op1, op2;
int n = 0;	/* counter for the expression string */ int top = -1;
token = get_token(&symbol, &n); while (token != eos)	{
if (token == operand) push(&top, symbol-’0’);

else {
/* remove two operands, perform operation, and return result to the stack */

op2 = pop(&top);	/* stack delete */ op1 = pop(&top);
switch(token) {
case plus: push(&top, op1+op2); break; case minus: push(&top, op1-op2); break; case times: push(&top, op1*op2); break; case divide: push(&top, op1/op2); break; case mod: push(&top, op1%op2);
}
}
token = get_token (&symbol, &n);
}
return pop(&top); /* return result */
}

precedence get_token(char *symbol, int *n)
{
  
*symbol =expr[(*n)++]; switch (*symbol)	{
case ‘(‘ : return lparen; case ’)’ : return rparen; case ‘+’: return plus; case ‘-’ : return minus;

case ‘/’ :	return divide; case ‘*’ : return times; case ‘%’ : return mod; case ‘\0‘ : return eos; default	: return operand;
/* no error checking, default is operand */
}
}


