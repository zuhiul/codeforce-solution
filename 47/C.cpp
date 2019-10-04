#include<bits/stdc++.h>
using namespace std;
string que[19];
int len[10];
vector<int>num;
vector<vector<char> > ans;
vector<vector<char> > buf;
bool debug() {
	int DEBUG[] = {1,4,2,5,3,0};
	for(int i = 0;i<6;i++) {
		if(num[i] != DEBUG[i]) return false;
	}
	return true;
}
bool check() {
	if(que[num[0]][0] != que[num[3]][0]) return false;
	if(que[num[0]][len[num[0]]-1] != que[num[4]][0]) return false;
	if(que[num[3]][len[num[3]]-1] != que[num[1]][0]) return false;
	if(que[num[1]][len[num[1]]-1] != que[num[5]][0]) return false;
	if(que[num[2]][0] != que[num[4]][len[num[4]]-1]) return false;
	if(que[num[2]][len[num[2]]-1] != que[num[5]][len[num[5]]-1]) return false;

	if(len[num[0]]+len[num[2]]-1 != len[num[1]]) return false;
	if(len[num[3]]+len[num[5]]-1 != len[num[4]]) return false;

	if(que[num[1]][len[num[0]]-1] != que[num[4]][len[num[3]]-1]) return false;
	return true;
}
void load() {
	buf.resize(len[num[4]]);
	for(int i = 0;i<len[num[4]];i++) {
		buf[i].resize(len[num[1]]);
		for(int j = 0;j<len[num[1]];j++) {
			buf[i][j] = '.';
		}
	}
	for(int i = 0;i<len[num[0]];i++) buf[0][i] = que[num[0]][i];
	for(int i = 0;i<len[num[1]];i++) buf[len[num[3]]-1][i] = que[num[1]][i];
	for(int i = len[num[0]]-1;i<len[num[1]];i++) buf[len[num[4]]-1][i] = que[num[2]][i-len[num[0]]+1];
	for(int i = 0;i<len[num[3]];i++) buf[i][0] = que[num[3]][i];
	for(int i = 0;i<len[num[4]];i++) buf[i][len[num[0]]-1] = que[num[4]][i];
	for(int i = len[num[3]]-1;i<len[num[4]];i++) buf[i][len[num[1]]-1] = que[num[5]][i-len[num[3]]+1];
}
int row_cmp(vector<char>&a, vector<char>&b) {
	int len = min(a.size(), b.size());
	for(int i = 0;i<len;i++) {
		if(a[i]!=b[i]) return a[i]-b[i];
	}
	return a.size() - b.size();
}
bool cmp() {
	int row_len = min(ans.size(),buf.size());
	for(int i = 0;i<row_len;i++) {
		int val = row_cmp(ans[i],buf[i]);
		if(val > 0) return true;
		else if(val < 0) return false;
	}
	return ans.size() < buf.size();
}
void show_ans() {
	for(int i = 0;i<ans.size();i++) {
		for(int j = 0;j<ans[i].size();j++) {
			putchar(ans[i][j]);
		}
		putchar('\n');
	}
}
int main(){
	ans.resize(33);
	for(int i = 0;i<33;i++) {
		ans[i].resize(33);
		for(int j = 0;j<33;j++) ans[i][j] = 'z';
	}
	for(int i = 0;i<6;i++) {
		num.push_back(i);
		cin>>que[i];	
		len[i] = que[i].length();
	}
	bool has_ans = false;
	do {
		if(check()) load();
		if(cmp()) ans = buf, has_ans = true;
	} while(next_permutation(num.begin(),num.end()));
	if(has_ans) show_ans();
	else puts("Impossible");
	return 0;
}
