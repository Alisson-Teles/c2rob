#include<stdio.h>
#include<stdbool.h>
#include<math.h>

#define rep(i,n) for(int i = 0; i < n; i++)


int main(void){
	int n, m, x;
	int a[13][14];
	int c = 0;
	int ans = 0;
	int t[13];
	int INF = 1000000000;

	scanf("%d %d %d", &n, &m, &x);

	rep(i,n){
		rep(j,m+1){
			scanf("%d", &a[i][j]);
		}
	}

	int min = INF;


	rep(j,pow(2,n)){

		int u[13] = {0};
		int cost = 0;

		rep(i,n){
			t[i] = (j>>i) & 1;
		}
		rep(i,n){
			if(t[i]) 
				cost += a[i][0];
		}

		rep(i,n){
			rep(k,m){
				if(t[i])
				u[k] += a[i][k+1];
			}
		}

		bool ok = true;

		rep(i,m){
			if(u[i] < x){
				ok = false;
			} 
		}

		if(ok && cost < min){
			min = cost;
		}

	}

	if(min == INF)
		ans = -1;
	else
		ans = min;

	printf("%d", ans);

	return 0;
}