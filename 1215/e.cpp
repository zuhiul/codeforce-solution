//
//@Birth:created by zuhiul on 2019-09-16
//@Solution:https://zuhiul.github.io/2019/09/16/CF_1215_E/#more
//
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int n;
const int maxm = 1e6;
const long long inf = 1e18;
vector<long long> mat[22];
long long value[22][22];
long long ans[1<<21];
int main(){
    scanf("%d",&n);
    for(int i = 0, a;i<n;i++) {
        scanf("%d",&a);
        mat[a].push_back(i);
    }
    for(int i = 0;i<=20;i++) mat[i].push_back(maxm<<1);
    for(int i = 1;i<=20;i++) {
        if(mat[i].size()==0) continue;
        for(int j = 1;j<=20;j++) {
            if(mat[j].size()==0||i==j) continue;
            long long ind1 = 0;
            for(auto ind : mat[j]) {
                if(ind > maxm) continue;
                while(ind > mat[i][ind1]) ind1++;
                value[i-1][j-1] += ind1;
            }
        }
    }
    for(int i = 0;i<(1<<20);i++) ans[i] = inf;
    ans[0] = 0;
    for(int mask = 0;mask<(1<<20);mask++) {
        vector<int> has_bit;
        for(int i = 0;i<20;i++) if(mask&(1<<i)) has_bit.push_back(i);
        for(int i = 0;i<20;i++){
            if(mask&(1<<i)) continue;
            long long sum = 0;
            for(int j = 0;j<has_bit.size();j++) sum+=value[i][has_bit[j]];
            int nmask = mask|(1<<i);
            ans[nmask] = min(ans[nmask], ans[mask]+sum);
        }
    }
    printf("%lld\n", ans[(1<<20)-1]);
    return 0;
}


