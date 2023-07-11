#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> v;
    char lc; cin >> lc;
    int cnt = 1;
    for(int i=1;i<n;++i){
        char tmp; cin >> tmp;
        if(tmp==lc) cnt++;
        else v.emplace_back(cnt),cnt=1,lc=tmp;
    }
    v.emplace_back(cnt);
    int k = v.size();
    vector<vector<int>> dp(k+1,vector<int>(n+1,0));
    dp[0][0] = 1;
    for(int i=0;i<k;++i){
        for(int j=0;j<n;++j){
            if(j+v[i]<n+1) dp[i+1][j+v[i]]|=dp[i][j];
            if(j-v[i]>-1) dp[i+1][j-v[i]]|=dp[i][j];
        }
    }
    if(dp[k][0]){
        cout << "YES" << endl;
        string ans = "";
        int i = k;
        int j = 0;
        while(i>0){
            if(dp[i-1][j+v[i-1]]) for(int x=0;x<v[i-1];++x) ans+=')',j++;
            else if(j>v[i-1]-1&&dp[i-1][j-v[i-1]]) for(int x=0;x<v[i-1];++x) ans+='(',j--;
            i--;
        }
        reverse(ans.begin(),ans.end());
        cout << ans << endl;
    }else cout << "NO" << endl;
}

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    solve();
	}
	return 0;
}
