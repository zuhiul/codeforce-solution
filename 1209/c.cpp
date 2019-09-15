#include<bits/stdc++.h>
using namespace std;
int len;
const int maxm = 2e5+10;
char que[maxm];
char ans[maxm];
vector<char> buf;
bool check(int a) {
	buf.clear();
	memset(ans,0,sizeof(ans));
	char now = a+'0';
	for(int i = len-1;i>=0;i--) if(que[i]<=now) {
		buf.push_back(que[i]);
		ans[i] = '1';
		now = que[i];
	}
	reverse(buf.begin(),buf.end());
	for(int i = 0;i<len;i++) if(ans[i]!='1') {
		ans[i] = '2';
		buf.push_back(que[i]);
	}
	for(int i = 1;i<len;i++) if(buf[i]<buf[i-1]) return false;
	return true;
}
void solve(){
	scanf("%d",&len);
	scanf("%s", que);

	for(int i =0;i<=9;i++) {
		char nouse = '0'+i;
		if(check(i)) {
			puts(ans);
			return ;
		}
	}
	printf("-\n");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
