//linked list-3
//Stack using linked list implemented using C program

#include <stdio.h>
#include <stdlib.h> //exit()
#include <string.h> //memset()

//node is created using structure
struct node
{
int info;
struct node *link; //link to the next node of type struct node
};

//NODE pointer variable is declared of type struct node
typedef struct node *NODE;

//funcion declaration
void display(NODE top);  //display stack element
void clean_stdin(void); //to clear the input buffer if user give wrong input type
NODE push(NODE top);   // insert element in stack
NODE pop(NODE top);   // delete element from stack
void BannerStart();  // for design 
void BannerEnd();   // for design

void main()
{
   system("clear");//clear terminal

   int choice;
   NODE Top = NULL; //stack is empty

   do
   {
   BannerStart();

   printf("\t\t\t\t\t\t                             1. PUSH\n");
   printf("\t\t\t\t\t\t                             2. POP\n");
   printf("\t\t\t\t\t\t                             3. EXIT\n");

   BannerEnd();

   display(Top); //display stack element

   printf("\n");

   printf("\t\t\t\t\t\t                        Enter your choice: ");
   memset(&choice, 0, sizeof(int)); //fill a block of memory with a particular value 
   scanf("%d",&choice);
   clean_stdin(); //flush/clean the file or buffer (if input is wrong eg. char, int etc.)

   system("clear");//clear terminal

   switch(choice)
   {
     case 1:
	     Top = push(Top);
	     system("clear");//clear terminal
	     break;
     case 2:
	     system("clear");//clear terminal
	     if(Top != NULL)
	     Top = pop(Top);
	     break;
     case 3:
	     system("clear");//clear terminal
	     exit(1);
     default:
	     system("clear");//clear terminal
	     printf("\n\t\t\t\t\t\t\t\t         ============");
	     printf("\n\t\t\t\t\t\t\t\t         Wrong Choice");
	     printf("\n\t\t\t\t\t\t\t\t         ============\n\n");

   }//end of switch
  
   }while(1);

   system("clear");//clear terminal
}

//push/insert element in stack fun
NODE push(NODE top)
{
 NODE NewNode;
 NODE temp = NULL;

 int pushed_item;

 display(top);

 //A new node is created dynamically
 NewNode = (NODE)malloc(sizeof(struct node));

 printf("\n\t\t\t\t\t\t\t\tPush the value in Stack: ");
 scanf("%d",&pushed_item);
 
 NewNode->info = pushed_item; //Data is pushed to the stack
 NewNode->link = NULL; //link pointer is set to the next node


if(top == NULL)//if stack is empty, first node
     top = NewNode;
else
{
  //Element inserted at the end
  temp=top;

  while(temp->link != NULL )
          temp=temp->link;

   temp->link=NewNode;
}

 return(top);
}//end of push

//pop/delete element from stack fun
NODE pop(NODE top)
{
    NODE tmp;
    NODE tmp2;
	    
    tmp = top; 

     if(tmp->link == NULL){ //stack has only one node	    
	     tmp2 = tmp;
             top  = NULL;
             free(tmp2);//free the memory of poped element
	     return(top);
     }else if (tmp->link != NULL && tmp->link->link == NULL){//stack has only two node
           tmp2 = tmp->link;
           tmp->link=NULL;
           free(tmp2);//free the memory of poped element
           return(top);
     }else{

      while(tmp->link != NULL && tmp->link->link != NULL){ //more than two node
          tmp=tmp->link;
	  tmp2 = tmp->link->link;
       }
          tmp->link=NULL;
	  free(tmp2);//free the memory of poped element
          return(top);
       }
}//end of pop

//display all element in the stack
void display(NODE top)
{
 printf("\n\t\t\t\t\t\t\t\t---------------------------------------\n\n");

 if(top == NULL){
	printf("\n\t\t\t\t\t\t\t\t          Stack is empty\n");
 }
 else
 {
    printf("\tStack: ");

    while(top != NULL)
    {
      printf("{%p} [%d : %p]",top,top->info,top->link);
     
      if(top->link != NULL)
      printf(" --> ");

       top = top->link;
    } //end of while
   
 } 
 printf("\n\n\t\t\t\t\t\t\t\t---------------------------------------\n");

}//end of display


//flush/clean the file or buffer (Use if input is wrong eg. char, int etc.)
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}


//start banner
void BannerStart()
{
 printf("\t\t\t\t\t\t================ Stack Using Linked List In C  ===========================\n\n");
}

//end Banner
void BannerEnd()
{
 printf("\t\t\t\t\t\t==========================================================================\n");
}

