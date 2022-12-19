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
	ll a,b,c; cin >> a >> b >> c;
	ll m; cin >> m;
	vector<pll> v;
	for(int i=0;i<m;++i){
		ll tmp; cin >> tmp;
		string s; cin >> s;
		if(s=="USB"){
			v.emplace_back(make_pair(tmp,1));
		}else v.emplace_back(make_pair(tmp,0));
	}	    
	ll ans=0,comp=0;
	sort(all(v));
	for(int i=0;i<m;++i){
		if(v[i].s){
			if(a){
				ans+=v[i].f;
				comp++;
				a--;
			}else if(c){
				ans+=v[i].f;
				comp++;
				c--;
			}
		}else{
			if(b){
				ans+=v[i].f;
				comp++;
				b--;
			}else if(c){
				ans+=v[i].f;
				comp++;
				c--;
			}
		}
		if(a+b+c==0) break;
	}
	cout << comp << " " << ans << endl;
}
