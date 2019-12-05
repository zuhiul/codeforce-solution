#include<bits/stdc++.h>
using namespace std; const int maxm = 2e5+10;
int len;
struct p{
	int val,ind;
};
p num2[maxm];
bool cmp(p a, p b) {
	if(a.val != b.val) return a.val > b.val;
	return a.ind < b.ind;
}
int num[maxm];
int len_que;
struct q {
	int len, o, ind;
	int ans ;
};
q que[maxm];
bool cmp2(q a, q b) {
	if(a.len!=b.len) return a.len<b.len;
	return a.o<b.o;
}
bool cmp3(q a, q b) {
	return a.ind < b.ind;
}
int used = 0;
int tree[maxm<<1];
void add(int ind) {
	while(ind<maxm) {
		tree[ind] += 1;
		ind += ind&-ind;
	}
}
int get(int a) {
	int ret = 0;
	while(a>0) {
		ret += tree[a];
		a-=a&-a;
	}
	return ret;
}

int get_ans(int o) {
	int ret = 0;
	int l = 0, r = maxm-1;
	while(l<r) {
		int mid = (l+r)>>1;
		if(get(mid)>=o) {
			ret = mid;
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	return num[ret];
}
void gao(int a) {
	while(used<que[a].len) {
		add(num2[used].ind);
		used++;
	}
	que[a].ans = get_ans(que[a].o);
}
int main (){
	scanf("%d",&len);
	for(int i = 1;i<=len;i++) {
		scanf("%d", num+i);
		num2[i].val = num[i];
		num2[i].ind = i;
	}
	sort(num2+1, num2+len+1, cmp);
	scanf("%d",&len_que);
	for(int i = 0;i<len_que;i++) {
		scanf("%d%d",&que[i].len, &que[i].o);
		que[i].ind = i;
	}
	sort(que, que+len_que, cmp2);
	for(int i = 0;i<len_que;i++ ){
		gao(i);
	}
	sort(que, que+len_que, cmp3);
	for(int i = 0;i<len_que;i++) {
		printf("%d\n", que[i].ans);
	}
	return 0;
}
