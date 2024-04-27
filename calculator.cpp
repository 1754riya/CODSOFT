#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int num1,num2;
    char x;
	cout<<"Enter number 1:"<<endl;
	cin>>num1;
	cout<<"Enter number 2:"<<endl;
	cin>>num2;
	cout<<"press 'a' for addition"<<endl;
	cout<<"press 'b' for subtraction"<<endl;
	cout<<"press 'c' for multiplication"<<endl;
	cout<<"press 'd'for divison"<<endl;
	cout<<"press 'e'for reminder"<<endl;
	cin>>x;
	if(x=='a')
	cout<<"The addition ="<<num1+num2<<endl;
	else if(x=='b')
	cout<<"The subtraction = "<<num1-num2<<endl;
    else if(x=='c')
	cout<<"The multiplication = "<<num1*num2<<endl;
	else if(x=='d')
	cout<<"The divison = "<<num1/num2<<endl;
	else if(x=='e')
	cout<<"The reminder = "<<num1%num2<<endl;
	else
	cout<<"invalid operation"<<endl;
}