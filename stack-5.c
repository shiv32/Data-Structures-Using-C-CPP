//stack-5
//convert infix to postfix expression using array

/******* operator precedence ****************
 
 (exprsn)       --> evaluate first
 ^              --> 1
 *,/,%          --> 2 (associativity left to right)
 +,-            --> 3 (associativity left to right)

*********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //system()

//define max size of stack
#define MAXSIZE 100

//declare the stack array and top variables in a structure
struct stack
{
char stack[MAXSIZE];
int Top;
};

typedef struct stack NODE;

//this fun will add/insert an element to Top of the stack
void push(NODE *pu,char item)
{

	//if the top pointer already reached the maximum allowd size then we can say that the stack is full or overflow
	if(pu->Top == MAXSIZE-1)
	{
	printf("\nthe stack is full");
	}
	else //otherwise an element can be added or inserted by incrementing the stack poniter Top as follows
	{
                   
	 	     pu->stack[++pu->Top]=item;
        }
}

//this fun will delete an element from the top of the stack
char pop(NODE *po)
{

 char item='#';
 
 //if the Top pointer points to NULL, then the stack is empty that is NO elemnet is there to delete or pop
 if(po->Top == -1)
 printf("\nthe stack is empty. Invalid infix expression");
 //otherwise the top most element in the stack is poped or deleted by decrementing the Top pointer
 else
 item=po->stack[po->Top--];

 return(item);
}

//this fun returns the prcedence of the operator
int prec(char symbol)
{   
     
    switch(symbol)
    {
	    case '(':
                     return(1);
	    case ')':
		     return(2);
	    case '+':
	    case '-':
		     return(3);
	    case '*':
	    case '/':
	    case '%':
		     return(4);
	    case '^':
		     return(5);
	    default:
		     return(0);
    }
}


//this fun will return the postfix expression of an infix
void Infix_Postfix(char infix[])
{

int len,priority;
char postfix[MAXSIZE],ch;

//declare an pointer variable to the structure
NODE *ps, pt;
      ps = &pt;

//initializing the Top pointer to NULL
ps->Top = -1;

//finding length of the string
len = strlen(infix);

//at the end of the string inputting a parenthesis ')'
infix[len++]=')';

push(ps,'('); //parenthesis is pushed to the stack

int i,j;

for(i=0,j=0;i<len;i++)
{
  switch(prec(infix[i]))
  {
	  //scanned char is '(' push to stack
          case 1:
	        push(ps,infix[i]);
	        break;
	  //scanned char is ')' pop the operator(s) and add to the postfix expression
          case 2:
	        ch = pop(ps);
		while(ch != '(')
		{
		postfix[j++]=ch;
		ch=pop(ps);
		}
		break;
		//scanned operator is +,- then pop the higher or same
		//precedence operator to add postfix before pushing
		//the scanned operator to the stack
	  case 3:
		ch=pop(ps);
		while(prec(ch) >= 3)
		{
		postfix[j++]=ch;
		ch=pop(ps);
		}
		push(ps,ch);
		push(ps,infix[i]);
		break;
		//scanned operator is *,/,% then pop the higher or
		//same precedence operator to add postfix before 
		//pushing the scanned operator to the stack
	  case 4:
		ch=pop(ps);
		while(prec(ch)>=4)
		{
		postfix[j++]=ch;
	        ch=pop(ps);		
		}
		push(ps,ch);
		push(ps,infix[i]);
		break;
		//scanned operator is ^ then pop the same 
		//precedence operator to add to postfix before pushing
		//the scanned operator to the stack
	  case 5:
	       ch=pop(ps);
               while(prec(ch)==5)
               {
               postfix[j++]=ch;
               ch=pop(ps);
               }
	       push(ps,ch);
	       push(ps,infix[i]);
	       break;
	       //scanned char is a operand simply add to the postfix
	       //expression
	  default:
	       postfix[j++]=infix[i]; //no operator in infix
	       break;
  }
}

              //printing the postfix notation to the screen
	      printf("\nPostfix expression is : ");
	      
	      for(i=0;i<j;i++)
              { 
		           if(postfix[i] != '\n')//ignore new line in print
			   printf("%c",postfix[i]);
	      }
              printf("\n\n***********************************\n");
}

//flush/clean the file or buffer
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

//main body
int main()
{
char choice,infix[MAXSIZE];

do
{
system("clear");//clear terminal

printf("\n*** Infix To Postfix Conversion ***\n");
printf("\nEnter the Infix expression : ");

fgets(infix, MAXSIZE, stdin); 

Infix_Postfix(infix);//calling the infix to postfix expression

printf("\n\nDo you want to continue(Y/y) = ");

scanf("%c",&choice);

clean_stdin();

}while(choice == 'Y' || choice == 'y');

system("clear");//clear terminal
}






