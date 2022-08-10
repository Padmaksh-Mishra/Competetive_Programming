//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# include <string.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	ll n,c,q; cin >> n >> c >> q;
	string s; cin >> s;
	ll lent[c+1];
	lent[0] = n;
	ll l[c+1],r[c+1];
	for(int i=1;i<=c;++i){
		cin >> l[i-1] >> r[i-1];
		lent[i] = lent[i-1] + (r[i-1] - l[i-1] + 1);
	}
	while(q--){
		ll k; cin >> k;
		for(int i=c-1;i>=0;i--){
			if(k>lent[i]){
				k = l[i] + (k-lent[i]-1);
			}
		}
		cout << s[k-1] << endl;
	}
}

int main(){

//for I/O----------------------------------

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif

//I/O end ---------------------------------

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