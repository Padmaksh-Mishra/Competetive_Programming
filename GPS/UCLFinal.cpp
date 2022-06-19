//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n; cin>>n;
	int ary[n+2];
	ary[0] = 0;
	ary[n+1] = 90;
	for (int i = 1; i < n+1; ++i)
	    {
	    	cin >> ary[i];
	    }

	for (int i = 0; i < n+1; ++i)
	    {
	    	if(ary[i+1]-ary[i]>15){
	    		cout << ary[i]+15;
	    		return;
	    	}
	    }

	cout << "90";
	return;    
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
