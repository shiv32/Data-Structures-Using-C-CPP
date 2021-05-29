//linked list-2
//Singly Linked List using C++

#include <iostream>

using namespace std;

class Linked_List
{

	//structure declaration for the node
	struct node
	{
	int info;
	struct node *link;
	};
    
	//private structure variable declared
	struct node *start = NULL; //empty list

	public:
        void Linked_list(){//Constructor defined
         start = NULL; //singly linked list empty
	}

        //public function declared
	void Create_List(int); 
	void AddAtBegin(int);
	void AddAfter(int,int);
	void Delete();
	void Count();
	void Search();
	void Display();
	void Reverse();
	int  CheckRepeatedData(int);
	int  CheckEmptyList();
	void BannerStart();
	void BannerEnd();
	void BorderStart();
	void BorderEnd();
};

//border start
void Linked_List::BorderStart(){
cout<<"\n\t\t\t=======================================================================\n";
}

//border end
void Linked_List::BorderEnd(){
cout<<"\n\t\t\t=======================================================================";
}


//start banner
void Linked_List::BannerStart(){
cout<<endl<<"\t\t\t================ Singly Linked List using C++  ========================"<<endl<<endl;
}

//end Banner
void Linked_List::BannerEnd(){
cout<<endl<<"\t\t\t======================================================================="<<endl<<endl;
}

//check empty list
int Linked_List::CheckEmptyList()
{
	 if(start == NULL)//Singly linked list empty
	{
	  printf("\n\t\t\t\t\t\tLinked List is empty\n");
	  return -1;
	}
	return 0;
}

//check duplicate data in Singly Linked List
int Linked_List::CheckRepeatedData(int data)
{
  struct node *q=start;
  int pos = 1;

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

//Create a new linked list of elements
void Linked_List::Create_List(int data)
{
struct node *q,*tmp;

//new node created with new operator
tmp = (struct node*)new(struct node);
tmp->info=data;
tmp->link=NULL;

if(start == NULL){ //list is empty
   start=tmp;
}else{ //element is inserted at the end
    q=start;
    
    while(q->link != NULL)
     q=q->link;
     
     q->link=tmp;
     }
}

//Add new element at the begining
void Linked_List::AddAtBegin(int data)
{
 struct node *tmp;

 //new node created
 tmp=(struct node *)new(struct node);
 tmp->info=data;
 tmp->link=start;
 start=tmp;
}

//Add new element at any specified position
void Linked_List::AddAfter(int data, int pos)
{
struct node *tmp,*q;
int i;
q=start;
//find the position in linked list to insert
for(i=0;i<pos-1;i++)
{
q=q->link;
if(q==NULL)
{
cout<<"\t\t\t\t\tThere are less than "<<pos<<" elements";
return;
}
}

//new node created
tmp = (struct node *)new(struct node);
tmp->link = q->link;
tmp->info=data;
q->link=tmp;
}	

//Delete an element from the list
void Linked_List::Delete()
{
struct node *tmp,*q;
int data;
cout<<"\t\t\t\t\tEnter the element for deletion : ";
cin>>data;

if(start->info == data)
{
	tmp=start;
	start=start->link; //first element deleted
	delete(tmp);
	return;
}

q=start;

while(q->link != NULL && q->link->link != NULL)
{
   if(q->link != NULL && q->link->info==data) //element deleted in b/w
   {
   tmp=q->link;
   q->link = tmp->link;
   delete(tmp);
   return;
   }
   q = q->link;
}

if((q->link != NULL) && (q->link->info==data)) //last element deleted
{
 tmp=q->link;
 delete(tmp);
 q->link=NULL;
 return;
}
cout<<"\t\t\t\t\tElement "<<data<<" not found";
}

//Display Singly linked list data
void Linked_List::Display()
{
struct node *q;
if(CheckEmptyList() == -1)
   return;
q=start;
cout<<endl<<"\t\t\t\t\t---------: List is :---------"<<endl;
while(q!=NULL)
{
  cout<<"{"<<q<<"}"<<"["<<q->info<<" : "<<q->link<<"]";

  if(q->link != NULL)
  {
    cout<<"->";
  }

  q=q->link;
}
}

//Count no. of node
void Linked_List::Count()
{
 struct node *q=start;
 int cnt=0;
 while(q!=NULL)
 {
 q=q->link;
 cnt++;
 }
 cout<<"\t\t\t\t\tNumber of elements is/are : "<<cnt;
}

//Reverse Singly linked list node
void Linked_List::Reverse()
{
  struct node *p1,*p2,*p3;

  if(start->link==NULL)//only one element/data
    return;

  p1=start;
  p2=p1->link;
  p3=p2->link;
  p1->link=NULL;
  p2->link=p1;

 while(p3!=NULL)
 {
   p1=p2;
   p2=p3;
   p3=p3->link;
   p2->link=p1;
 }
  start=p2;
}

//Search data in Singly linked list
void Linked_List::Search()
{
   struct node *ptr = start;
   int pos=1, data;

  cout<<"\t\t\t\t\tEnter the element to be searched : ";
  cin>>data;

 while(ptr!=NULL)
 {
    if(ptr->info==data)
    {
    cout<<"\t\t\t\t\tItem "<<data<<" found at position "<<pos;    
    return;
    }
    ptr=ptr->link;
    pos++;
 }

 if(ptr==NULL)
   cout<<"\t\t\t\t\tItem "<<data<<" not found in list";
}

//main body
int main()
{
int choice,n,m,position,i;
Linked_List sl;
system("clear");//clear terminal
while(1) //infinite
{
sl.BannerStart();	
cout<<"\t\t\t\t\t\t1.Create List"<<endl;
cout<<"\t\t\t\t\t\t2.Add at begining"<<endl;
cout<<"\t\t\t\t\t\t3.Add after"<<endl;
cout<<"\t\t\t\t\t\t4.Delete"<<endl;
cout<<"\t\t\t\t\t\t5.Display"<<endl;
cout<<"\t\t\t\t\t\t6.Count"<<endl;
cout<<"\t\t\t\t\t\t7.Reverse"<<endl;
cout<<"\t\t\t\t\t\t8.Search"<<endl;
cout<<"\t\t\t\t\t\t9.Quit"<<endl;
sl.BannerEnd();
cout<<"\t\t\t\t\t    Enter your choice : ";
cin>>choice;
switch(choice)
{
	case 1:
		system("clear");
		sl.BorderStart();
		cout<<"\t\t\t\t\tHow many nodes you want : ";
		cin>>n;
		char YN;
                printf("\n\t\t\t\t\tAre you sure ? (Y/N) : ");
		scanf(" %c",&YN);
		if(YN =='Y' || YN == 'y' ){//do nothing
		}
		else{
		    sl.Display(); //display list
		    sl.BorderEnd();
		    continue; //come out of the case 1
		}
		i = 0;
		while(i<n)
		{
		cout<<"\n\t\t\t\t\tEnter the element : ";
		cin>>m;
		if(sl.CheckRepeatedData(m)) //check duplicate data/element
	        continue; //ask again element
		sl.Create_List(m);
		i++;
		}
		sl.Display(); //display list
		sl.BorderEnd();
		break;
	case 2:
		system("clear");
		sl.BorderStart();
		cout<<"\t\t\t\t\tEnter the element : ";
		cin>>m;
		if(sl.CheckRepeatedData(m))//check duplicate data/element
                continue; //go to main menu 
		sl.AddAtBegin(m);
		sl.Display();
		sl.BorderEnd();
		break;
	case 3:
		system("clear");
		sl.BorderStart();
	        if(sl.CheckEmptyList() == -1){ //check empty list
		sl.BorderEnd();
                continue; //come out of case 3
                }
		cout<<"\t\t\t\t\tEnter the element : ";
		cin>>m;
		if(sl.CheckRepeatedData(m)) //check duplicate data/element
                continue; //go to main menu
		cout<<"\t\t\t\t\tEnter the postion : ";
		cin>>position;
		sl.AddAfter(m,position);
		sl.Display();
		sl.BorderEnd();
		break;
	case 4:
		system("clear");
		sl.BorderStart();
	        if(sl.CheckEmptyList() == -1){ //check empty list
		sl.BorderEnd();
                continue; //come out of case 4
		}
		sl.Delete();
		sl.Display();
		sl.BorderEnd();
		break;
	case 5:
		system("clear");
		sl.BorderStart();
		if(sl.CheckEmptyList() == -1){ //check empty list
		sl.BorderEnd();
                continue; //come out of case 5
                }
		sl.Display();
                sl.BorderEnd();
		break;
	case 6:
		system("clear");
		sl.BorderStart();
		if(sl.CheckEmptyList() == -1){ //check empty list
		sl.BorderEnd();
                continue; //come out of case 6
                }
		sl.Count();
		sl.Display();
		sl.BorderEnd();
		break;
	case 7:
		system("clear");
		sl.BorderStart();
		if(sl.CheckEmptyList() == -1){ //check empty list
		sl.BorderEnd();
                continue; //come out of case 7
                }
		sl.Reverse();
		sl.Display();
		sl.BorderEnd();
		break;
	case 8:
		system("clear");
		sl.BorderStart();
		if(sl.CheckEmptyList() == -1){ //check empty list
		sl.BorderEnd();
                continue; //come out of case 8
                }
		sl.Search();
		sl.Display();
		sl.BorderEnd();
		break;
	case 9:
		system("clear");
		exit(0); //exit list program
	default:
		system("clear");
		sl.BorderStart();
		cout<<endl<<"\t\t\t\t\t\tWrong choice";
		sl.BorderEnd();
}//end switch
}//end while
return 1;
}//end main


