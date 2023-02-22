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
	ll n,k; cin >> n >> k;
	char mcm = 'a';
	char l = 0;
	char r = 0;
	string s; cin >> s;
	for(int i=0;i<n;++i){
		// deb(mcm);
		if(s[i]<=mcm){
			s[i] = 'a';
		}else if(k>0){
			ll diff = s[i]-mcm;

			if(diff<=k){
				mcm = s[i];
				s[i] = 'a';
				k-=diff;
			}else{
				r = s[i];
				s[i]-=k;
				l = s[i];
				k=0;
			}
		}
	}
	for(int i=0;i<n;++i){
		if(s[i]<=r&&s[i]>=l){
			s[i] = min(s[i],l);
		}
	}	
		    
	cout << s << endl;
}
