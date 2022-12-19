//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int xg1,xg2,xb1,xb2,yg1,yg2,yb1,yb2;
	cin >> xb1 >> yb1 >> xb2 >> yb2 >> xg1 >> yg1 >> xg2 >> yg2;
	int xi = max(0,min(xb2,xg2)-max(xb1,xg1));
	int yi = max(0,min(yb2,yg2)-max(yb1,yg1));
	int areai = xi*yi;
	if(xi<(xb2-xb1)&&yi<(yb2-yb1)) areai = 0;
	cout << ((xb2-xb1)*(yb2-yb1)) - areai << endl;
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
    int ans = 1,tmp = n;
    while(p>0){
        if(p&1) ans = (ans * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return ans;
}