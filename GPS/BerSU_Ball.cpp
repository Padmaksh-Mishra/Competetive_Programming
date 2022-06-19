//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
int boys[101],girls[101];
int n,m;

void solve(){
	cin >> n;
	for(int i=0;i<n;++i) cin >> boys[i];
	cin >> m;
	for(int i=0;i<m;++i) cin >> girls[i];
	sort(boys,boys+n);
	sort(girls,girls+m);
	ll pairs = 0;
	for(int i=0;i<n;++i){
		for(int f=0;f<m;++f){
			if(abs(boys[i]-girls[f])<=1){
				pairs++;
				girls[f] = MOD;
				break;
			}
		}
	}
	cout << pairs ;
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
