#include<bits/stdc++.h>
using namespace std;
int n,k;
int cmp(vector<char>&a, vector<char>&b) {
	int len = a.size();
	for(int i = 0;i<len;i++) if(a[i]!=b[i]) return a[i]-b[i];
	return 0;
}
char que[100000+10];
void get(vector<char> &a, int &b) {
	scanf("%s%d", que, &b);
	int len = strlen(que);
	a.resize(len);
	for(int i =0 ;i<len;i++) a[i] = que[i];
}
vector<int> cal(vector<int> buf) {
	sort(buf.begin(), buf.end());
	reverse(buf.begin(), buf.end());
	vector<int> ret(2);
	ret[1]+=buf[0];
	int len = buf.size();
	for(int i = 0;i<len;i+=2) {
		if(i+1<len && buf[i]+buf[i+1]>0) ret[0]+=buf[i]+buf[i+1];
		if(i+2<len && buf[i+1] + buf[i+2]>0) ret[1]+=buf[i+1]+buf[i+2];
	}
	return ret;
}
int gao(vector<int> a, vector<int> b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int ret = 0;
	int len = min(a.size(), b.size());
	for(int i = 0;i<len;i++) {
		if(a[i]+b[i] > 0) ret+=a[i]+b[i];
		else break;
	}
	return ret;
}
vector<vector<int> >ans(2);
int main(){
	scanf("%d%d",&n,&k);
	map<vector<char>, vector<int> > mat;
	for(int i = 0;i<n;i++) {
		vector<char> que(k);
		int value;
		get(que, value);
		mat[que].push_back(value);
	}
	int ind = 0;
	int ano_ans = 0;
	ans[0].resize(mat.size()+10);
	ans[1].resize(mat.size()+10);
	for(auto i=mat.begin();i!=mat.end();i++) {
		ind++;
		vector<char> fir = i->first;
		vector<char> sec = fir;
		reverse(sec.begin(), sec.end());
		int score = cmp(fir, sec);
		if(score == 0) {
			vector<int> buf = cal(i->second);
			ans[0][ind] = ans[0][ind-1]+buf[0];
			ans[1][ind] = max(ans[0][ind-1]+buf[1], ans[1][ind-1]+buf[0]);
		} else if(score < 0) ano_ans += gao(i->second, mat[sec]);
		ans[0][ind] = max(ans[0][ind-1], ans[0][ind]);
		ans[1][ind] = max(ans[1][ind-1], ans[1][ind]);
	}
	printf("%d\n", ano_ans+max(ans[0][ind], ans[1][ind]));
	return 0;
}
