//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,k; cin >> n >> k;
	int tmp;
	vector<int> m;
	while(n--){
		cin >> tmp;
		m[tmp]++;
	}
	vector<pair<int,int>> v;
	for(auto val : m){
		if(val.second>=k) v.push_back({1,val.first});
		else v.push_back({0,val.first});
	}
	int l=-1,r=-1;
	int d = 0;
	int L,R;
	for(int i=0;i<v.size();++i){
		if(v[i].first==1){
			if(l==-1) l = i;
		}else {
			if(l!=-1){
				r = i-1;
				int td = r-l;
				if(td>d){
					L=l;R=r;
					d = td;
				}
			}
			l==r==-1;
		}
	}
	cout << v[L].first << " " << v[R].second << endl;	
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