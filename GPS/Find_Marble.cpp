//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

int p[100000];

void solve(){
	int n,s,t; cin >> n >> s >> t;
	s--;t--;
	for(int i=0;i<n;i++){
		cin >> p[i];
		p[i]--;
	}
	int i;
	int index = s;
	for(i=1;i<1e7;i++){
		//deb(p[index]);
		if(index==t){
			cout << i-1;
			return;
		}
		index = p[index];
	}
	cout << -1;
	return;
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
