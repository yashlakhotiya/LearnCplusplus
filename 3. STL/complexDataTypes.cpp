//NESTED STL TYPES

#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
	map<string/*key*/,vector<int>/*value*/> scores;

	scores["Mike"].push_back(10);
	scores["Mike"].push_back(20);	
	scores["Vicky"].push_back(15);
	scores["Dean"].push_back(10);

	for(auto it = scores.begin(); it != scores.end(); it++){
		string name = it->first;
		vector<int> scoreList = it->second;

		cout<<name<<": "<<flush;

		for(int i = 0;i < scoreList.size(); i++){
			cout<<scoreList[i]<<" "<<flush;
		}
		cout<<endl;
	}
}