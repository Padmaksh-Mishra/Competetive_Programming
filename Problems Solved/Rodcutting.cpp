#include <bits/stdc++.h>
using namespace std;
const int N = 1001;

int cost[N];
int price[N];
int main(){
	int n; cin >> n;
	for(int i=0;i<n;++i){
		cin >> price[i+1];
	}
	for(int i=1;i<=n;++i){
		for(int k=0;k<=i;k++){
			cost[i] = max(cost[i],price[k]+cost[i-k]);
		}
	}
	cout << cost[n] << endl;
	return 0;

}