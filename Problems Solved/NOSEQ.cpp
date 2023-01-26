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
	ll n,k,s,ss; cin >> n >> k >> s;
	ss=s;
	vll ans(n);
	for(int i=0;i<n;++i){
		if(s%k==0){
			ans[i]=0;
		}else if(s%k==1){
			s--;
			ans[i]=1;
		}else if(s%k==k-1){
			ans[i] = -1;
			s++;
		}
		s/=k;
	}
	ll a = ans[0];
	ll m = k;
	for(int i=1;i<n&&a<ss;++i){
		a+=(m*ans[i]);
		m*=k;
	}
	if(a!=ss){
		cout << -2 << endl;
		return;
	}
	for(auto val : ans){
		cout << val << " ";
	}	    
	cout << endl;
}
