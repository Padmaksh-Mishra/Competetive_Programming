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
	string s; cin >> s;
	vll o;
	vll z;
	for(int i=0;i<2*n;++i){
		if(s[i]=='1') o.emplace_back(i+1);
		else z.emplace_back(i+1);
	}	    
	if(siz(o)==0||siz(o)==2*n){
		cout << -1 << endl;
		return;
	} 
	if(siz(o)>=siz(z)){
		for(int i=0;i<n;++i) cout << o[i] << " ";
		cout << endl;
	}else{
		for(int i=0;i<n;++i) cout << z[i] << " " ;
		cout << endl;
	}
}
