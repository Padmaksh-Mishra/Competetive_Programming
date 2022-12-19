//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int a,b; cin >> a >> b;
	string s; cin >> s;
	int j = 0;
	int i = 0;
	int l = s.length();
	vector<int>	v(l,0);
	v[j]++;
	while(s[i]=='0') i++;
	i++;
	if(i==l+1){
		cout << 0 << endl;
		return;
	}
	for(;i<l;++i){
		if(s[i-1]!=s[i]) j++;
		v[j]++;
	}
	ll cost = a;
	// deb(j);
	// for(auto val:v){
	// 	val*=b;
	// }
	// cout << endl;
	for(int k=1;k<j;k+=2){
		if(v[k]*b*1LL<=a){
			cost+=v[k]*1LL*b;
		}else cost+=a;
	}
	cout << cost << endl;
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