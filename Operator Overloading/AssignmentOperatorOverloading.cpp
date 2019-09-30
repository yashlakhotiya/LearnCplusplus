#include<iostream>
using namespace std;

class Test{
private:
	int id;
	string name;
public:
	Test(): id(0),name(""){}//Default constructor
	Test(int id,string name): id(id),name(name){}
	void print(){
		cout<<id<<": "<<name<<endl;
	}
	Test(const Test &other){
		cout<<"Copy COnstructor running"<<endl;
		id = other.id;
		name = other.name;
	}

	//IMPLEMENTING ASSIGNMENT(=) OVERLOADING

	const Test &operator=(const Test &other){

		cout<<"Assignment running"<<endl;
		id = other.id;
		name = other.name;

		return *this;
		//to return the reference of the actual object
	}
};

int main(){

	Test test1(10,"Mike");
	cout<<"Print test1"<<flush;
	test1.print();

	Test test2(20,"Bob");

	test2 = test1;//assignment overloading
	//shallow copy
	cout<<"Print test2"<<flush;
	test2.print();

	Test test3;
	//test3 = test2 = test1;

	//test3 = test2;
	//Is equivalent to test3.operator=(test2)

	test3.operator=(test2);
	cout<<"Print test3"<<flush;
	test3.print();

	cout<<endl;

	//Copy Initialization
	//If copy constructor is not given, it will use implicit copy constructor

	Test test4 = test1;//It wont print "Assignment running" on screen as this is using copy constructor assignment
	//This is not using = operator. It is using copy constructor
	test4.print();

	return 0;
}