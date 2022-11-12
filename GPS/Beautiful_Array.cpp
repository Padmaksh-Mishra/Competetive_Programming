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
	ll n,k,b,s; cin >> n >> k >> b >> s;
	ll tmp = floor(b/n);
	if(b*k>s||(k*b)+(k-1)*n<s){
		cout << -1 << endl;
	}
	else{
		vll ans(n,tmp);
		ll t = b%n;
		for(int i=0;i<t;++i) ans[i]++;
		sort(all(ans));
		ll sum = 0;
		for(int i = 0;i<n;++i){
			ans[i]*=k;
			sum+=ans[i];
			// cout << ans[i] << " ";
		}
		// cout << endl;
		ll sub = s-sum;
		// deb(sub);
		for(int i = 0;i<n&&sub>0;++i){
			ll tx = min(sub,k-1);
			// deb(tx);
			sub-=tx;
			ans[i]+=tx;
		}
		// ll sdf=0;
		for(auto val : ans) {
			// sdf+=val;
			cout << val << " ";
		}
		cout << endl;
		// cout << sdf << endl;
	}    
}
