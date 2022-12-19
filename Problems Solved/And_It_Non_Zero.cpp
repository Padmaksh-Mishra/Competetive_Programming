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
long long getcount(long long n, int k)
{
    // Store count till nearest
    // power of 2 less than N
    long long res = (n >> (k + 1)) << k;
 
    // If K-th bit is set in N
    if ((n >> k) & 1)
 
        // Add to result the nearest
        // power of 2 less than N
        res += n & ((1ll << k) - 1);
 
    // Return result
    return res;
}
void solve(){
	int l,r; cin >> l >> r;
	int ans = -200009;
	for(int i=0;i<18;++i){
		int tmp = getcount(r+1,i) - getcount(l,i);
		ans = max(ans,tmp);
	}	    
	cout << r-l+1 - ans << endl;
}








