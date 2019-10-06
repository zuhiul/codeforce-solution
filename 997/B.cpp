#include<bits/stdc++.h>
using namespace std;
////int cal(int a) {
////	set<int> nouse;
////	for(int i = 0;i<=a;i++) {
////		for(int j = 0;i+j<=a;j++) {
////			for(int k = 0;i+j+k<=a;k++) {
////				nouse.insert(i+j*5+k*10+(a-i-j-k)*50);
////			}
////		}
////	}
////	return nouse.size();
////}
int ans[15] = {0,4,10,20,35,56,83,116,155,198,244};
int main(void)
{
	long long n;
	scanf("%lld", &n);
	if(n<=10)
		printf("%d\n", ans[n]);
	else
		printf("%lld\n", ans[10]+(n-10)*49-1);
	return 0;
}
