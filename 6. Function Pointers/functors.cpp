#include<iostream>
using namespace std;

struct Test{
	virtual bool operator()(string &text) = 0;
	virtual ~Test(){}
};

struct MatchTest:public Test{
	virtual bool operator()(string &text){
		return text == "lion";
	}
};//FUNCTOR

void check(string text,Test &test){
	if(test(text)){
		cout<<"Text Matches"<<endl;
	}
	else{
		cout<<"No match!"<<endl;
	}
}

int main(){
	MatchTest pred;
	string value = "lion";
	cout<<pred(value)<<endl;
	MatchTest m;
	check("lion",m);
}