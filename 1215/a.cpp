#include<bits/stdc++.h>
using namespace std;
int main(){
	int a1,a2,k1,k2,n;
	scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
	int n2 = n;
	if(k1>k2) swap(k1,k2), swap(a1,a2);
	
	if(n<=(k1-1)*a1+(k2-1)*a2) {
		printf("0 ");
	} else {
		printf("%d ", min(n - (k1-1)*a1-(k2-1)*a2, a1+a2));
	}
	

	if(n2>=a1*k1) {
		n2-=a1*k1;
		printf("%d\n", a1+n2/k2);
	} else {
		printf("%d\n", n2/k1);
	}
	
	return 0;
}
