//stack-1
//stack using array

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<stdbool.h>

#define MAXSIZE 100

struct stack
{
int stack[MAXSIZE];
int Top;
};

typedef struct stack NODE;

void push(NODE *pu)
{
int item;

if(pu->Top == MAXSIZE-1)
{
printf("\nStack is full");
}else{

printf("\nEnter the element to be inserted:");
scanf("%d",&item);
pu->stack[++pu->Top] = item;
}

}

void pop(NODE *po)
{
int item;

if(po->Top == -1)
{
printf("\n Stack is empty !");
}else
{
item = po->stack[po->Top--];
printf("\nThe deleted element is = %d",item);
}
}

void traverse(NODE *pt)
{
int i;

if(pt->Top == -1)
{
printf("\n Stack is empty !");
}else
{
	printf("\nthe element in the stack is/are:");
	for(i=pt->Top; i>=0;i--)
        printf("\n%d",pt->stack[i]);
}

}



int main()
{
int choice;

NODE *ps;

ps->Top = -1;

bool cond = true;

while(cond)
{

printf("\n======================\n");

//menu
printf("\n1.PUSH");
printf("\n2.POP");
printf("\n3.TRAVERSE");
printf("\n4.QUIT");
printf("\n-------------------------\n");

printf("\nENTER YOUR CHOICE:");
scanf("%d",&choice);
printf("\n-------------------------\n");

switch(choice)
{

	case 1:
        push(ps);
        break;

	case 2:
        pop(ps);
        break;

	case 3:
        traverse(ps);
        break;

        case 4:
        printf("\nSuccessfully Quit !");
	cond = false;
	//raise(SIGKILL);
        break;

	default:
	printf("\nYou have entered wrong choice !");
}
}
return 0;
}





