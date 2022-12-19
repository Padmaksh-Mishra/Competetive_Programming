//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
char stk[2000006];

void solve(){
	string a; cin >> a;
	string test; cin >> test;
	int n = test.size();
	int top = n;
	for(int i=0;i<a.size();++i){
		stk[top] = a[i];
		top++;
		string tmp = "";
		for(int i=n;i>0;--i){
			tmp += stk[top-i];
		}
		if(tmp==test){
			top = top - n;
		}
	}
	for(int i=n;i<top;++i){
		cout << stk[i];
	}	
	cout << endl;

	string censored;
	for(int i=0;i<a.size();++i){
		censored+=a[i];
		if((censored.size() > n) && (censored.substr(censored.size()-n)==test)) 
			censored.resize(censored.size()-n);
	}
	cout << censored << endl;
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
    int censored = 1,tmp = n;
    while(p>0){
        if(p&1) censored = (censored * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return censored;
}