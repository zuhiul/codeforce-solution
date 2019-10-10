#include <cstdio>
int a,b,c,d;
int main() {
    scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n", ((1-b)&d) | (a&b&c) | (a&(1-c)&(1-d)));
}
