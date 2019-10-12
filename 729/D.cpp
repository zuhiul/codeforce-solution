#include<bits/stdc++.h>
using namespace std;
const int maxm = 2e5+10;
int len, num, wid, has_shoot;
char que[maxm];
vector<int> shoot;
int main(){
	scanf("%d%d%d%d%s", &len, &num, &wid, &has_shoot, que);
	int cnt = 0, all = 0;
	for(int i = 0;i<len;i++) {
		if(que[i]=='0') {
			cnt++;
			if(cnt==wid) all++, cnt = 0, shoot.push_back(i);
		} else cnt = 0;
	}
	printf("%d\n", all-num+1);
	for(int i = all-num+1,j=0;i;i--,j++) {
		printf("%d ", shoot[j]+1);
	}
	return 0;
}
