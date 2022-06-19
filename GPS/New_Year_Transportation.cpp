//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
const int N = 1e5;
using namespace std;

int bexpo(int n,int p);
int visited[N];
int portal[N];
void dfs(int vertex){

	if(visited[vertex]) return;
	visited[vertex] = 1;

	dfs(vertex+portal[vertex]);
}
void solve(){
	int n,t; cin >> n >> t;
	for(int i=1;i<n+1;++i) cin >> portal[i];
	dfs(1);
	if(visited[t]) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    //cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}


//Binary Exponention Iterative
int bexpo(int n,int p){ 
    int ans = 1,tmp = n;
    while(p>0){
        if(p&1) ans = (ans * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return ans;
}
