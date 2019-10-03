#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Test{
private:
	string name;
public:
	Test(string name):
	name(name){}

	~Test(){//DESTRUCTOR
		//cout<<"Object destroyed"<<endl;
	}

	void print(){
		cout<<name<<endl;
	}
};

int main(){

	//LIFO
	stack<Test> testStack;


	//When we add objects to stack, we destroy original objecta nd create a copy of object and add it to stack
	testStack.push(Test("Mike"));
	testStack.push(Test("John"));
	testStack.push(Test("Sue"));

	cout<<endl;

	// when we are accessing objects in the stack, it returns a reference of that object
	//But in above line, the variable is not a Test pointer but a Test object, 
	//After testStack.top() returns a reference, it copies all the data in that reference and instance variables
	//to the test1 object for correctness which takes time.
	//Instead, we can just use a Test pointer(reference) variable for it to be fast and efficient
	Test test1 = testStack.top();
	test1.print();

	//************************************//
	//Avoid using the next commented block as it works but is conecptually wrong
	//we are trying to print the memory location pointed by testPointer which is alredy destructed by pop() function


//THIS IS INVALID! CODE!##########OBJECT IS DESTROYED

	/*
	Test &testPointer = testStack.top();//returns reference
	testStack.pop();//destructs the objected pointed by testPointer
	testPointer.print();//reference refers to destroyed objects
	*/

	//*************************************//

	//USE THIS

	Test &test2 = testStack.top();
	test2.print();
	testStack.pop();

	//There is no way to iterate through stack
	//as stack is not made to iterate
	//But still if you want to iterate, we can do the following

	while(testStack.size() > 0){
		Test &test = testStack.top();
		test.print();
		testStack.pop();
	}

	//********############## Q U E U E ##############*******

	/*

	remove <- front ===== back <- insert
	*/
	//FIFO

	//adding from rear
	//deleting from front

	queue<Test> testQueue;

	testQueue.push(Test("Mike"));
	testQueue.push(Test("John"));
	testQueue.push(Test("Sue"));

	cout<<endl;

	while(testQueue.size() > 0){
		Test &test = testQueue.front();


		//  to get back object

		//testQueue.back().print();


		test.print();
		testQueue.pop();
	}
	return 0;

}