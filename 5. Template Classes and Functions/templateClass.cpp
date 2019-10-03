#include<iostream>
using namespace std;

template<class T>
class Test{
private:
	T obj;
public:
	Test(T obj){
		this->obj = obj;
	}
	void print(){
		cout<<obj<<endl;
	}
};

int main(){
	Test<int> t1(1);
	t1.print();

	Test<string> t2("yash");
	t2.print();
	return 0;
}