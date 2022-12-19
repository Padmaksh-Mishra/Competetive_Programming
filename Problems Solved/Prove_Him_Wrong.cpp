//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
const int maxSize = 19;
using namespace std;
int ary[maxSize];
void initate(){
    ary[0]=1;
    for(int i=1; i<maxSize; i++){
        ary[i] = ary[i-1]*3;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    initate();
    while(TC--){
        ll N; cin >> N;
        if(N>maxSize) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            for(int i=0; i<N ;i++) cout << ary[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
