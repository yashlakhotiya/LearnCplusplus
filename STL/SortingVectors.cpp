#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Test{
	//By default, instance variables in a class are private and in a struct, they are public.
	int id;
	string name;
public:
	Test(int id,string name): id(id), name(name){}
	void print(){
		cout<<id<<": "<<name<<endl;
	}
	/*bool operator<(const Test &other) const{
		if(name == other.name){
			return id < other.id;
		}
		else{
			return name < other.name;
		}
	}*/

	// F R I E N D keyword
	//It is added to a prorotype to tell that it is allowed to access its privte members

	friend bool comp(const Test &a,const Test &b);

	//if the above line is not added, then the sort line will give an error saying that it acnnot access private members of the class Test
};

//Function pointer -- Instead of implementing the < operator in class
//We can also write another function and pass the function as a pointer to the sort function
//as done below

bool comp(const Test &a, const Test &b){
	return a.name < b.name;
}

int main(){
	vector<Test> tests;
	tests.push_back(Test(5,"Mike"));
	tests.push_back(Test(10,"Sue"));
	tests.push_back(Test(7,"Raj"));
	tests.push_back(Test(3,"Vicky"));

	//sort(tests.begin(), tests.end(),comp);

	//TO SORT RANGE OF VECTORS

	sort(tests.begin(),tests.begin(),comp);

	for(int i = 0;i < tests.size(); i++){
		tests[i].print();
	}

	return 0;
}