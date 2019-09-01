#include<iostream>
using namespace std;

void mightGoWrongInt(){
	bool error = true;
	if(error){
		throw 8;
	}
}

void mightGoWrongString(){
	bool error1 = false;
	bool error2 = true;
	if(error1){
		throw "Something went wrong";
	}
	if(error2){
		throw string("Something else went wrong");//creating a string object and throwing it
	}
}

int main(){
	try{
		mightGoWrongInt();
	}
	catch(int e){
		cout<<"Error code: "<<e<<endl;
	}
	try{
		mightGoWrongString();
	}
	catch(char const * e){
		cout<<"Error message: "<<e<<endl;
	}
	catch(string &e){
		cout<<"String error message: "<<e<<endl;
	}
	return 0;
}