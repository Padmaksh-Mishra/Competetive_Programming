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
bool prime[1000005];
vll p;
vll primes;
vll vis(400000);

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google     
    for(int i=2;i<=34000;i++){
		if(!vis[i]){
			p.push_back(i);
			for(int j=i;j<=34000;j+=i)vis[j]=1;
		}
	}
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
	map<ll,ll> hsh;
	vll v(n);
	for(int i=0;i<n;++i){
		cin >> v[i];
	}
	for(int i=0;i<n;++i){
		ll tmp = v[i];
		for(auto val : p){
			if(tmp%val==0){
				if(hsh[val]==1){
					cout << "YES" << endl;
					return;
				}
				//deb(val);
				hsh[val]=1;
				while(tmp%val==0){
					tmp/=val;
				}
			}
		}
		if(tmp>1&&hsh[tmp]){
			cout << "YES" << endl;
			return;
		}else hsh[tmp]=1;
	}
	cout << "NO" << endl;
}
