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
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
	
	return ((x.f*0.1/x.s)<(y.f*0.1/y.s));
}
void solve(){
	ll n; cin >> n;
	vector<pair<ll,ll>> v;
	vll arra(n),arrb(n);
	for(int i=0;i<n;++i) cin >> arra[i];
	for(int i=0;i<n;++i) cin >> arrb[i];
	for(int i=0;i<n;++i){
		ll a=arra[i],b=arrb[i];
		v.emplace_back(make_pair(b,a));
	}    
	sort(all(v),cmp);
	ll dist = 0;
	ll beauty = 0;
	for(auto val : v){
		beauty += (dist*val.f);
		dist+=val.s;
	}
	cout << beauty << endl;
}
