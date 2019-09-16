#include<bits/stdc++.h>
using namespace std;
int n;
const int maxm = 2e6;
char que[maxm],que2[maxm];
int num[maxm];
int r[maxm];
int main(){
	scanf("%d",&n);
	scanf("%s%s", que,que2);
	vector<int> neg, pos;
	for(int i =0;i<n;i++){
		num[i] = que[i] - que2[i];
		if(num[i]==0) continue;
		if(num[i]>0) pos.push_back(i+1);
		if(num[i]<0) neg.push_back(i+1);
	}	
	if((pos.size()&1)!=(neg.size()&1)) {
		puts("-1");
		return 0;
	}
	printf("%lu\n", (pos.size()>>1)+(neg.size()>>1)+(pos.size()&1)*2);
	for(int i = 0;i+1<pos.size();i+=2) printf("%d %d\n", pos[i],pos[i+1]);
	for(int i = 0;i+1<neg.size();i+=2) printf("%d %d\n", neg[i],neg[i+1]);
	if(pos.size()&1) {
		printf("%d %d\n", pos[pos.size()-1], pos[pos.size()-1]);
		printf("%d %d\n", pos[pos.size()-1], neg[neg.size()-1]);
	}
	return 0;
}
