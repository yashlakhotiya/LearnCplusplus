#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector< vector<int> > grid(3/*rows*/,vector<int>(4,0)/*intialize each row as vector of size 4*/);
	 grid[1].push_back(8);
	 for(int row =0 ; row < grid.size(); row++){
	 	for(int col =0; col<grid[row].size(); col++){
	 		cout<<grid[row][col]<<flush;
	 	}
	 	cout<<endl;
	 }
} 