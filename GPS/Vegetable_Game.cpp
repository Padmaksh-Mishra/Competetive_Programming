//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,m; cin >> n >> m;
	set<string> tom,dum;
	set<string> pot;
	for(int i=0;i<n;i++){
		string t; cin >> t;
		tom.insert(t);
		dum.insert(t);
	}
	int sameword = 0;
	for(int i=0;i<m;i++){
		string t;cin>>t;
		pot.insert(t);
	}

	for(auto val:pot){
		if(tom.find(val)!=tom.end()) sameword++;
	}
	if(sameword&1) {
		sameword>>=1;
		if(tom.size()-sameword <=pot.size()-sameword-1) cout << "NO";
		else cout << "YES";
	}else{
		sameword>>=1;
		if(tom.size()-sameword <=pot.size()-sameword) cout << "NO";
		else cout << "YES";
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
