# include <bits/stdc++.h>
# define f first
# define s second
# define int long long
using namespace std;
vector<int> dp[101];
int32_t main(){
	int N,W; cin >> N >> W;
	vector<int> w(N+1,0),p(N+1,0);
	vector<pair<int,int>> v;
	for(int i=0;i<N;++i){
		int x,y; cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end());
	for(int i=0;i<N;++i){
		w[i+1]=v[i].f;
		p[i+1]=v[i].s;
	}
	for(int i=0;i<=N;++i){
		for(int j=0;j<=W;++j){
			if(i==0||j==0){
				dp[i].push_back(0);
			}
			else if(w[i]<=j){
				dp[i].push_back(max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]));
				
			}else{
				dp[i].push_back(dp[i-1][j]);
			}
		}	

	}
	cout << dp[N][W] << endl;
	return 0;
}