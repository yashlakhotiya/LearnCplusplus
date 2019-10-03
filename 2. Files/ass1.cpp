#include<iostream>
#include<fstream>
using namespace std;

int main(){
	string line = "",filename = "ass1.txt";
	ofstream outFile;
	outFile.open(filename);
	if(outFile.is_open()){
		while(line != "quit"){
			outFile << line << endl;
			cin>>line;
		}
		outFile.close();
	}
	else{
		cout<<"Error creating file"<<endl;
	}
}