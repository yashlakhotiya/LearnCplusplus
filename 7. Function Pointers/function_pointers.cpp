#include<iostream>
using namespace std;

void test(int val){
	cout<<"Hello "<<val<<endl;
}

int main(){
	test(0);

	void (*pTest)(int);//pointer to a function with int as parameters
	//can also write void(*pTest)(int) = test;
	pTest = &test;//no need of round brackets
	//we can also remove & infront of function as name is the adress of function only

	//Calling function

	(*pTest)(8);//round brackets are used to call a function 

	pTest = test;//Name of function is a pointer to a function

	pTest(9);
}