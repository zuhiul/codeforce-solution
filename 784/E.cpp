#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int a,b,c,d;
int main() {
    //scanf("%d%d%d%d",&a,&b,&c,&d);
	for(a = 0;a<=1;a++) for(b = 0;b<=1;b++) for(c = 0;c<=1;c++) for(d = 0;d<=1;d++) {
		int nouse1=a^b;
		int nouse4=c|d;
		int nouse5=b&c;
		int nouse6=a^d;
		int nouse2=nouse1&nouse4;
		int nouse3=nouse5|nouse6;
		int ans=nouse2^nouse3;
		cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<ans<<endl;
	}
}
