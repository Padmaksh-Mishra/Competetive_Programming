//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

using namespace std;

const ll MOD = 1e9 + 7;

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

void solve(){
	int n; cin >> n;
	map<ll,int> regsys;
	while(n--){
		string s; cin >> s;
		ll hs = compute_hash(s);
		if(regsys.find(hs)!=regsys.end()){
			regsys[hs]++;
			cout << s << regsys[hs] << endl;
		}else{
			regsys[hs] = 0;
			cout << "OK" << endl;
		}
	}
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything
    int TC = 1;
    //cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}


