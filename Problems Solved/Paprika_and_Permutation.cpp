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
	vll arr(n+1);
	arr[0] = -INF;
	ll ans = 0;
	for(int i=1;i<=n;++i) cin >> arr[i];
	sort(arr.begin(),arr.end());
	vector<bool> v(n+1,false);
	ll j = 1;
	multiset<int> s;
	for(int i=1;i<=n;++i){
		if(arr[i]<=n&&!v[arr[i]]) v[arr[i]] = true;
		else s.insert(arr[i]);
	}	    
	
	for(int i=1;i<=n;++i){
		if(!v[i]){
			if(i<((*s.begin())+1)/2){
				ans++;
				s.erase(s.begin());
			}else {
				cout << -1 << endl;
				return;
			}
		}
	}
	cout << ans << endl;
}
