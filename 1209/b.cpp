#include<bits/stdc++.h>
using namespace std;
int n;
char que[1000];
int a[1000],b[1000];
int main(){
	scanf("%d",&n);
	scanf("%s", que);
	int ans = 0;
	for(int i = 0;i<n;i++) if(que[i]=='1') ans++;
	for(int i = 0;i<n;i++) scanf("%d%d", a+i,b+i);
	for(int i = 1;i<100000;i++) {
		int cnt = 0;
		for(int j = 0;j<n;j++) {
			if(i>=b[j]&&(i-b[j])%a[j]==0) {
				if(que[j]=='0') que[j]= '1';
				else que[j]='0';
			}
			if(que[j]=='1') cnt++;
		}
		ans= max(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}
