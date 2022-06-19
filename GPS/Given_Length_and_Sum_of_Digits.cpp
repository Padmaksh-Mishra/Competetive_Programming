//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int m,s; cin >> m >> s;
	if(s==0&m==1) {
		cout << "0 0";
		return;
	}
	if((s==0)||(s>9*m)){
		cout << "-1 -1";
		return;
	}

	int a,b; a=b=s;
	int larg[m],smll[m];
	for(int i=0;i<m;i++){
		if(a>8){
			a-=9;
			larg[i]=9;
		}
		else if (a>0){
			larg[i] = a;
			a=0;
		}else larg[i]=a;
	}
	smll[m-1] = 1;
	b--;
	for(int i=0;i<m-1;i++){
		if(b>8){
			b-=9;
			smll[i]=9;
		}
		else if (b>0){
			smll[i] = b;
			b=0;
		}else smll[i]=b;
	}
	smll[m-1]+=b;
	
	
	for(int i=m-1;i>-1;i--) cout << smll[i];
	cout << " ";
	for(int i=0;i<m;i++) cout << larg[i];
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
		