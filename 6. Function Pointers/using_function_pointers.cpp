#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool match(string test){
	//return test == "two";
	return test.size() == 3;
}

int countStrings(vector<string> &texts,bool (*match)(string test)){
	int count = 0;
	for(auto it = texts.begin(); it != texts.end(); it++){
		if((*match)(*it)) count++;
		//if(match(*it)) count++; IS ALSO CORRECT
	}
	return count;
}

int main(){
	vector<string> texts;
	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");
	texts.push_back("two");
	texts.push_back("four");
	texts.push_back("two");
	texts.push_back("three");

	cout<<match("one")<<endl;

	cout<<count_if(texts.begin(), texts.end(), match) << endl;

	cout<<countStrings(texts,match)<<endl;

	return 0;
}