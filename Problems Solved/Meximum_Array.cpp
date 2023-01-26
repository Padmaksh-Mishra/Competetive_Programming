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
	ll n; cin >> n;
	vll a(n);
	ll maxx = -1;
	for(int i=0;i<n;++i){
		cin >> a[i];
		maxx = max(a[i],maxx);
	}	    
	vll hsh(maxx+2,0);
	ll mex = 0;
	for(int i=0;i<n;++i){
		hsh[a[i]]++;
		while(hsh[mex]!=0){
			mex++;
		}
	}
	ll fullmex = mex;
	vll prfmex(n+1);
	prfmex[0] = fullmex;
	for(int i=0;i<n;++i){
		hsh[a[i]]--;
		// deb(hsh[a[i]]);
		if(hsh[a[i]]==0&&a[i]<mex){
			mex = a[i];
		}
		prfmex[i+1] = mex;
	}
	// for(auto val : prfmex){
	// 	cout << val << " ";
	// }
	// cout << endl;
	ll tgtmex = fullmex;
	mex = 0;
	vll ans;
	for(int i=0;i<n;++i){
		hsh[a[i]]++;
		while(hsh[mex]!=0){
			mex++;
		}
		if(mex==tgtmex){
			ans.emplace_back(mex);
			mex=0;
			fill(all(hsh),0);
			tgtmex = prfmex[i+1];
		}
	}

	cout << siz(ans) << endl;
	for(auto val : ans){
		cout << val << " ";
	}
	cout << endl;
}
