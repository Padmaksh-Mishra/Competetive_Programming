//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
    bool possible = true;
    int N,K; cin >> N >> K;
    string s; cin >> s;
    int no1 = 0,xord = 0;
    for(int i=0;i<N;i++) {
        if(s[i]=='1') no1++;
        xord = (xord ^ ((int)s[i]-48));
    }
    int tmp = no1/K;
    if(K&1){
        if(xord==0) {
            if(tmp%1) possible = false;
        }
        else {
            if(!tmp%1) possible = false;
        }
    }else{
        if(xord==1) possible = false;
    }

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
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
