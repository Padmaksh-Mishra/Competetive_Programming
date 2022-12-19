//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

int N,M;
int woods[1000000];

bool isEnough(int H){
    ll sum = 0;
    for(int i=0;i<N;i++){
        if(woods[i]>H) sum += woods[i] - H;
    }
    return sum >=M;
}

void solve(){
    cin >> N >> M ;
    for(int i=0;i<N;i++){
        cin >> woods[i];
    }
    int high = 1000000000,low = 0, mid;
    while(high-low>1){
        mid = (high+low)>>1;
        if(isEnough(mid)) low = mid;
        else high = mid-1;    
    }
    if(isEnough(high)) cout << high << endl;
    else cout << low << endl;
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
