//Coding_Duck PM
# include <bits/stdc++.h>   //iostraem already included

typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N;
    cin >> N;
    cout << N << " "; 
    while(N>1){
        if((N&1)==0){
            N /= 2; 
        }
        else{
            N *= 3;
            N++; 
        }
        cout << N << " ";
    }
    return 0;
}