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
	string s,t; cin >> s >> t;
	cin >> s >> t;
	ll n = siz(s);
	ll m = siz(t);
	string sp = s.substr(0,m);
	string ss = s.substr(n-m);
	vll p(m),sx(m);
	for(int i=0;i<m;++i){
		p[i] = (t[i]==sp[i]||t[i]=='?'||sp[i]=='?');
		sx[i] = (t[i]==ss[i]||t[i]=='?'||ss[i]=='?');
	}	    
	vll prfp(m+1),sufs(m+1);
	prfp[0]=0;
	for(int i=1;i<m+1;++i){
		prfp[i] = prfp[i-1] + p[i-1];
	}
	sufs[m] = 0;
	for(int i=m-1;i>-1;--i){
		sufs[i] = sufs[i+1] + sx[i];
	}
	// deb(sp);
	// for(auto val : prfp){
	// 	cout << val << " ";
	// }
	// cout << endl;
	// deb(ss);
	// for(auto val : sufs){
	// 	cout << val << " ";
	// }
	// cout << endl;
	for(int i=0;i<m+1;++i){
		if(prfp[i]+sufs[i]==m){
			cout << "Yes" << endl;
		}else cout << "No" << endl;
	}
}
