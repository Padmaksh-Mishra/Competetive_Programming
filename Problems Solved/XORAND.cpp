//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;
int bitCounter(int n){
    return log2(n)+1;
}
void solve(){
    int N; cin >> N;
    map<int,int> map;
    for(int i=0; i<N; i++){
        int tmp;cin >> tmp;
        map[bitCounter(tmp)] ++;
    }
    ll count = 0;
    for(auto i=map.begin(); i!=map.end(); i++){
        //cout << i->first << " " << i->second << endl;
        ll temp = i->second;
        if(temp >1) count +=(temp*(temp-1))/2;
    }
    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
