//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
int n,p,goodindex = -1; 

void solve(){
	cin >> n >> p;
	string s; cin >> s;
	for( int i = n-1 ; i>-1 ;i-- ){   //Garbage vlaue lega lene do 
		string tmp  = s;			//as it can never satasfy the below if's condition ;]
		while(tmp[i]-'a'<p-1){
			tmp[i]++;
			if((tmp[i-1]!=tmp[i])&&(tmp[i-2]!=tmp[i])){
				goodindex = i;
				s[i] = tmp[i];
				break;
			}
		}
		if(goodindex!=-1) break;
	}
	if(goodindex==-1) cout << "NO" << endl;
	else{
		for(int i = goodindex+1;i<n;i++){
			s[i] = 'a'-1;
			while(s[i]-'a'<p-1){
				s[i]++;
				if((s[i-1]!=s[i])&&(s[i-2]!=s[i])){
					break;
				}
			}
		}
		cout << s << endl;
	}
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
