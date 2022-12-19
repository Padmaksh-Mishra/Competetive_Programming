//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n; cin >> n;
	string prim; cin >> prim;
	string bin; cin >> bin;
	bitset<100000> A(prim);
	bitset<100000> B(bin);
	string alt1,alt2;
	if(prim==bin){
		cout << "YES" << endl;
		return;
	}
	for(int i=0;i<n;++i){
		if(i&1) {
			alt1+='1';
			alt2+='0';
		}else{
			alt1+='0';
			alt2+='1';
		}
	}
	if(A.count()>0){
		if(bin==alt1||bin==alt2){
			cout << "NO" << endl;
			return;	
		}
		cout << "YES" << endl;
		return;
	}
	else{
		if(B.count()==0){
			cout << "YES" << endl;
			return;		
		}
		cout << "NO" << endl;
	}	
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