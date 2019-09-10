#include<iostream>
#include<fstream>
using namespace std;

#pragma pack(push,1)
struct Person{
	char name[50];  //50 bytes
	int age;		//4 bytes
	double height;	//8 bytes	total size of struct is 62 bytes but cout will give 64 bytes 
					//due to the padding added to the struct.If I add another char a(2 bytes),
					//it will still give 64 bytes.
					//to remove the padding, we enclose struct by #pragma pack(push,1) and #pragma pack(pop)
};
#pragma pack(pop)

int main(){
	Person someone = {"yash",20,70.8};
	string filename = "Binary File.bin";
	
	///////Write binary file////////

	ofstream outputFile;
	outputFile.open(filename,ios::binary);//ios::binary for reading binary files as there are no newline characters
	if(outputFile.is_open()){
		outputFile.write(reinterpret_cast<char *>(&someone),sizeof(Person));
		//new way of casting pointers is
		//		outputFile.write((char *)&someone,sizeof(Person));
		outputFile.close();
	}
	else{
		cout<<"Count not create file: "<<filename<<endl;
	}


	////////Read binary file back into struct///////////
	Person someoneElse = {};
	ifstream inputFile;
	inputFile.open(filename,ios::binary);//ios::binary for reading binary files as there are no newline characters
	if(inputFile.is_open()){
		inputFile.read(reinterpret_cast<char *>(&someoneElse),sizeof(Person));
		//new way of casting pointers is
		//		outputFile.write((char *)&someone,sizeof(Person));
		inputFile.close();
	}
	else{
		cout<<"Count not read file: "<<filename<<endl;
	}
	cout<<someoneElse.name<<endl;
	cout<<someoneElse.age<<endl;
	cout<<someoneElse.height<<endl;
	return 0;
}