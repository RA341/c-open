                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          // integer stack
#include<stdio.h>

struct STACK
{
 int a[5];
 int top;
};

struct STACK s; // variable of type stack has to be global
void push(int ele);
void pop();
int main( )
{
    s.top=-1; // empty stack
    push(10);
    push(100);
    push(105);
    push(120);
    push(110);
    pop();
    pop();
    pop();
    push(20);
    push(30);
    push(40);
    pop();
    pop();
    pop();
    pop();
    pop();

}

void push(int ele)
{
    s.top++;//s.top=s.top+1;
    s.a[s.top]=ele; // s.a[++(s.top)]=ele;
}

void pop()
{
    printf("\n%d",s.a[s.top]);
    s.top--;
}
