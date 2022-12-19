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
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n,k; cin >> n >> k;
	vll a(k);
	map<ll,pair<ll,ll>> m;
	map<ll,ll> pos;
	m[0].f = MOD;
	m[0].s = -MOD;
	vll arr(n+1);
	for(int i=0;i<n;++i){
		m[i+1].f = m[i+1].s = i+1;
		pos[i+1] = i+1;
		arr[i+1] = i+1;
	}
	for(int i=0;i<k;++i){
		ll liked; cin >> liked;
		if(pos[liked]!=1) {
			ll tmp = arr[pos[liked]-1];
			swap(arr[pos[liked]],arr[pos[liked]-1]);
			pos[tmp]++;
			pos[liked]--;
			m[liked].f = min(m[liked].f,pos[liked]);
			m[liked].s = max(m[liked].s,pos[liked]);
			m[tmp].f = min(m[tmp].f,pos[tmp]);
			m[tmp].s = max(m[tmp].s,pos[tmp]);
		}
	}    
	for(int i=0;i<n;++i){
		cout << m[i+1].f << " " << m[i+1].s << endl;
	}
}
