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

void solve(){
	cout << "YES" << endl;
	ll n,m,x; cin >> n >> m >> x;
	vll h(n);
	for(int i=0;i<n;++i) cin >> h[i];
	// sort(all(h));
	set<pair<ll,ll>> s;
	int i;
	for(i=0;i<m;++i){
		s.insert(make_pair(h[i],i));
		cout << i+1 << " ";
	}
	m = n-m;
	while(m--){
		pair<ll,ll> p = *s.begin();
		p.f+=h[i];
		cout << p.s+1 << " ";
		s.erase(s.begin());
		s.insert(p);	//note set sirf insertion pe sort karta hai 
						//agar inserted wale ki value badal diye to kuch nahi hota
		i++;
	}
	cout << endl;

}
