//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

char stk[100000];
int top = 0;

void solve(){
	int n;
	string s; cin >> s;
	n = s.length();
	//deb(n);
	for(int i = 0 ; i<n ;i++){
		//deb(s[i]);
		if(top==0){
			stk[top] = s[i];
			top++;
		}
		else{
			if(stk[top-1] == s[i]) top--;
			else {
				stk[top] = s[i];
				top++;
			}
		}
		//deb(stk[top-1]);
	}
	//deb(top);
	int ans = ((n - top)>>1);
	//deb(ans);
	if(ans&1) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

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
