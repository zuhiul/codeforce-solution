#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm = 1e6+10;
int len;
int num[maxm];
int buf[maxm];
int main() {
	scanf("%d",&len);
	for(int i = 0;i<len;i++) scanf("%d", num+i), num[i]&=1;
	for(int i = 0;i<len;i++) {
		if(buf[0] == 0 || num[i] != buf[buf[0]]) buf[++buf[0]] = num[i];
		else buf[0]--;
	}
	printf("%s", buf[0]<=1?"YES":"NO");
	return 0;
}

