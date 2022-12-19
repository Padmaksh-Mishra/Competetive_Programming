//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,m,k; cin >> n >> m >> k;
	char p ;
	int streak = 0;
	string a; 
	cin >> a;
	string b; cin >> b;
	// deb(a);
	// deb(b);
	sort(a.begin(),a.end()); sort(b.begin(),b.end());
    vector<char> c; 
	int ai=0,bi=0;
	n--;
	m--;
	if(a[0]<b[0]){
		c.push_back(a[0]);
		p = a[0];
		streak++;
		n--;
		ai++;
	}else {
		c.push_back(b[0]);
		p = b[0];
		streak++;
		m--;
		bi++;
	}

	for(int i=0;;i++){
    	//deb(a[i]);
    	//deb(b[i]);
    	if(n<0) break;
    	if(m<0) break;
	    if(a[ai]<=b[bi]){
			if(p==a[ai]){
				if(streak<=k){
					c.push_back(a[ai]);
					streak++;
					n--;
					ai++;
				}else{
					streak=1;
					p = b[bi];
					c.push_back(b[bi]);
					m--;
					bi++;
				}	
			}else{
				streak=1;
				p = a[ai];
				c.push_back(a[ai]);
				n--;
				ai++;
			}
		}else {			
			if(p==b[i]){
				if(streak<=k){
					c.push_back(b[bi]);
					streak++;
					m--;
					bi++;
				}else{
					streak=1;
					p = a[ai];
					c.push_back(a[ai]);
					n--;
					ai++;
				}	
			}else{
				streak=1;
				p = b[bi];
				c.push_back(b[bi]);
				m--;
				bi++;
			}
		}	
	}
	for(int i=0;i<c.size();++i) cout << c[i];
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
