#include <bits/stdc++.h>
# define s second
# define f first
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> values(n);
    for(int i=0;i<n;++i) cin >> values[i];
    vector<vector<int>> tree(n,vector<int>());
    for(int i=0;i<n-1;++i){
        int a,b; cin >> a >> b;
        a--,b--;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    vector<int> occs(100005);
    long long ans = 0;
    function<void(int,int,pair<int,int>,int)> dfs = [&](int v,int p,pair<int,int> val,int len){
        occs[values[v]]++;
        if(max(occs[values[v]],val.s)*2>len){
            ans++;
        }
        for(auto c : tree[v]){
            if(c==p) continue;
            pair<int,int> tmp = make_pair(val.f,val.s);
            if(occs[v]>val.s) tmp.s = occs[values[v]],tmp.f = v;
            dfs(c,v,tmp,len+1);
        } 
        occs[values[v]]--;                   
    };
    dfs(0,-1,{0,0},0);
    cout << ans << endl;
}





int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}