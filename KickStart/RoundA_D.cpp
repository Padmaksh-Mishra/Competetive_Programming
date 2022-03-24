//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e7 + 1;
using namespace std;

ll solution[MOD] = {1,1,1,1,1,1,1,1,1};

ll sumDgts(ll n){
    ll sum = 0;
    while (n){
        sum = sum + (n%10);
        n = n/10;
    }
    return sum;
}
ll productOfdgts(ll n){
    ll prod = 1;
    ll sum = sumDgts(n);
    while (n){
        prod = (prod*(n%10))%sum;
        if(prod==0) return prod;
        n = n/10;
    }
    return prod;
}

void initiate(){
    for(ll i = 10;i<= MOD;i++){
        if(!(productOfdgts(i)%sumDgts(i))) solution[i-1] = 1;
        else solution[i-1] = 0;
    }
}

void solve(){
    ll start,end; cin >> start >> end;
    ll count = 0;
    for(ll i = start; i<= end; i++){
        //cout << "At i = " << i << " value = " << solution[i-1] << endl;
        if(solution[i-1]) count++;
    }
    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    initiate();
    int TC;
    cin >> TC;
    ll p = 0;
    while(TC--){
        p++;
        cout << "Case #" << p << ": ";
        solve();
    }
    //cout << "solution" << endl;
    return 0;
}
