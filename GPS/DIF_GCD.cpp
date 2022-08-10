// <--> Nefarious <--> BadNess is in my ass

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,m; cin >> n >> m;
    int j;
    int mini = MOD;
    for(int i=0;i<m-n;++i){
        int tmp = (m%(n+i))+i;
        if(tmp<mini) j = i;
        mini = min(mini, tmp);
    }

	cout << (m-(m%(n+j))) << " " << n+j << endl;
}

int main(){

//for I/O----------------------------------

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif

//I/O end ---------------------------------

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
