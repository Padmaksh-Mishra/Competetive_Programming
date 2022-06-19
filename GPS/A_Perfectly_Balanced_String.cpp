//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	string s; cin >> s;
	set<char> set;
	int charcount = 0;
	int len = 0;
	int till = -1;
	//int old = set.size();
	for(int i=0;i<s.length();++i){
		set.insert(s[i]);
		len++;
	} 
	
	for(int i=0;i<len;++i){
		if(s[i]!=s[i%set.size()]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}


//Binary Exponention Iterative
int bexpo(int n,int p){ 
    int ans = 1,tmp = n;
    while(p>0){
        if(p&1) ans = (ans * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return ans;
}
