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
	vll arr(n);
	for(int i=0;i<n;++i) cin >> arr[i];
	vll ans;
	sort(all(arr));
	    
	for(int i=0;i<n/2;++i){
		//cout << arr[i] << " " << arr[n-i-1] << endl;
		ans.emplace_back(arr[i]);
		ans.emplace_back(arr[n-i-1]);
	}
	if(n%2) ans.emplace_back(arr[n/2]);
	ll mini = INF,maxi = -INF;
	for(int i=0;i<n;++i){
		maxi = max(maxi,ans[i]);
		mini = min(mini,ans[i]);
	}
	if(maxi==mini&&siz(arr)!=2){
		cout << -1 << endl;
		return;
	}
	for(auto val : ans){
		cout << val << " ";
	}
	cout << endl;
}
