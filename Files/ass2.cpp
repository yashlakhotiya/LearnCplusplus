#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream fileStream;
	string fileName = "ass2.txt";
	fileStream.open(fileName);
	int count = 0;
	if(fileStream.is_open()){
		while(count++!=10){
			fileStream << "line number: "<<count<<endl;
		}
		fileStream.close();
	}
	else{
		cout<<"Error creating file\n";
	}
}