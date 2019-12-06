#include<bits/stdc++.h>
using namespace std;
const int maxm = 1e5+10;
int ans[maxm];
int a0, a1, a2, a3;
bool check(int a,int b,int c,int d, int start) {
	int ind = 0;
	if(start == 0 && a) ans[ind++] = 0, a--;
	else if(start == 2 && c) ans[ind++] = 2, c--;
	else if(start == 3 && d) ans[ind++] = 3, d--;
	else ans[ind++] = 1, b--;
	while(a||b||c||d) {
		if(ans[ind-1] == 0) {
			ans[ind++] = 1, b--;
			continue;
		}
		if(ans[ind-1] == 1) {
			if(a) ans[ind++] = 0, a--;
			else ans[ind++] = 2, c--;
			continue;
		}
		if(ans[ind-1] == 2) {
			if(b) ans[ind++] = 1, b--;
			else ans[ind++] = 3, d--;
			continue;
		}
		if(ans[ind-1] == 3) ans[ind++] = 2, c--;
		if(start == 0) {
			//cout<<ind-1<<' '<<ans[ind-1]<<endl;
		}
		if(a<0||b<0||c<0||d<0) return false;
	}
	return true;
}
void print() {
	int len = a0+a1+a3+a2;
	puts("YES");
	for(int i = 0;i<len;i++) {
		printf("%d ", ans[i]);
	}
}
int main() {
	scanf("%d%d%d%d",&a0, &a1, &a2, &a3);
	for(int i =0;i<4;i++) {
		if(check(a0, a1, a2, a3, i)) {
			print();
			return 0;
		}
	}
	puts("NO");
	return 0;
}
