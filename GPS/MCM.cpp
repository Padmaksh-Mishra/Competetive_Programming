#include <bits/stdc++.h>
using namespace std;
const int N = 101;

int cost[N][N];
int arr[N];

int main(){
	int n; cin >> n;	//n number of dimensions means n-1 rows

	for(int i=0;i<n;++i){
		cin >> arr[i];
	}

	for(int d=1;d<n-1;++d){
		for(int i=1;i<=n-d;++i){
			// cout << i << endl;
			int j = i+d;
			int mini = 1e9;
			for(int k=i;k<j;++k){
				mini = min(mini,cost[i][k]+cost[k+1][j]+(arr[i-1]*arr[k]*arr[j]));
				// cout << i << " " << j << " " << k << " " << mini << endl;
			}
			cost[i][j] = mini;
		}
	}
	cout << cost[1][n-1] << endl;
	return 0;

}