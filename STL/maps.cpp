#include<iostream>
#include<map>
using namespace std;

int main(){
	map<string,int> ages;
	ages["Mike"] = 40;
	ages["Raj"] = 20;
	ages["Vicky"] = 30;
	cout<<ages["Raj"]<<endl;
	
	//iteration through maps

	ages["Mike"] = 70;

	pair<string,int> addToMap("Peter",100);
	ages.insert(addToMap);

	ages.insert(pair<string,int>("yash",60));

	ages.insert(make_pair("shubhi",200));
	//this will overwite mike, so keys will always be unique
	for(map<string,int>::iterator it=ages.begin(); it!=ages.end(); it++){
		cout<<it->first<<": "<<it->second<<endl;
	}

	//accesing element whose key does not exist will give 0
	cout<<ages["Sue"];
	//will give 0

	//better method is
	if(ages.find("Vicky") != ages.end()){
		cout<<"Found vicky"<<endl;
	}
	//find returns iterator to end of container if key is not found
	else{
		cout<<"key not found"<<endl;
	}
	//What we actua;;y are storing in maps is of type pair<string,int>
	for(map<string,int>::iterator it=ages.begin(); it!=ages.end(); it++){
		pair<string,int> age= *it;
		cout<<age.first<<": "<<age.second<<endl;
	}


//it(iterator) is a pointer to a struct who has two fields first and second

	return 0;
}