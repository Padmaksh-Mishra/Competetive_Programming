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
	ll k,n; cin >> n >> k;
	string s; cin >> s;
	ll ans = 0;
	//cout << s << endl;
	for(int i=0;i<n;++i){
		if(s[i]=='0'){
			ll tmp = 0;
			bool lb = false,rb = false;
			if(i>0&&s[i-1]=='1') lb = true;
			while(i<n&&s[i]=='0'){
				i++;
				tmp++;
			}
			if(i<n&&s[i]=='1') rb = true;
			// deb(tmp);
			tmp -= (k*lb + k*rb);
			// deb(tmp);
			if(tmp<=0) continue;
			ans+= (tmp/(k+1)) + (tmp%(k+1)!=0);
		}
	}
	//cout << endl;
	// cout << s << endl;
	cout << ans << endl;
}
