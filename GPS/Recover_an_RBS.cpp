//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	string s; cin >> s;
	int n; n = s.size();
	//int bala[n];
	int q = 0,bal=0;
	// if(s[n-1]=='('){ //nvr exe
	// 	cout << "NO" << endl;
	// 	return;
	// }
	if(s[0]=='?') s[0] = '(';
	s[n-1] = ')';
	for(int i=0;i<n;++i){
		if(s[i]=='(') bal++;
		else if(s[i]==')') bal--;
		else q++;
		// // if(bal<0){
		// // 	if(q>0){
		// // 		q--;
		// // 		bal++;
		// // 	}
		// 	// else{ //never exe
		// 	// 	cout << "NO" << endl;
		// 	// 	return;
		// 	// }
		// bala[i] = bal;
		
	}
	// int icr = 0;
	// for(int i=0;i<n;++i){
	// 	if(s[i]=='?'){
	// 		if(bala[i]+icr<=0) q--,icr++;
	// 	}
	// }
	if(q-abs(bal)==0) cout << "YES" << endl;
	else cout << "NO" << endl;

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