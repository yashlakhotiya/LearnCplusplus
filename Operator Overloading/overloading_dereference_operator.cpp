#include"Complex.h"

using namespace std;
using namespace caveofprogramming;

int main(){
	Complex c1(3,4);
	Complex c2(4,5);
	Complex c3 = c1+c2;

	Complex c4 = *c1;
	Complex c5 = *c2;
	cout<<c4<<" "<<c5;

	return 0;
}