//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int r=8,c=8;
	int f;
	int ip[8][8];
	int i,k;
	for(int i=0;i<c;++i) {
		char t; cin >> t;
		ip[0][i] = t;
	}
	int row = 0;
	bool ok = false;
	for(int i=1;i<r-1;++i){
		int as = 0;
		for(int j=0;j<c;++j){
			char tmp; cin >> tmp;
			if(tmp=='#') {
				as++;
			}
			ip[i][j] = tmp;
		}
		if(as==1&&!ok){
			row = i;
			ok=true;
		}
	}
		
		
	for(int k=0;k<c;++k){
		if(ip[i][k]=='#'){
			f=k;
			break;
		}
	}

	cout << i+1 << " " << f+1 << endl;
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
