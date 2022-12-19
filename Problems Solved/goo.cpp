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

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

void solve(){
	ll n; cin >> n;
	vll arr(n),ps(n+1,0);
    ll ans = 0;
	for(int i=0;i<n;++i) {
        cin >> arr[i];
        ps[i+1] = ps[i] + arr[i];
        // cout << ps[i] << " ";
    }
    // cout << endl;
    for(int i=0;i<=n;++i){
        for(int j=1;j<=n;++j){
            ll tmp = ps[j]-ps[i];
            if(i>j) continue;
            if(tmp>=0) {
                ans+=tmp;
                // cout << j << ' ' << i  << " " << tmp << endl;
            }else break;
        }
    }
    cout << ans << endl;
}
