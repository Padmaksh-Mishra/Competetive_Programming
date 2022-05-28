# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll len = 1e6;
ll p[len];
ll prefix[len+1];
ll inv[len];
ll n;
string s;
ll anshash;
bool ans = false;

void powp();
void stringHash();
void solve();
ll binexpo(ll n, ll p);

bool probe(int l){
	bool possible = false;
	for(int i = 1;i<=n-l-1;i++){
		ll curhash = ((prefix[i+l] - prefix[i] + MOD)*inv[i-1])%MOD;
		if(curhash==anshash){
			return true;
		}
	}
	return false;
}


int main(){
	powp();
	solve();
	return 0;
}

void solve(){
	cin >> s;
	n = s.length();
	stringHash();
	int bl = n/3;

	for(int i = n;i>0;i--){
		ll p1 = prefix[i];
		ll p2 = ((prefix[n] - prefix[n-i] + MOD) *1LL* inv[n-i-1])%MOD;
		if(p1==p2){
			anshash = p1;
			if(probe(i)){
				ans = true;
				cout << s.substr(0,i) << endl;
				return;
			}
		}
	}
	cout << "Just a legend" << endl;
	return;
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
		prefix[i+1] =  (prefix[i] + (s[i] - 'a' + 1) *1LL* p[i])%MOD;
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