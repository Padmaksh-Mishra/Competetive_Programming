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
	int ek=0,teen=0,pach=0,das=0;
    int mini = MOD;
    set<int> s;
	for(int i=0;i<n;++i){
		int tmp; cin >> tmp;
		tmp+=(tmp%10);
        if(tmp%10==5) pach++;
        else if(tmp%10==0) das++; 
		else if(tmp%10!=6){
            if((tmp/10)%2==0) ek++;
            else teen++;
        }else{
            if((tmp/10)%2==0) teen++;
            else ek++;
        }
        mini = min(mini,tmp);
        s.insert(tmp);
	}
    if(s.size()==1) cout << "YES" << endl;
	else if(max(ek,teen)==n) cout << "YES" << endl;
    else if(das+pach==n&&(mini%10)==5) cout << "YES" << endl;
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