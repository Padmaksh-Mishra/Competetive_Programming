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
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	vll hsh(26);
	ll n,k; cin >> n >> k;
	string s; cin >> s;
	for(int i=0;i<n;++i){
		hsh[s[i]-'a']++;
	}	    
	ll sing = 0;
	ll prs = 0;
	for(int i=0;i<26;++i){
		prs += (hsh[i]/2);
		sing += (hsh[i]%2);
	}
	ll minlen = 2*(prs/k);
	sing+=2*(prs%k);
	if(k<=sing){
		minlen++;
	}
	cout << minlen << endl;
}
