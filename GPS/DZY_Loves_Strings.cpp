//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

int ary[26];

void solve(){
	string s; cin >> s;
	int k; cin >> k;
	int max = 0;
	for(int i=0;i<26;i++){
		cin >> ary[i];
		max = (max>ary[i]) ? max : ary[i];
	}
	ll ans = 0;
	int i;
	for(i=0;i<s.length();i++){
		ans += (i+1)*ary[(s[i]-97)];
	}
	for(int j = i+1;j<=i+k;j++){
		ans += max*j;
	}
	cout << ans << endl;
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
