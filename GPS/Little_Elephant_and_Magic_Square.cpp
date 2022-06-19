//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int E[3][3];
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			cin >> E[i][j];
		}
	}   
	int s1 = E[0][0] + E[0][1] + E[0][2];
	int s2 = E[1][0] + E[1][1] + E[1][2]; 
	int s3 = E[2][0] + E[2][1] + E[2][2];
	int dif = min(abs(s1-s2),abs(s1-s3));
	if(s1>s2&&s1>s3){
		if(s2>s3){
			int a = (E[2][0]+ E[1][1] + E[0][2]-2*dif)>>1;
			cout << a+2 << " " << E[0][1] << " " << E[0][2] << endl;
			cout << E[1][0] << " " << a+1 << " " << E[1][2] << endl;
			cout << a+2 << " " << E[0][1] << " " << E[0][2] << endl;
		}
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
