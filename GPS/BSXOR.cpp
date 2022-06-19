//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;
vector<ll> ary(14);
vector<ll> sums,counts;
int bexpo(int n,int p);

int setBitsCounter(ll n){
    int count = 0;
    while(n){
        if(n&1) count++;
        n = n>>1;
    }
    return count;
}

void intitlize(){   
    ary[1] = 1;
    for(int i = 2;i<15;i++){
        ary[i] = ary[i-1] * i;
    }
}

void factSet(){

    int maxi = (1<<14);

    for(int i = 0 ; i <maxi;i++){ //a 15 bit binary represinting which element is included
        ll sum=0,count=0,p = 1;
        for(int j = 0;j<14;j++){
            if(i&p) {
                sum+=ary[j+1];
                count++;
            }
            p = (p<<1);
        }
        sums.push_back(sum);
        counts.push_back(count);
    }
}


void solve(){
    ll n; cin >> n; 
    int ans = setBitsCounter(n),tmp = 0;

    ll txt = 1e18;
    for(int i = 0;i<(1<<14);i++){
        //cout << "HI" << endl;
        ll x = n -sums[i];
        if(x<0) continue;
        txt = min(txt,counts[i]+setBitsCounter(x));
    }
    ans = (ans<txt) ? ans : txt;
    cout << ans << endl;

}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    cin >> TC;

    intitlize();
    factSet();

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