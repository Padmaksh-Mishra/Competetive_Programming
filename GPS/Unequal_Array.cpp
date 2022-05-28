//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
const int size = 2*1e5;
using namespace std;

int bexpo(int n,int p);

int stk[size];
int top;

void solve(){
	int n;cin >> n;
	for(int i=0;i<n;i++) cin >> stk[i];
	int base=-1,same=0;
	for(int i=1;i<n;i++){
		if(stk[i]==stk[i-1]){
			if(base==-1) base = i-1;
			same = i;
			//deb(base);deb(same);
		}
	}
	if(same-base<2) cout << 0 << endl;
	else if(same-base==2) cout << 1 << endl;
	else cout << same - base - 2 << endl;
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
