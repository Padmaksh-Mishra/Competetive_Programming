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
	ll x; cin >> x;
	vll w(n);
	ll sum=0;
	for(ll i=0;i<n;++i){
		cin >> w[i];
		sum+=w[i];
	}    
	sort(all(w),greater<ll>());
	if(sum<x){
		cout << "YES" << endl;
		for(auto val : w){
			cout << val << " ";
		}
		cout << endl;
	}
	else{
		sum = 0;
		ll i=0;
		map<ll,bool> bad;
		vll gande;
		ll bs = 0;
		while(sum<x&&i<n){
			if(sum+w[i]!=x){
				sum+=w[i];
			}else bad[i] = true,gande.pb(i),bs+=w[i];
			++i;
		}
		if(sum+bs==x){
			// deb(sum);
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			for(int i=0;i<n;++i){
				if(!bad[i]) cout << w[i] << " ";
			}
			for(auto val : gande) cout << w[val] << " ";
			cout << endl;
		}
	}
}
