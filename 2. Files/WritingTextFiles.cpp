#include<iostream>
#include<fstream>
/*streams are objects where we can write data to and read data in*/
using namespace std;
//*********USING ofstream****************//output file stream
/*int main(){
	ofstream outFile;
	string outputFileName = "text.txt";
	outFile.open(outputFileName);
	if(outFile.is_open()){
		outFile << "Hello there"<<endl;
		outFile << 123 << endl;
		outFile.close();
	}
	else{
		cout<<"Could not name file: "<<outputFileName<<endl;
	}
	return 0;
}*/
//**************USING fstream************//file stream
int main(){
	fstream outFile;
	string outputFileName = "text1.txt";
	outFile.open(outputFileName,ios::out);
	if(outFile.is_open()){
		outFile << "Hello there"<<endl;
		outFile << 123 << endl;
		outFile.close();
	}
	else{
		cout<<"Could not name file: "<<outputFileName<<endl;
	}
	return 0;
}
