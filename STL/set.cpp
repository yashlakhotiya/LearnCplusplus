#include<iostream>
#include<set> //only contain unique elements
using namespace std;

class Test{
	int id;
	string name;

public:
	Test(int id,string name):
		id(id),name(name){}

	void print() const{
		cout<<id<<": "<<name<<endl;
	}

	bool operator<(const Test &other) const{
		return name < other.name;
	}
};

int main(){
	set<int> numbers;
	numbers.insert(50);
	numbers.insert(10);
	numbers.insert(30);
	numbers.insert(20);

	for(auto it = numbers.begin(); it != numbers.end(); it++){
		cout<<*it<<endl;
	}

	auto itFind = numbers.find(30);
	if(itFind != numbers.end()){
		cout<<"Found: "<<*itFind<<endl;
	}

	//OR

	if(numbers.count(30)){
		cout<<"Number found"<<endl;
	}

	//Objects in set

	set<Test> tests;

	tests.insert(Test(10,"Mike"));
	tests.insert(Test(30,"Joe"));
	tests.insert(Test(20,"Sue"));

	for(auto it = tests.begin(); it!= tests.end(); it++){
		it->print();
	}
}