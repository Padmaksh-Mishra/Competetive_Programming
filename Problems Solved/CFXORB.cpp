//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n; cin >> n;
	set<int> ary;
	for(int i=0;i<n;i++) {
		int tmp;
		cin >> tmp;
		ary.insert(tmp);
	}
	int x; cin >> x;
	int hash[2] = {0,0};
	for(auto it = ary.begin();it!=ary.end();it++){
		if(((*it)^x)==0) hash[0]++;
		else hash[1]++;
	}
	int t = ((hash[0]*(hash[0]-1))>>1);
	int u = ((hash[1]*(hash[1]-1))>>1);
	cout << u+t << endl;    
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
