//Linked List-1
//Singly Linked List using C programming
//All the nodes are arranged sequentially by linking with a pointer. 

#include<stdio.h>
#include<stdlib.h>

//function declaration
void Display(); //display Singly Linked List elements

//structute declaration for the node, node-> [info:next_node_address]
struct node
{
     int info; //store data/element
     struct node *link; //store address of next node
}*start;

//check Singly Linked List Empty
int CheckEmptyList(struct node *start)
{
        if(start == NULL)//Singly linked list empty
           {
                 printf("\n\n\t\t\t\tLinked List is empty\n");
                 return -1;
           }

          return 0;
}

//check duplicate data in Singly Linked List
int checkReaptedData(int data)
{
  struct node *q=start;
  int pos = 0;

  while(q!=NULL)
  {
	 if(q->info == data){
          printf("\n\t\t\t\t%d already availabe in Linked List at position %d\n",data,pos);
	  Display();
	  return 1;
	 }else{
            q=q->link;
	    pos++;
	 }
  }
  return 0;
}

//create a new Singly linked list
void Create_List(int data)
{
struct node *q, *tmp;

//dynamic memory has been allocated for a node
tmp = (struct node*)malloc(sizeof(struct node));
tmp->info=data;
tmp->link=NULL;

if(start == NULL)//if list is empty, first node
     start = tmp;
else
{
  //Element inserted at the end
  q=start;
 
  while(q->link != NULL )
          q=q->link;
 
  q->link=tmp;
}
system("clear"); //clear terminal
Display();
}

//add new element at the beginning of the Singly linked list
void AddAtBegin(int data)
{
	struct node *tmp;

	//create node
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	
	tmp->link=start;  //assign address, tmp link will point to whom start was pointing
	start=tmp;        //tmp is first node
	
	Display();
}

//add new element at any position
void AddAfter(int data,int pos)
{
struct node *tmp,*q=start; 
int i;

//find the position to add new element to the linked list
for(i=0;i<pos;i++)
{
q=q->link; //next node address
if(q==NULL)
{
printf("\n\n\t\t\t\tThere are no node at postion %d in Linked List\n",pos);
return;
}
}
//create node
tmp=(struct node*)malloc(sizeof(struct node));
tmp->info=data;

tmp->link=q->link;//assing address
q->link=tmp;

Display();
}

//delete element from Singly linked list
void Del(int data)
{
    int delFlag = 0; //for deleted element, 0->not found; 1->deleted
    struct node *tmp,*q;

   if(start->info == data) //check first element
    {
      delFlag = 1;
      
      tmp=start;
      start=start->link;//first element deleted

      free(tmp);//free memory of deleted node 
      
      Display();
      
      return;
    }
     q=start;

 while(q->link != NULL && q->link->link != NULL) //more than one element
  {
     if(q->link != NULL && q->link->info == data)//element deleted in b/w
     {
     delFlag = 1;	     
     
     tmp = q->link;         //2nd node
     q->link = tmp->link;   //3rd node
     
     free(tmp);//free memory of deleted node 
     
     Display();
     
     return;
     }
      q=q->link; 
  }

  if(q->link != NULL && q->link->info == data) //last element deleted
  {
  delFlag = 1;
  
  tmp = q->link;
  
  free(tmp);//free memory of deleted node 
  
  q->link = NULL; //to avoid dangling pointer
  
  Display();
  
  return;
  }

  if(!delFlag)//element not found
     printf("\n\n\t\t\t\tElement %d is not found in Linked List\n",data);

  Display();
}

//display all elements in the Singly linked list
void Display()
{
 struct node *q;

 //Singly linked list empty
 if(CheckEmptyList(start) == -1)
   return;

 q=start;

 printf("\n\t\t\t==================== Singly Linked List ================================\n\n");
 
 while(q!=NULL)
 {
 printf("{%p} [ %d : %p]",q,q->info,q->link); //{node addr} [data : next node addr]

 q=q->link;

 if(q!=NULL)
 printf(" -> ");

 } 
 printf("\n");
 printf("\n\t\t\t========================================================================\n");
}

//count the no. of nodes in the Singly linked list
void Count()
{
  struct node *q=start;

  int cnt=0;
  
  while(q!=NULL)
  {
   q=q->link;
   cnt++;
  }
  
  printf("\n\t\t\t\tNumber of nodes in Linked List  is/are : %d\n",cnt);

  Display();
}

//reverse the Singly linked list
void Rev()
{
  struct node *p1,*p2,*p3;

  //Singly linked list empty
  if(CheckEmptyList(start) == -1)
       return;

  if(start->link == NULL){//only one element
   Display();
   return;
  }

  p1 = start;
  p2 = p1->link;
  p3 = p2->link;
  p1->link = NULL;
  p2->link = p1;
  
  while(p3!=NULL)
  {
    p1 = p2;
    p2 = p3;
    p3 = p3->link;
    p2->link = p1;
  } 
  
  start=p2;

  Display();
}

//search an element in the Singly linked list
void Search(int data)
{
 struct node *ptr = start;
 int pos = 0;

 //searching for an element in the Singly linked list
 while(ptr != NULL)
 {
    if(ptr->info==data)
    {
     printf("\n\n\t\t\t\tElement %d found at position %d\n",data,pos);
     Display();
     return;
    }
    ptr = ptr->link;
    pos++;
 }

 if(ptr == NULL)//element not found
    printf("\n\n\t\t\t\tElement %d is not found in Linked List\n",data);
    
    Display();
}

//main method
void main()
{
int choice,n,m,position,i;
start = NULL; //Singly Link List is empty

system("clear"); //clear terminal screen

while(1)
{
printf("\n\t\t\t\t==================== Singly Linked List Menu ============\n");
printf("\t\t\t\t1. Create Linked List\n");
printf("\t\t\t\t2. Add at beginning\n");
printf("\t\t\t\t3. Add after\n");
printf("\t\t\t\t4. Delete\n");
printf("\t\t\t\t5. Display\n");
printf("\t\t\t\t6. Count\n");
printf("\t\t\t\t7. Reverse\n");
printf("\t\t\t\t8. Search\n");
printf("\t\t\t\t9. Quit");
printf("\n\t\t\t\t=========================================================\n");
printf("\n\t\t\t\tEnter your choice : ");
scanf("%d",&choice);

system("clear"); //clear terminal screen

switch(choice)
{
	case 1:
		printf("\n\n\t\t\t\tHow many nodes you want : ");
		scanf("%d", &n);
	        char YN;
		printf("\n\n\t\t\t\tAre you sure ? (Y/N) : ");
                scanf(" %c",&YN);
                if(YN =='Y' || YN == 'y' ){//do nothing
		}
		else
                 continue;//come out of the case 1

		int i = 0;

		while(i<n)
		{		
		printf("\n\t\t\t\tEnter the element : ");
		scanf("%d",&m);

		if(checkReaptedData(m))//check duplicate data/element
                      continue;//ask again element

		Create_List(m);//create node and add in list
		
		i++;
		}
		break;
	case 2:
                printf("\n\n\t\t\t\tEnter the element : ");
		scanf("%d",&m);

		if(checkReaptedData(m))//check duplicate data/element
                      continue;//ask again element
                
		AddAtBegin(m); 
		
		break;
	case 3:
		if(CheckEmptyList(start) == -1)
			continue;//come out of case 3

		printf("\n\n\t\t\t\tEnter the element : ");
		scanf("%d",&m);
		
		printf("\n\t\t\t\tEnter the position after which this element is inserted : ");
		scanf("%d",&position);
		
	       	if(checkReaptedData(m))
                      continue;
	
		AddAfter(m,position);
	
		break;
	case 4:
		if(CheckEmptyList(start) == -1)
                        continue;//come out of case 4

		printf("\n\n\t\t\t\tEnter the element for deletion : ");
		scanf("%d",&m);
		
		Del(m);
		
		break;
	case 5:
		Display();//display Singly linked list data/element
		break;
	case 6:
		if(CheckEmptyList(start) == -1)
                        continue;//come out of case 5

		Count();//count no. of element/data/node in Singly linked list 
		
		break;
	case 7:
		Rev();//reverse Singly linked list right to left vice-versa
		
		break;
	case 8:
		 if(CheckEmptyList(start) == -1)
                        continue;//come out of case 8

		printf("\n\n\t\t\t\tEnter the element to be searched : ");
		scanf("%d",&m);

		Search(m);
		
		break;
	case 9:
		exit(0);//come out of the program
	default:
		printf("\n\n\t\t\t\tWrong Choice\n");

}//end switch
}//end while
}//end main


