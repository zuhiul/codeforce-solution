#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> son[100];
long long dirx[] = {1,-1,0,0};
long long diry[] = {0,0,1,-1};
bool has_position[100];
long long ansx[100],ansy[100];
void lay(int ind, int pre, long long x,long long y, int dir, int floor) {
	has_position[ind] = true;
	ansx[ind] = x;
	ansy[ind] = y;
	long long rdis = 1ll<<floor;
	int dir_ind = 0;
	for(int i:son[ind]) {
		if(i==pre) continue;
		if(dir_ind==(dir^1)) dir_ind++;
		//printf("%d %d\n", dir, dir_ind);
		if(dir_ind>3) {
		//	printf("%d %d\n", dir, dir_ind);
			printf("NO");
			exit(0);
		}
		lay(i, ind, x+dirx[dir_ind]*rdis, y+diry[dir_ind]*rdis, dir_ind, floor-1);
		rdis--;
		dir_ind ++ ;
	}
}
int main(){
	scanf("%d",&n);
	for(int i = 1, from ,to;i<n;i++) {
		scanf("%d%d",&from,&to);
		son[from].push_back(to);
		son[to].push_back(from);
	}
////for(int i = 1;i<=n;i++) {
////	printf("%d\t", i);
////	for(int j : son[i]) printf("%d ", j);
////	printf("\n");
////}
	lay(1,0,0,0,-1,50);
	for(int i = 1;i<=n;i++) {
		if(!has_position[i]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i = 1;i<=n;i++) {
		printf("%lld %lld\n", ansx[i], ansy[i]);
	}
	return 0;
}
