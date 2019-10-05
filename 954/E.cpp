#include<bits/stdc++.h>
using namespace std;
int n,t;
struct water {
	int t;
	int cnt;
	water(int _t,int _cnt):t(_t),cnt(_cnt){}
};
vector<water> l,r;
double cal(vector<water>&buf, double sum) {
	double ret = 0;
	for(auto i: buf) {
		if(sum < 1e-10)  break;
		double cnt = min(1.0*i.cnt, sum/i.t);
		ret += cnt;
		sum -= cnt*i.t;
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&t);
	vector<int> a(n), tem(n);
	for(int i = 0;i<n;i++) scanf("%d",&a[i]);
	for(int i = 0;i<n;i++) scanf("%d",&tem[i]);
	double ans = 0;
	double lsum = 0,rsum = 0;
	for(int i = 0;i<n;i++) {
		if(tem[i]<t) l.emplace_back(t-tem[i],a[i]), lsum+=1.0*a[i]*(t-tem[i]);
		else if(tem[i]==t) ans+=a[i];
		else r.emplace_back(tem[i]-t,a[i]), rsum+=1.0*a[i]*(tem[i]-t);
	}
	sort(l.begin(), l.end(), [&](water a,water b)->bool{return a.t<b.t;});
	sort(r.begin(), r.end(), [&](water a,water b)->bool{return a.t<b.t;});
	lsum = rsum = min(lsum,rsum);
	ans+=cal(l, lsum);
	ans+=cal(r, rsum);
	printf("%.12f\n", ans);
	return 0;
}
