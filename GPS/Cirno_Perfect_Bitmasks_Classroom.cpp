//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	ll n; cin >> n;
	ll m = n;
	if(n==1){
		cout << 3 << endl;
		return;
	}
	ll z = -1,o=-1;
	int set = 0;
	for(int i = 0;i<64;i++){
		if(z==-1) if(n%2==0) z = i;
		if(o==-1) if (n%2==1) o = i;
		if(n&1) set++;
		n>>=1;
	}
	//deb(z);
	//deb(o);
	if(set==1) {
		cout << bexpo(2,o) + 1LL << endl;
		return;
	}else{
		if(m%2==0){
			cout << bexpo(2,o) << endl;
		}else cout << 1 << endl;
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
