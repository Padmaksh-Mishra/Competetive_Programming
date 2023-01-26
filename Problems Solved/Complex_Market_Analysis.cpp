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

vector<bool> is_prime(1000001, true);

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google  
    is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= 1000000; i++) {
	    if (is_prime[i]) {
	        for (int j = i * i; j <= 1000000; j += i)
	            is_prime[j] = false;
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
	ll n,e; cin >> n >> e;
	vll a(n);
	for(int i=0;i<n;++i){
		cin >> a[i];
	}	    
	vll v[e];
	for(int i=0;i<e;++i){
		ll ones = 0;
		for(int j=i;j<n;j+=e){
			if(a[j]==1) ones++;
			else{
				v[i].emplace_back(ones);
				if(is_prime[a[j]]){
					v[i].emplace_back(-1);
				}else{
					v[i].emplace_back(-2);
				}
				ones=0;
			}
		}
		v[i].emplace_back(ones);
	}
	ll ans = 0;
	
	for(int i=0;i<e;++i){
		if(v[i][0]==-1&&siz(v[i])>1) ans+=(max(v[i][1],0ll));
		for(int j=1;j<siz(v[i])-1;++j){
			if(v[i][j]!=-1) continue;
			else{
				ll tmp = 0;
				if(v[i][j-1]>0) tmp+=v[i][j-1];
				if(v[i][j+1]>0) tmp+=v[i][j+1];
				if(v[i][j-1]>0&&v[i][j+1]>0){
					tmp+=(v[i][j-1]*v[i][j+1]);
					// cout << v[i][j-1] << " " << v[i][j+1] << endl;
				}
				ans+=tmp;
			} 
		}
		if(siz(v[i])>1) ans+=max(0ll,v[i][siz(v[i])-2]);
	}
	cout << ans << endl;
}
