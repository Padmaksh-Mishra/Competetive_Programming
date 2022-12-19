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
	int tmp;
	vector<int> hsh(10,0);
	vector<int> s;
	for(int i=0;i<n;++i){
		cin >> tmp;
		tmp = tmp % 10;
		if(hsh[tmp]<3){
			s.push_back(tmp);
			hsh[tmp]++;
		}
	}
	int siz = s.size();
	for(int i = 0;i<siz;++i){
		for(int j = i+1;j<siz;++j){
			for(int k = j+1;k<siz;++k){
				if((s[i]+s[j]+s[k])%10==3){
					cout << "YES" << endl;
					return;
				}
			}
		}
	}
	cout << "NO" << endl;
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