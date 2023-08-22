# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
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
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n,m; cin >> n >> m;
	vll weaker(n+1),edges(n+1);
	while(m--){
		ll a,b; cin >> a >> b;
		weaker[a]+=(a>b);
		weaker[b]+=(b>a);
		edges[a]++;
		edges[b]++;
	}	    
	ll ans = 0;
	for(int i=1;i<n+1;++i){
		ans+=(weaker[i]==edges[i]);
	}
	// cout << ans << endl;
	ll q; cin >> q;
	while(q--){
		ll t; cin >> t;
		if(t==3){
			cout << ans << endl;
		}else{
			ll a,b; cin >> a >> b;
			if(t==1){
				ans-=(weaker[a]==edges[a])+(weaker[b]==edges[b]);
				weaker[a]+=(a>b);
				weaker[b]+=(b>a);
				edges[a]++;
				edges[b]++;	
				ans+=(weaker[a]==edges[a])+(weaker[b]==edges[b]);
			}else{
				ans-=(weaker[a]==edges[a])+(weaker[b]==edges[b]);
				weaker[a]-=(a>b);
				weaker[b]-=(b>a);
				edges[a]--;
				edges[b]--;	
				ans+=(weaker[a]==edges[a])+(weaker[b]==edges[b]);
			}
		}
	}
}