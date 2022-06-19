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
	int n = s.length();
	if(n==1){
		cout << "Bob" << " ";
		cout << s[0] - 'a' + 1 << endl;
	}else{
		ll ans = 0;
		for(int i = 0;i<n;i++) ans += s[i] - 'a' + 1;
		if(n&1) {
			int bob = min((s[0]-'a'+1),(s[n-1]-'a'+1));
			ans = ans - (bob<<1);
		}
		cout << "Alice" << " ";
		cout << ans <<endl;
		//cout << endl;
	}    
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
