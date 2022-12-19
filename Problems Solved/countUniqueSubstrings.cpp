# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll len = 2*1e5;
ll p[len];
ll prefix[len+1];
ll inv[len];
ll n;
string s;

void powp();
void stringHash();
void solve();
ll binexpo(ll n, ll p);

int count_unique_substrings(string const& s) {   //cp-algorithms wala
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}


int main(){
	powp();
	ll tc; cin >> tc;
	while(tc--){
		solve();
	}
	return 0;
}

void solve(){
	cin >> n >> s;
	stringHash();
	set<ll> uniq;
	for(ll i = 1;i<=n;i++){
		for(ll j = i;j<=n;j++){
			ll curr_hsh = ((prefix[j] - prefix[i-1]) * 1LL * inv[i-1]) % MOD;
			uniq.insert(curr_hsh);
		}
	}
	cout << uniq.size() << endl;
	cout << count_unique_substrings(s) << endl;
}

void powp(){
	p[0] = 31;
	inv[0] = binexpo(p[0],MOD-2);
	for(ll i=1;i<len;i++){
		p[i] = (p[i-1] * 1LL * 31) % MOD;
		inv[i] = binexpo(p[i],MOD-2);
	} 
	return;
}

void stringHash(){
	prefix[0] = 0;
	prefix[1] = ((s[0] - 'a' + 1) * p[0])%MOD;
	for(ll i=1;i<n+1;i++){
		prefix[i+1] =  (prefix[i] + (s[i] - 'a' + 1) * p[i])%MOD;
	}
	return;
}

ll binexpo(ll n,ll p){ 
    ll ans = 1,tmp = n;
    while(p>0){
        if(p&1) ans = (ans * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return ans;
}