#include<iostream>
#include<list>
using namespace std;
int main(){
	//list contins a bunch of nodes which has a pointer to both pprevious and next element, i.e. doubly linked list
	list<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);

	//we ant used indexes in lists
	//we have to use iterator
	//as indexes are not there in lists
	//we can also add elements to its front unlike vector
	numbers.push_front(0);
	for(list<int>::iterator it = numbers.begin(); it!=numbers.end(); it++){
		cout<<*it<<endl;
	}
	cout<<endl;
	//if we want to insert an element at i'th position, we use insert method
	list<int>::iterator it = numbers.begin();
	numbers.insert(it,100);
	for(list<int>::iterator it = numbers.begin(); it!=numbers.end(); it++){
		cout<<*it<<endl;
	}
	cout<<endl;
	it++;
	cout<<"\nit: "<<*it;
	/*numbers.erase(it);
	cout<<"\nit: "<<*it;*/
	//after erasing also, iti is giving 1
	//we need to write like this
	it = numbers.erase(it);
	cout<<"\nit "<<*it;
	return 0;
}