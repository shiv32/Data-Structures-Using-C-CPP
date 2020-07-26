//stack-6
//infix to postfix expression using array in c++


/******* operator precedence ****************
 *  
 *  (exprsn)       --> evaluate first
 *  ^              --> 1
 *  *,/,%          --> 2 (associativity left to right)
 *  +,-            --> 3 (associativity left to right)
 *
 * *********************************************/

#include <iostream>
#include <string.h>
#include <stdlib.h> //system()

using namespace std;

//maximum size of the stack
#define MAXSIZE 100

//A class initialised with public and private variables and functions
class STACK_ARRAY
{
   int stack[MAXSIZE];
   int Top;

   public:
   //constructor is called and Top pointer is initialised to -1
   //when and object is created for the class
   STACK_ARRAY()
   {
    Top = -1; //empty stack
   }

   void push(char);
   char pop();
   int prec(char);
   void Infix_Postfix();
};

//This function will add/insert an element to Top of the stack
void STACK_ARRAY::push(char item)
{
    //if the top pointer already reached the maximum allows size then we can say that the stack is full or overflow
    if(Top == MAXSIZE-1)
    {
       cout<<"\nThe Stack is Full";
    }
    else//Otherwise an element can be added or inserted by incrementing the stack pointer Top as follows
    {
        stack[++Top]=item;
    }
}	

//This function will delete an element from the Top of the stack
char STACK_ARRAY::pop()
{
char item='#';

//if the Top pointer points to NULL, then the stack is empty
//that is NO element is there to delete or pop
if(Top == -1)
   cout<<"\nThe Stack is Empty OR Invalid Infix expression";
//Otherwise the top most element in the stack is poped or
//delete by decrementing the Top pointer
else
    item=stack[Top--];
return(item);
}

//this function returns the precedence of the operator
int STACK_ARRAY::prec(char symbol)
{
     switch(symbol)
     {
	     case '(':
		     return(1);
	     case ')':
		     return(2);
	     case'+':
	     case'-':
		     return(3);
	     case'*':
	     case'/':
	     case'%':
		     return(4);
	     case'^':
		     return(5);
             default:
		     return(0);
     }
}


//this fun will return the postfix expression of an infix
void STACK_ARRAY::Infix_Postfix()
{
int len,priority;
char infix[MAXSIZE],postfix[MAXSIZE],ch;

cout << "\n\nEnter the Infix expression : ";
cin >> infix; //inputting the infix notation

//finding length of the string
len = strlen(infix);

//at the end of the string inputting a parenthesis ')'
infix[len++] = ')';

push('('); //'(' pushed to stack

int i,j;

for(i=0,j=0;i<len;i++)
{
 switch(prec(infix[i]))
 {
   //scanner char is '(' push to the stack
    case 1:
	    push(infix[i]);
	    break;
  //scanned char is ')' pop the operator(s) and add to the postfix expression
    case 2:
	    ch=pop();
	    while(ch != '(')
	    {
	    postfix[j++]=ch;
	    ch=pop();
	    }
           break;
   //scanned operator is +,- then pop the higher or same precedence operator to add postfix before pushing the scanned operator to the stack
    case 3:
           ch=pop();
           while(prec(ch)>=3)
	   {
	   postfix[j++]=ch;
	   ch=pop();
	   }
           push(ch);
           push(infix[i]);
           break;	
	//scanned operator is *,/,% then pop the higher or same precedence operator to add postfix before pushing the scanned operator to the stack
    case 4:
         ch=pop();
         while(prec(ch)>=4)
	 {
	 postfix[j++]=ch;
	 ch=pop();
	 }
         push(ch);
         push(infix[i]);
         break;
      //scanned operator is ^ then pop the same precedence operator to add to postfix before pushing the scanned operator to the stack
    case 5:
         ch=pop();
         while(prec(ch)==5)
	 {
	 postfix[j++]=ch;
	 ch=pop();
	 }	
         push(ch);
         push(infix[i]);
         break;
      //scanned char is a operand simply add to the postfix expression
    default:
	 postfix[j++]=infix[i]; //no operator
	 break;

 }
}
     //printing the postfix notation to the screen
     cout<<"\nThe Postfix expression is : ";
     
     for(i=0;i<j;i++){	     
	     if(postfix[i] != '\n')//ignore new line in print
             cout<<postfix[i];
     }
     cout <<"\n";
}

int main()
{
  char choice;
  STACK_ARRAY infx_postfx; //stack object

  do
  {
  system("clear"); //clear terminal

  cout<<"\n======= Infix to Postfix in C++ ==================\n";
  
  infx_postfx.Infix_Postfix();//calling the infix to postfix function
  
  cout<<"\n==================================================\n";
  
  cout << "\n\nDo you want to continue (Y/y) = ";
  
  cin >> choice;
  
  }while(choice == 'Y' || choice == 'y');

  system("clear"); //clear terminal

  return 0;
}




