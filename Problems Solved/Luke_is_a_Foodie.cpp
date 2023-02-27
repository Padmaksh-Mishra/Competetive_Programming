//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,x; cin >> n >> x;
	vector<int> v(n);
	double sum = 0;
	for(int i=0;i<n;++i){
		cin >> v[i];
		sum+=v[i];
	}
	int ans = 0;
	int avg = round(sum/n);
	deb(avg);
	int tn;
	if(v[0]<avg-x){
		tn=v[0]+x;
	}else if(v[0]>avg+x){
		tn=v[0]+x;
	}
	for(int i=0;i<n;++i){
		if((tn>v[i]+x)||(tn<v[i]-x)){
			ans++;
			if(v[i]<avg-x){
				tn=v[i]+x;
			}else if(v[i]>avg+x){
				tn=v[i]+x;
			}
		}
	}
	cout << ans << endl;
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