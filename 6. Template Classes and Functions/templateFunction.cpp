#include<iostream>
using namespace std;

template<class T>
void print(T n){
	cout<<"Template version "<<n<<endl;
}

void print(int n){//OVERLOADING print() FUNCTION
	cout<<"Non template version "<<n<<endl; //
}

template<class T>
void show(int value){
	cout<<T()<<endl;
}

int main(){
	print<int>(5);
	print<string>("print with <string>");
	print("print without <>; automatic type conversion");
	print(6);//will call non template version print() function
	//To run template version of print() function with int, then just give a diamond operator with function call
	print<>(6);

	show<double>();
	return 0;
}