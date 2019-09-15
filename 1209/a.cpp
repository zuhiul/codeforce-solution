#include<bits/stdc++.h>
using namespace std;
int n;
int num[1000];
bool used[1000];
int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d", num+i);
	sort(num+1,num+n+1);
	int has_use = 0;
	int ans = 0;
	int ind = 1;
	while(has_use!=n){
		while(used[ind]) ind++;
		ans++;
		for(int i = ind;i<=n;i++) {
			if(num[i]%num[ind] ==0&&used[i]==false) {
				used[i] = true;
				has_use++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
