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
	ll n,x; cin >> n >> x;
	ll cng = -1,lsb=0;
	for(int i=63;i>-1;--i){
		if((n>>i)&1){
			lsb = i;
			break;
		}
	}
	// deb(lsb);
	for(int i=63;i>-1;--i){
		if((n>>i)&1ll){
			if(((x>>i)&1ll)&&cng!=-1){
				cout << -1 << endl;
				return;
			}else if(((x>>i)&1)==0){
				if(cng==-1) cng=i;
			}
		}else if((x>>i)&1){
			cout << -1 << endl;
			return;
		}
	}
	ll ans=n;
	// deb(cng);
	if(cng!=-1){
		cng++;
		ans = (1ll<<cng);
		// deb(cng);
		// deb(lsb);
		if(cng<lsb){
			ans+=(1ll<<lsb);
		}
	}
	
	cout << ans << endl;
	// cout << (1ll<<60) <<endl;	    
}
