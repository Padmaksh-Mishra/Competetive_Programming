//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int n; cin >> n;
        set<int> set;
        for(int i=0; i<n; i++) {
            int temp; cin >> temp;
            set.insert(temp);
        }
        for(int k=1; k<n+1; k++) {
            if(k<=set.size()) {
                cout << set.size() << " ";
            }else cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}
