#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int, int> mat;
	mat[1] = 2;
	mat[2] = 3;
	for(auto i:mat) {
		cout<<i.first<<endl;
	}
	return 0;
}
