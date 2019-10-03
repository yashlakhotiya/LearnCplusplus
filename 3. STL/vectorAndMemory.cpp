#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<double> numbers(20);
	cout<<"size: "<<numbers.size()<<endl;
	//capacity is the size of the internal array the the vector is using
	int capacity = numbers.capacity();
	cout<<"capacity: "<<numbers.capacity()<<endl;
	for(int i = 0; i < 10000; i++){
		if(numbers.capacity() != capacity){
			capacity = numbers.capacity();
			//size of the internal array increases  exponentially
			cout<<"capacity "<<capacity<<endl;
		}
		numbers.push_back(i);
	}
	numbers.clear();
	cout<<"size: "<<numbers.size()<<endl;
	//capacity does not changes after clearing the vector
	cout<<"capacity: "<<numbers.capacity()<<endl;
}