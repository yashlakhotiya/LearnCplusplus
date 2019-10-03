#include<iostream>
using namespace std;

class Animal{
public:
	virtual void run()=0;
	virtual void speak()=0;//Notation of no implementation of pure virtual function
	//class of pure virtual function is called abstract class
	//we cant instantiate absract class
};

class Dog: public Animal{
public:
	virtual void speak(){
		cout<<"Woof!"<<endl;
	}
};

class Labrador: public Dog{
public:
	virtual void run(){
		cout<<"Labrador running"<<endl;
	}
};

void test(Animal &a){
	a.run();
}

int main(){
	//We cant create array of Animal,
	//but we can create array of Labrador
	//we can create array of animal pointers
	Labrador lab;
	lab.speak();
	lab.run();

	Animal *animals[5];
	animals[0] = &lab;
	animals[0]->speak();
	test(lab);
	return 0;
}