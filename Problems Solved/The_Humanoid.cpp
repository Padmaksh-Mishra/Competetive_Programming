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
	ll n,h; cin >> n >> h;
	vll a(n+1);
	for(int i=0;i<n;++i){
		cin >> a[i+1];
	}	    
	sort(all(a));
	ll i;
	n++;
	for(i=1;i<n;++i){
		if(h<=a[i]){
			i--;
			break;
		}
		h+=(a[i]>>1);
	}
	ll ans = 0;
	ll sum223 = h*2,sum232 = h*2,sum322 = h*3; 
	ll j;
	for(j=i+1;j<n;++j){
		if(sum223<=a[j]){
			j--;
			break;
		}
		sum223+=(a[j]>>1);
	}
	sum223*=2;

	for(;j<n;++j){
		if(sum223<=a[j]){
			j--;
			break;
		}
		sum223+=(a[j]>>1);
	}
	sum223*=3;
	for(;j<n;++j){
		if(sum223<=a[j]){
			j--;
			break;
		}
		sum223+=(a[j]>>1);
	}
	ans = max(ans,j);
	for(j=i+1;j<n;++j){
		if(sum232<=a[j]){
			j--;
			break;
		}
		sum232+=(a[j]>>1);
	}
	sum232*=3;
	for(;j<n;++j){
		if(sum232<=a[j]){
			j--;
			break;
		}
		sum232+=(a[j]>>1);
	}
	sum232*=2;
	for(;j<n;++j){
		if(sum232<=a[j]){
			j--;
			break;
		}
		sum232+=(a[j]>>1);
	}
	ans = max(ans,j);

	for(j=i+1;j<n;++j){
		if(sum322<=a[j]){
			j--;
			break;
		}
		sum232+=(a[j]>>1);
	}
	sum322*=2;
	for(;j<n;++j){
		if(sum322<=a[j]){
			j--;
			break;
		}
		sum232+=(a[j]>>1);
	}
	sum322*=2;
	for(;j<n;++j){
		if(sum232<=a[j]){
			j--;
			break;
		}
		sum322+=(a[j]>>1);
	}
	if(max(sum322,max(sum232,sum223))<=a[1]) cout << 0 << endl;
	else cout << min(max(j,ans),n-1) << endl;
}
