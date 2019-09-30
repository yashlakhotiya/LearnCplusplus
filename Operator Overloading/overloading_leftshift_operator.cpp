#include<iostream>
#include<ostream>
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
		cout<<"Copy Constructor running"<<endl;
		id = other.id;
		name = other.name;
	}

	friend ostream &operator<<(ostream &out, const Test &test){
		out<<test.id<<": "<<test.name;
		return out;
	}
};

int main(){
	Test test1(10,"Mike");
	Test test2(20,"Bob");
	test1.print();

	cout<<test1<<test2<<endl;

	//What if we could do cout<<test1;
	//We do << overloading

	//<< has left right associativity


}