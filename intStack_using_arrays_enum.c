                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           // integer stack
#include<stdio.h>
# define n 5

typedef enum  {FALSE, TRUE} BOOL;
//enum bool a;
BOOL a;

 int STACK[n];
 int top;

void push(int ele);
void pop();
BOOL isFull();
BOOL isEmpty();
int main( )
{
    top=-1; // empty stack
    pop();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

}

BOOL isFull()
{
      if(top==n-1) // return top==n-1? 1:0;
        {
            printf("\n Stack is FULL");
            return TRUE;
        }

        return FALSE;

}
void push(int ele)
{
    if(isFull())
        return;

    top++;//s.top=s.top+1;
    STACK[top]=ele; // s.a[++(s.top)]=ele;
}

BOOL isEmpty()
{
    if(top==-1)
    {
        printf("\n Stack is Empty");
        return TRUE;
    }

    return FALSE;
}
void pop()
{
    if(isEmpty())
        return;

    printf("\n%d",STACK[top]);
    top--;
}
                                                                                                                                                                                                                                                                                                                                                                                            