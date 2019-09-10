#include<iostream>
using namespace std;

#pragma pack(push,1)
struct Person{
	char name[50];  //50 bytes
	int age;		//4 bytes
	double weight;	//8 bytes	total size of struct is 62 bytes but cout will give 64 bytes 
					//due to the padding added to the struct.If I add another char a(2 bytes),
					//it will still give 64 bytes.
					//to remove the padding, we enclose struct by #pragma pack(push,1) and #pragma pack(pop)
};
#pragma pack(pop)

int main(){
	cout<<sizeof(Person)<<endl;
	return 0;
}