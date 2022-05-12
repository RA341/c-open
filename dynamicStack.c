// integer stack
#include<stdio.h>
 int n=5;

 int *STACK;
 int top;

 int isEmpty()
 {
         if(top==-1)
            return 1;
        return 0;
 }

 int isFull()
 {
         if(top==n-1)
            return 1;
        return 0;
 }


 void push(int ele)
{
    if(isFull())
    {   n=2*n;
        STACK=(int *)realloc( STACK, n);
    }
    top++;//s.top=s.top+1;
    STACK[top]=ele; // s.a[++(s.top)]=ele;
}

void pop()
{
         if(isEmpty())
    {
        printf("\n Stack is Empty");
        return;
    }
    printf("\n%d",STACK[top]);
    top--;
}

int main( )
{

    top=-1; // empty stack
    STACK=(int *)malloc(n* sizeof(int));
    pop();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60); // reallocation of memory will take place

    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           