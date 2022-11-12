# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 +7;
const int N = 2e5 + 1;

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n; cin >> n;
	vector<bool> leaf(n+1,true),visited(n+1,false);
	vector<ll> parent(n+1);
	vector<vll> ans;

	for(ll i=1;i<=n;++i){
		ll dad; cin >> dad;
		//if(parent==i) continue;
		leaf[dad] = false;
		parent[i] = dad;
		
	}
	for(ll i=1;i<=n;++i){
		if(leaf[i]){
			vll tmp;
			tmp.pb(i);
			ll v = parent[i];
			while(!visited[v]){
				tmp.pb(v);
				visited[v] = true;
				v = parent[v];
			}
			reverse(all(tmp));
			ans.pb(tmp);
		}
	}
	if(n>1){
		cout << siz(ans) << endl;
		for(auto path : ans){
			cout << siz(path) << endl;
			for(auto node : path){
				cout << node << " ";
			}
			cout << endl;
		}
		cout << endl;
	}else{
		cout << 1 << endl << 1 << endl << 1 << endl << endl;
	}
	ans.clear();
}
