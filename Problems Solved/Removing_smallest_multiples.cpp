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
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 
const ll bits = 1e6+2;
void solve(){
	ll n; cin >> n;
	string s; cin >> s;
	ll cost = 0;
	vector<int> taken(n+1,0);
	for(int probe=1;probe<=n;++probe){
		for(int i=probe;i<=n;i+=probe){
			if(s[i-1]=='0'){
				if(taken[i]==0) cost+=probe,taken[i] = 1;				
			} 
			else break;
		}
		// cout << "-----" << endl;
	} 
	cout << cost << endl;   
}
