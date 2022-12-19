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
	unordered_set<ll> 
	for(int i=0;i<n;++i){
		cin >> valy[i];
	}
	ll goodi,goodj;
	for(int i=1;i<n-1;++i){
		if(valy[i]<valy[i+1]&&valy[i-1]>=valy[i]){
			goodi = i;
			break;
		}
	}
	for(int i=n-2;i>=0;--i){
		if(valy[i]<valy[i-1]&&valy[i+1]>=valy[i]){
			goodj = i;
			break;
		}
	}
	if(goodj==goodi) cout << "YES" << endl;
	else {
		if(valy[goodj]==valy[goodi]){
			for(int i=goodi;i<goodj;++i){
				if(valy[i]!=valy[goodj]){
					cout << "NO" << endl;
					return;
				}
			}
			cout << "YES" << endl;
		}else cout << "NO" << endl;
	}
}
