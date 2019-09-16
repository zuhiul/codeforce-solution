#include<bits/stdc++.h>
using namespace std; int n;
void NO() {
	puts("Monocarp");
	exit(0);
}
int main(){
	scanf("%d",&n);
	int lsum = 0, rsum =0;
	int lun = 0, run = 0;
	for(int i = 0;i*2<n;i++) {
		char a;
		scanf(" %c",&a);
		if(a=='?') lun++;
		else lsum += a - '0';
	}

	for(int i = 0;i*2<n;i++) {
		char a;
		scanf(" %c",&a);
		if(a=='?') run++;
		else rsum += a - '0';
	}

	//cout<<lun<<' '<<run<<' '<<lsum<<' '<<rsum<<endl;

	if(lun == run) {
		if(lsum!=rsum) {
			//cout<<'0'<<endl;
			puts("Monocarp");
			return 0;
		} else {
			puts("Bicarp");
			return 0;
		}
	}
	else {
		int cao = (lun+run)>>1;
		int lmax = (lun+1)>>1;
		int rmax = (run+1)>>1;
		
		int maxl_l_sum = lmax*9 + lsum;
		int maxl_r_sum = rsum;
		if(maxl_l_sum > maxl_r_sum) {
			int buf = maxl_l_sum - maxl_r_sum;
			if(buf > (run - (cao - lmax))*9) {
				//cout<<'1'<<endl;
				NO();
			}
		}

		int maxr_r_sum = rmax*9 + rsum;
		int maxr_l_sum = lsum;
		if(maxr_r_sum > maxr_l_sum) {
			int buf = maxr_r_sum - maxr_l_sum;
			if(buf > (lun - (cao - rmax))*9) {
				//cout<<'2'<<endl;
				NO();
			}
		}

		int minl_l_sum = lsum;
		int minl_r_sum = rsum + (cao - lmax)*9;
		if(minl_l_sum < minl_r_sum) {
			int buf = minl_r_sum - minl_l_sum;
			if(buf > (lun - lmax)*9) {
				//cout<<'3'<<endl;
				NO();
			}
		}
		
		int minr_r_sum = rsum;
		int minr_l_sum = lsum + (cao - rmax)*9;
		if(minr_r_sum < minr_l_sum) {
			int buf = minr_l_sum - minr_r_sum;
			if(buf > (run - rmax)*9) {
				//cout<<'4'<<endl;
				NO();
			}
		}
	}
	puts("Bicarp");
	return 0;
}
