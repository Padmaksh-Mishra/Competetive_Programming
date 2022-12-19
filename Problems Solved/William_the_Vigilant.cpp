//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,q; cin >> n >> q;
	string s; cin >> s;
	vector<int> v;
	for(int i=0;i<n-2;++i){
		if(s.substr(i,3)=="abc") v.push_back(i);
	}
	int ans = v.size();	
	while(q--){
		int pos; cin >> pos; pos--;
		char put; cin >> put;
		if(s.substr(pos,3) == "abc") ans--;
		if(pos>=1&&s[pos-1]=='a'&&s[pos]=='b'&&s[pos+1]=='c') ans--;
		if(pos>=2&&s[pos-2]=='a'&&s[pos-1]=='b'&&s[pos]=='c') ans--;
		s[pos] = put;
		if(s.substr(pos,3) == "abc") ans++;
		if(pos>=1&&s[pos-1]=='a'&&s[pos]=='b'&&s[pos+1]=='c') ans++;
		if(pos>=2&&s[pos-2]=='a'&&s[pos-1]=='b'&&s[pos]=='c') ans++;
		cout << ans << endl;
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