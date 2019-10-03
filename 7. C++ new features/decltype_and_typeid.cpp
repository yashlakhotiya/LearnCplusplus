#include<iostream>
#include<typeinfo>//to use typeid
using namespace std;

int main(){
	int value;
	cout<<typeid(value).name()<<endl;
	return 0;  
}