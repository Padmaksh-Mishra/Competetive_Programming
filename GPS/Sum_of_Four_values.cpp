//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define f first
# define s second
const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,x; cin >> n >> x;
	vector<pair<int,int>> v;
	for(int i=0;i<n;++i){
		int tmp; cin >> tmp;
		v.push_back({tmp,i});
	}	
	sort(v.begin(), v.end());
	for(int m = 0;m<n;++m){
		for(int i=m+1;i<n;++i){
			int tgt = x - v[i].f - v[m].f;
			int k = n-1;
			for(int j=i+1;j<k;++j){
				int sum = v[j].f + v[k].f;
				while(sum>=tgt&&k>j){
					if(sum==tgt){
						cout << v[m].s+1 << " " << v[i].s+1 << " " << v[j].s+1 << " " << v[k].s+1 << endl;
						return;
					}
					k--;
					sum = v[j].f + v[k].f;
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return;
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