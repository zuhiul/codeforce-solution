#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iostream>

int a;
int mask;
int get[400];
int to[400][10];

void init() {
    get[0] = 1;
    to[0][++to[0][0]] = 0;
    for (int i = 0; i < 300; i++) {
        int x = i;
        while (x) {
            get[i] |= (1 << (x % 10));
            to[i][++to[i][0]] = x % 10;
            x /= 10;
        }
    }
}
int buf[20];

bool check(int a, int b, int c, int d) {
    int nouse = get[a] | get[b] | get[c] | get[d];
    if (nouse != mask) return false;
    buf[0] = 0;
    int len = 0;

    for (int i = to[a][0]; i >= 1; i--) buf[len++] = to[a][i];
    for (int i = to[b][0]; i >= 1; i--) buf[len++] = to[b][i];
    for (int i = to[c][0]; i >= 1; i--) buf[len++] = to[c][i];
    for (int i = to[d][0]; i >= 1; i--) buf[len++] = to[d][i];

    for (int i = 0; i < len>>1; i++) {
        if (buf[i] != buf[len - i - 1]) return false;
    }
    return true;
}

int ans_list[100000][4];
int good[1000];

void solve() {
    for (int i = 0; i <= 255; i++) {
        int buf = get[i];
        if ((buf & mask) == buf) good[i] = true;
    }

    int ans = 0;
    std::vector<int> buf(4);
    for(int i = 0;i<256;i++) {
        if(!good[i]) continue;
        for(int j = 0;j<256;j++) {
            if(!good[j]) continue;
            for(int k = 0;k<256;k++) {
                if(!good[k]) continue;
                for(int l = 0;l<256;l++) {
                    if(!good[l]) continue;
                    if(check(i,j,k,l)) {
                        ans_list[ans][0] = i;
                        ans_list[ans][1] = j;
                        ans_list[ans][2] = k;
                        ans_list[ans++][3] = l;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++)
        printf("%d.%d.%d.%d\n", ans_list[i][0], ans_list[i][1], ans_list[i][2], ans_list[i][3]);
}

int main() {
    init();
    scanf("%d", &a);

    if (a > 6) {
        puts("0");
        return 0;
    }
    while (a--) {
        int b;
        scanf("%d", &b);
        mask |= (1 << b);
    }

    solve();
    return 0;
}
