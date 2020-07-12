//stack-7
//Evaluate postfix expression using stack (array)
//result will be in float

//for compile
//gcc my_program.c -o my_program -lm


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//define max size of stack
#define MAXSIZE 100

//declaring the stack array and top variables in a structure
struct stack
{
float stack[MAXSIZE];
int Top;
};

//type definition is used to define an identifier that would represent an existing data type
typedef struct stack NODE;

//this function will add/insert an element to Top of the stack
void push(NODE *pu,float item)
{
//if the top pointer already reached the maximum allowed size then we can say that the stack is full or overflow
if(pu->Top == MAXSIZE-1)
{
printf("\nThe Stack is Full");
}
else //Otherwise an element can be added or inserted by incrementing the  stack pointer Top as follows
{
pu->stack[++pu->Top] = item;
}
}

//this function will delete an element from the Top of the stack
float pop(NODE *po)
{
float item;

//if the Top pointer points to NULL, then the stack is empty that is NO element is there to delete or pop 
if(po->Top == -1)
{
printf("\nThe Stack is empty");
}
else //otherwise the top most element in the stack is poped or deleted by decrementing the Top pointer
{
item = po->stack[po->Top--];
}
return(item);
}

//this function will evaluate the postfix expression
float Postfix_Eval(char postfix[])
{
float a,b,temp;
int len;

//declaring pointer variable and simple variable to the structure
NODE *ps, pt;
ps = &pt;

//Initializing the Top pointer to NULL
ps->Top = -1;

//finding length of the string
len = strlen(postfix);

int i;

for(i=0;i<len;i++)
{

   //for operand
   if(postfix[i]<='9' && postfix[i]>='0')//operand is pushed on the stack
     {
      push(ps,(postfix[i]-48)); //postfix[i] is in ascii value 48,49,50 etc.
     }
     else//for operator
     {
         //pop the top most two operand for operation
	 a = pop(ps);
         b = pop(ps);

	 switch(postfix[i])
	 {
	  case '+':
		  temp = b+a;
		  break;
          case '-':
                  temp = b-a;
                  break;
          case '*':
                   temp = b*a;
                   break;
          case '/':
                   temp = b/a;
                   break;
          case '%':
		   temp = fmodf(b,a); //floating-point remainder function (%)
                   break;
          case '^':
                   temp = pow(b,a); //pow function 
		   break;
	 }
            push(ps,temp);

     }

}
  return(pop(ps));

}

//flush/clean the file or buffer
void clean_stdin(void)
{
    int c;
    do {
        c = getchar(); // gets a character (an unsigned char) from stdin
    } while (c != '\n' && c != EOF); //EOF indicates "end of file"
}


int main()
{
char choice,postfix[MAXSIZE];

do
{
    system("clear");//clear terminal
  
    printf("\n=== Postfix Evaluation ===\n");

    printf("\n\nEnter the Postfix expression : ");
 
    fgets(postfix, MAXSIZE, stdin);

    printf("\n\nThe postfix evaluation is : %f",Postfix_Eval(postfix));
    printf("\n==========================\n");
    printf("\n\nDo you want to continue (Y/y) : ");
 
    scanf("%c",&choice);

    clean_stdin(); //clean stdin buffer

}while(choice == 'Y' || choice == 'y');

system("clear");//clear terminal

return 0;
}
