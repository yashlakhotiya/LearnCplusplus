#include<iostream>
using namespace std;

class Parent{
private:
	int one;
public:
	Parent():one(0){

	}

	Parent(const Parent &other):one(0){
		one = other.one;
		cout<<"Copy parent"<<endl;
	}

	void print(){
		cout<<"Calling print() from Parent without using virtual"<<endl;
	}

	virtual void show(){
		cout<<"Calling show() In base class Using virtual"<<endl;
	}

	virtual ~Parent(){

	}
};

class Child: public Parent{
private:
	int two;
public:
	Child():two(0){

	}
	void print(){
		cout<<"Calling print() from Child without virtual"<<endl;
	}
	void show(){
		cout<<"calling show() In child class using virtual"<<endl;
	}
};

int main(){
	Child c1;
	Parent p1;
	Parent &p2 = c1;
	p2.print();
	p2.show();

	Parent &p3 = p1;
	p3.print();
	p3.show();

	Parent p4 = Child();
	p4.print();

	return 0;
}