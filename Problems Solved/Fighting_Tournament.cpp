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
const int N = 1e5 + 1;

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
	ll n,q; cin >> n >> q;
	vll a(n+1);
	ll mpi=0;
	for(int i=0;i<n;++i){
		cin >> a[i+1];
		if(a[i+1]==n){
			mpi = i+1;
		}
	}
	map<ll,vll> players;
	ll curmax = a[1];

	for(int i=2;i<=mpi;++i){
		if(a[i]>curmax){
			curmax = a[i];
		}
		players[curmax].pb(i-1);
	}    

	while(q--){
		ll pi,round; cin >> pi >> round;
		if(pi==mpi){
			cout << max(round - mpi + 2 - (mpi==1),0ll) << endl;
		}else{
			ll ans = (upper_bound(all(players[a[pi]]),round)-players[a[pi]].begin())-1;
			cout << ans+1 << endl;
		}
	}
}
