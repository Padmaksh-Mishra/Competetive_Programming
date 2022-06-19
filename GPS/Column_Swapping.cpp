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

	int ary[n][m];

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> ary[i][j];
		}
	}
	int swp1=-1,swp2=-1;
	for(int i=0;i<n;i++){
		int good[m];
		for(int j=0;j<m;j++){
			good[j] = ary[i][j];
		}
		sort(good,good+m);

		for(int j=0;j<m;j++){
			//deb(good[j]);
			//deb(ary[i][j]);
			if(good[j] != ary[i][j]){
				if(swp1==-1) swp1=j;
				else swp2= j;
			}
		}
	}
	//deb(swp1);
	//deb(swp2);
	if(swp1==-1){
		cout << "1 1" << endl;
		return;
	}
	for(int i=0;i<n;i++) swap(ary[i][swp1],ary[i][swp2]);
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			if(ary[i][j]>ary[i][j+1]){
				cout << "-1" << endl;
				return;
			}
		}
	}

	cout << swp1+1 << " " << swp2+1 << endl;
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
