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

void solve(){
	ll n; cin >> n;
	vll ips(n);
	for(int i=0;i<n;++i){
		cin >> ips[i];
	}    
	for(int k=n;k>=0;--k){
		multiset<ll> ms(all(ips));
		for(int i = 1;i<=k;++i){
			auto it = ms.upper_bound(k-i+1);
			if(it==ms.begin()) break;
			else ms.erase(--it);
			if(ms.size()>0){
				ll x = *ms.begin();
				ms.erase(ms.begin());
				ms.insert(x+k-i+1);	
			}
		} 
		if(siz(ms)+k==n){
			cout << k << endl;
			return;
		}
	}
}
