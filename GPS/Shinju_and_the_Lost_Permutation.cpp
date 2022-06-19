//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

int C[100000];

void solve(){
	
	int n; cin >> n;
	for (int i=0;i<n;i++) cin >> C[i];
	if((n==1)&&(C[0]==1)) cout << "YES" << endl;
	else if(n>1){
		bool win = true;
		int no1=0;
		for(int i = 0;i<n-1;i++){
			if(C[i] == 1) no1++;
			if(C[i+1]-C[i]>1) {
				win = false;
				break;
			}	
		}
		if(C[n-1]==1) no1++;
		if(no1!=1) win = false;
		if(win) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else cout << "NO" << endl;
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
