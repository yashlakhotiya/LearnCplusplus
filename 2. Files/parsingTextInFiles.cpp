#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream input;
	string filename = "stats.txt";
	input.open(filename);
	if(!input.is_open()){
		return 1;
	}

	while(input){
		string line;
		getline(input,line,':');
		int population;
		input>>population;
		// input.get();
		input>>ws; //reads all whitespaces
		if(!input){
			break;
		}
		cout<<line<<" -- "<<population<<endl;
	}

	input.close();
}