//program-3
//struct, dangling pointer

#include<stdio.h>
#include<stdlib.h>

struct Employee
{
int Emp_Code;       //4b
char Emp_Name[50];  //50b
char Emp_Nlast[50]; //50b
float Emp_Salary; //4b
};

typedef struct Employee Emp;

void main()
{
Emp emp;
Emp *emp_ptr;
int n,i;

printf("\n==== Emp member size ====\n");
printf("\nsize of Emp_Code: %lu byte\n",sizeof(emp.Emp_Code));
printf("\nsize of Emp_Name: %lu byte\n",sizeof(emp.Emp_Name));
printf("\nsize of Emp_Nlast: %lu byte\n",sizeof(emp.Emp_Nlast));
printf("\nsize of Emp_Salary: %lu byte\n",sizeof(emp.Emp_Salary));
printf("\nsize of Emp: %lu byte\n",sizeof(Emp));


printf("\nEnter the no. of Employee(s) to be added\n");
scanf("%d",&n);

emp_ptr = (Emp *)malloc(n*sizeof(Emp));

if(emp_ptr == NULL)
{
printf("\nmemory allocation is failed\n");
exit(0);
}else
printf("\nmemory allocation is successfull\n");

for(i=0;i<n;i++)
{
printf("\naddress of emp_ptr[%d] is : %p\n",i,&emp_ptr[i]);
printf("\nsize of emp_ptr[%d] is : %lu byte\n",i,sizeof(emp_ptr[i]));
}	

for(i=0;i<n;i++)
{
printf("\n==== Enter Emp Detail =====\n");

printf("\nEnter the Employee code: ");
scanf("%d", &emp_ptr[i].Emp_Code);

printf("\nEnter the Employee first name: ");
scanf("%s", emp_ptr[i].Emp_Name);

printf("\nEnter the Employee last name: ");
scanf("%s", emp_ptr[i].Emp_Nlast);

printf("\nEnter the Employee salary: ");
scanf("%f", &emp_ptr[i].Emp_Salary);
}	

printf("\n=====Added Emp====== \n");

for(i=0;i<n;i++)
{
printf("\n========================\n");
printf("\naddress of Emp at emp_ptr[%d] is : %p\n",i,&emp_ptr[i]);
printf("\nsize of emp_ptr[%d] is : %lu byte\n",i,sizeof(emp_ptr[i]));

printf("\nEmp Code : %d \n",emp_ptr[i].Emp_Code);
printf("\nEmp Nmae : %s %s \n",emp_ptr[i].Emp_Name, emp_ptr[i].Emp_Nlast);
printf("\nEmp Salary : %f \n",emp_ptr[i].Emp_Salary);
}	

printf("\n");
free(emp_ptr);

printf("\n===== after free ====\n");
printf("\naddress store at emp_ptr[0] after free() is : %p\n",&emp_ptr[0]);

emp_ptr = NULL;
printf("\n===== after NULL====\n");
printf("\naddress store at emp_ptr[0] after free() is : %p\n",&emp_ptr[0]);
}	
