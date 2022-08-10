//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	// for(int i=1;i<46;++i){
		int s; cin >> s;
		if(s<=9) cout << s << endl;
		else if(s<=17) cout << s-9 << 9 << endl;
		else if(s<=24) cout << s-17 << 89 << endl;
		else if(s<=30) cout << s-24 << 789 << endl;
		else if(s<=35) cout << s-30 << 6789 << endl;
		else if(s<=39) cout << s-35 << 56789 << endl;
		else if(s<=42) cout << s-39 << 456789 << endl;
		else if(s<=44) cout << s-42 << 3456789 << endl;
		else if(s<=45) cout << s-44 << 23456789 << endl;
	//}
	
	
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