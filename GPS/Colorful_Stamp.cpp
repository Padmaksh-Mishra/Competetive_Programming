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
	string s; cin >> s;
	char stk[n+2];
	int top = 0;
	for(int i=0;i<n;++i){
		if(top==0){
			stk[top] = s[i];
			top++;
		}else if(stk[top-1]==s[i]) continue;
		else {
			stk[top] = s[i];
			top++;
		}
	}	
	vector<int> wi;
	for(int i=0;i<top;++i){
		if(stk[i]=='W') wi.push_back(i),deb(i);
	}
	int siz = wi.size();

 	for(int i = 1;i<siz;++i){
		if(wi[i]-wi[i-1]<2){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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