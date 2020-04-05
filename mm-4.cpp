//program-4
//new, delete operator, nothrow constant in C++

#include<iostream>

using namespace std;

class Company
{
	public:
		char *Emp_name;
		float *Salary;

};

int main()
{
Company emp;

cout<<endl;
cout<<"============================="<<endl;

cout<<"address of Emp_name before memory allocate :"<<(void *)emp.Emp_name<<endl;
cout<<"size in byte of Emp_name before memory allocate : "<<sizeof(emp.Emp_name)<<endl;

emp.Emp_name = new(nothrow) char[100];

cout<<"enter employee name : ";
cin.getline(emp.Emp_name, 100);

cout<<"address of Emp_name after memory allocate :"<<(void *)emp.Emp_name<<endl;
cout<<"size in byte of Emp_name after memory allocate : "<<sizeof(emp.Emp_name)<<endl;

if(!emp.Emp_name){
cout<<"allocation of memory failed for Emp_name"<<endl;
}else{
cout<<"Emp_name : "<<emp.Emp_name<<endl;
}

cout<<"====================================="<<endl;

cout<<"address of Salary before memory allocate :"<<emp.Salary<<endl;
cout<<"size in byte of Salary before memory allocate : "<<sizeof(emp.Salary)<<endl;

emp.Salary = new(nothrow) float[10];

cout<<"enter employee salary :";
cin >>*emp.Salary;

cout<<"address of Salary after memory allocate :"<<emp.Salary<<endl;
cout<<"size in byte of Salary after memory allocate : "<<sizeof(emp.Salary)<<endl;


if(!emp.Salary){
cout<<"allocation of memory failed for Salary"<<endl;
}else{
cout<<"Salary :"<<*emp.Salary<<endl;
}

cout<<"========== free memory ======="<<endl;

delete[] emp.Emp_name;
delete[] emp.Salary;

cout<<"address pointing by Emp_name after free : "<<(void *)emp.Emp_name<<endl;
cout<<"address pointing  by salary after free : "<<emp.Salary<<endl;

cout<<"======= after NULL ============="<<endl;

emp.Emp_name = NULL;
emp.Salary = NULL;

cout<<"address pointing by Emp_name after NULL : "<<(void *)emp.Emp_name<<endl;
cout<<"address pointing  by salary after NULL : "<<emp.Salary<<endl;

return 0;
}

