#include<bits/stdc++.h>
using namespace std;
long long dp[26][15][15][5][5];
//长度为i的序列, j个波峰，k个波谷，y[i-1] = a, y[i] = b的方案数
void init() {
	for(int i = 1;i<=4;i++) for(int j = 1;j<=4;j++) {
		if(i==j) continue;
		dp[2][0][0][i][j] = 1;
	}	
	for(int i = 2;i<20;i++) for(int j = 0;j<=10;j++) 
		for(int k = 0;k<=10;k++) for(int a = 0;a<=4;a++) 
			for(int b = 0;b<=4;b++) 
				if(dp[i][j][k][a][b]) {
					for(int c = 1;c<=4;c++)  {
						if(c==b) continue;
						if(a>b && b<c) dp[i+1][j][k+1][b][c] += dp[i][j][k][a][b];
						else if(a<b && b>c) dp[i+1][j+1][k][b][c] += dp[i][j][k][a][b];
						else dp[i+1][j][k][b][c] += dp[i][j][k][a][b];
					}					
				}
}
int main(){
	init();
	int a,b;
	scanf("%d%d",&a,&b);
	long long ans = 0;
	for(int i = 0;i<=4;i++) for(int j = 0;j<=4;j++) ans += dp[a][b][b-1][i][j];
	printf("%lld\n", ans);
	return 0;
}
