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

struct cordvll{
	vll x;
	vll y;
};
void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n,m; cin >> n >> m;
	map<ll,cordvll> mp;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			ll tmp; cin >> tmp;
			mp[tmp].x.emplace_back(i);
			mp[tmp].y.emplace_back(j);
		}
	}  
	ll sum = 0;
	for(auto color : mp){
		ll x=0,y=0,k = siz(color.s.x);
		sort(all(color.s.x));
		sort(all(color.s.y));
		for(int i=0;i<k;++i){
			x+=(2*i - k + 1)*color.s.x[i];
			y+=(2*i - k + 1)*color.s.y[i];
		}
		sum+=x+y;
	}  
	cout << sum << endl;
}
