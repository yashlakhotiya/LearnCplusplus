#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream inFile;
	string fileName = "ass2.txt";
	inFile.open(fileName);
	if(inFile.is_open()){
		string line;
		//****WILL GIVE ONLY FIRST WORD OF FILE****
		/*inFile>>line;
		cout<<line<<endl;
		*/
		//TO READ FILE LINE BY LINE
		/*while(!inFile.eof()){
			getline(inFile,line);
			cout<<line<<endl;
		}*/
		//WE CAN ALSO USE
		cout<<"WE CAN ALSO USE\n";
		while(inFile){
			getline(inFile,line);
			cout<<line<<endl;
		}
		//will stop when it reaches end of file
		inFile.close();

	}
	else{
		cout<<"Error opening file: "<<fileName;
	}
}