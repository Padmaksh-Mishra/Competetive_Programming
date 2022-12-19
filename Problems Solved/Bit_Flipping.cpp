//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,k; cin >> n >> k;
	string s; cin >> s;
	int op[n];
	//deb(k);
	if(k%2==0){
		for(int i = 0;i<n-1;i++){
			op[i]=0;
			if((s[i]=='0')&&(k>0)) {
				s[i] = '1';
				op[i]=1;
				k--;
			}
		}
			if(k%2!=0) s[n-1] = (s[n-1]=='0') ? '1' : '0';
			op[n-1] = k;
			//cout << "EVEN = " << s << endl;
		
	}
	else{
		for(int i = 0;i<n-1;i++){
			op[i]=0;
			s[i] = (s[i]=='0') ? '1' : '0';
			if((s[i]=='0')&&(k>0)) {
				s[i] = '1';
				op[i]=1;
				k--;
			}
		}
			if(k%2==0) s[n-1] = (s[n-1]=='0') ? '1' : '0';
			op[n-1] = k;
			//cout << "ODD = " << s << endl;
		
	}
	cout << s << endl;    
	for(int i =0;i<n;i++) cout << op[i] << " ";
	cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

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
