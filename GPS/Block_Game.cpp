//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
ll sigma[27];
void solve(){
	int n; cin >> n;

	while(n--){
		vector<int> alpha1(27,0),alpha2(27,0);
		string tmp1,tmp2; cin >> tmp1 >> tmp2;
		for(int i=0;i<tmp1.length();++i){
			alpha1[tmp1[i]-'a'+1]++;
		}
		for(int i=0;i<tmp2.length();++i){

			alpha2[tmp2[i]-'a'+1]++;
		}
		for(int i=1;i<27;++i){
			sigma[i]+=max(alpha1[i],alpha2[i]);
		}	
	}
	for(int i=1;i<27;++i){
		cout << sigma[i] << endl;
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