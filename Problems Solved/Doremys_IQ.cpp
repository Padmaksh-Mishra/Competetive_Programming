//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,q; cin >> n >> q;
	// deb(q);
	vector<pair<int,int>> a(n);
	int val[n];
	for(int i=0;i<n;++i){
		cin >> val[i];
		a[i].second = i;
		a[i].first = val[i];
	}
	sort(a.begin(), a.end());
	vector<int> has(n,0);
	for(int i =0;i<n;++i){
		deb(a[i].first);
		if(a[i].first<=q) has[a[i].second] = 1;
		deb(a[i].second);
		deb(has[i]);
	}
	for(int i=0;i<n;++i){
		// deb(has[i]);
		if(q<=0){
			cout << 0;
			continue;
		}
		if(has[i]==1){
			if(val[i]>q){
				q--;
				cout << 1;
			}else cout << 1;
		}else  cout << 0;
	}

	cout << endl;

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