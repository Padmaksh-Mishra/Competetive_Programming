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
	cout.tie(NULL);
    setIO("sublime");    //Does not work with Google     
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
	ll n,q; cin >> n >> q;
	set<ll> fc,fr;
	for(ll i=1;i<=n;++i){
		fr.insert(i);
		fc.insert(i);
	}
	vector<ll> rows(n+1,0),colm(n+1,0);
	while(q--){
		ll t,x,y,xx,yy; cin >> t;
		if(t==1){
			cin >> x >> y;
			rows[x]++;
			colm[y]++;
			if(rows[x]==1&&fr.find(x)!=fr.end()) fr.erase(fr.find(x));
			if(colm[y]==1&&fc.find(y)!=fc.end()) fc.erase(fc.find(y));
		}else if(t==2){
			cin >> x >> y;
			rows[x]--;
			colm[y]--;
			if(rows[x]==0) fr.insert(x);
			if(colm[y]==0) fc.insert(y);
		}else{
			cin >> x >> y >> xx >> yy;
			if(yy>=(*fc.lower_bound(y))&&xx>=(*fr.lower_bound(x))){
				cout << "NO" << endl;
			}else{
				cout << "YES" << endl;
			}
		}
	}
}
