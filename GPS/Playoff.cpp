//Coding_Duck PM

# include <bits/stdc++.h>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC; cin >> TC;
    while(TC--){
        int N; cin >> N;
        cout << (1<<N) - 1 << endl;
    }
    return 0;
}
