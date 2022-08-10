# include <bits/stdc++.h>
# define JAI ios_base::sync_with_stdio(false); 
# define SHREE cin.tie(NULL); 
# define RAM cout.tie(NULL);
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define pb push_back
# define f first
# define s second
# define NO cout << "NO" << endl
# define YES cout << "YES" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (ll)(x).size()
# define vi vector<int>
# define vll vector<ll>

using namespace std;
const ll MOD = 1e9 +7;
void setIO(string name = "sublime");


void solve(){
	int n,m;
	vi hsh1(26,0);
	vi hsh2(26,0);
	string s; cin >> s;
	// deb(s);
	n = siz(s);
	for(int i=0;i<n;++i){
		// deb(hsh1[s[i]-'a']);
		hsh1[s[i]-'a']++;
	}
	string t; cin >> t;
	m = siz(t);
	int ans = 0;
	for(int i=0;i<m;++i){
		// deb(hsh1[t[i]-'a']);
		if(hsh1[t[i]-'a']==0) {
			cout << -1 << endl;
			return;
		}
		hsh2[t[i]-'a']++;
	}

	for(int i=0;i<26;++i) {
		ans+=min(hsh1[i],hsh2[i]);
		// deb(hsh1[i]);
		// deb(hsh2[i]);
	}
	cout << ans << endl;
}

int main(){

    JAI SHREE RAM

    setIO();	//Google and other non judges
    int TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
    	//cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}

void setIO(string name) {  
#ifndef ONLINE_JUDGE
	if((ll)name.size() > 0){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
#endif
}

//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 