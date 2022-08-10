//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
int maped[5000][5000];
int x,y;
int ghadi;
vector<int> ans;

void solve(){
	int n; cin >> n;
    x=y=2500;
    ghadi=0;
	while(n--){
		char D; cin >> D;
		int steps; cin >> steps;
		if(D=='S'){
            for(int i=0;i<steps;++i){
                if(maped[x][y]!=0) ans.push_back(ghadi-maped[x][y]);
                maped[x][y] = ghadi;
                y--;
                ghadi++;
            }
        }else if(D=='N'){
            for(int i=0;i<steps;++i){
                if(maped[x][y]!=0) ans.push_back(ghadi-maped[x][y]);
                maped[x][y] = ghadi;
                y++;
                ghadi++;
            }
        }else if(D=='W'){
            for(int i=0;i<steps;++i){
                if(maped[x][y]!=0) ans.push_back(ghadi-maped[x][y]);
                maped[x][y] = ghadi;
                x--;
                ghadi++;
            }
        }else if(D=='E'){
            for(int i=0;i<steps;++i){   
                if(maped[x][y]!=0) ans.push_back(ghadi-maped[x][y]);
                maped[x][y] = ghadi;
                x++;
                ghadi++;
            }
        }
	}
    int t = 1e9;
    for(auto val:ans){
        t = min(t,val);
    }	
    cout << (t==1e9? -1 : t) << endl;
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