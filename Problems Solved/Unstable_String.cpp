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
	string s; cin >> s;
	s+='2';
	ll n = siz(s)-1;
	ll ans = 0;
	ll j=0;
	for(int i=0;i<n;++i){
		j++;
		if(s[i]==s[i+1]&&s[i]!='?'){
			ans+=(j+1)*j/2;
			j=0;
		}
	}
	ans+=(j+1)*j/2;
	for(int i=0;i<n;++i){
		j = i+1;
		ll qmc = 0;
		while(s[j]=='?'&&j<n){
			qmc++;
		}
		if(s[i]=='?') qmc++;
		if(j==n){
			
		}
		if(qmc%2){
			if(s[i]==s[j])
		}

	}
	deb(ans);	    
}
