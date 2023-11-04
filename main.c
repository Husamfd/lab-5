#include<stdio.h>
#define STACK_SIZE 20
typedef struct{
    int data[STACK_SIZE];
    int top;
}stack;

void initialize(stack * stk){
    stk->top=-1;
}

void push( stack * stk,int c){
    if(stk->top!= STACK_SIZE-1){
        stk->top++;
        stk->data[stk->top]=c;
}
    else
        printf("\nStack is Full!!");
}

int pop (stack * stk){
    if(stk->top!=-1){
return stk->data[stk->top--];
}
    printf("\n Stack is Empty!!");
return 0;
}


int main(){
char exp[20];
char *e;
stack s;
initialize(&s);
int n1,n2,n3,num;
    printf("Postfix Enter expression: ");
    scanf("%s",exp);
    e = exp;
while(*e != '\0'){
    if(isdigit(*e)){
        num = *e - 48; //tam say�ya �evirme
        push(&s,num);
}   else{
        n1 = pop(&s);
        n2 = pop(&s);
    switch(*e){
    case '+':
        n3 = n2 + n1;
    break;
    case '-':
        n3 = n2 - n1;
    break;
    case '*':
        n3 = n2 * n1;
    break;
    case '/':
        n3 = n2 / n1;
    break;
}

push(&s,n3);
}
e++;
}
printf("\nSonuc = %d\n",pop(&s));
}
