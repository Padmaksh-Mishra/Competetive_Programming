//Name.Redacted || Coding_Duck || PM

# include <bits/stdc++.h>	//iostream already included 

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC; 
    int i = 0;
    while(TC--){
        i++;
        ll N,M;
        cin >> N >> M;
        ll temp,sum = 0;
        for(int i = 0; i <N ; i++){
            cin >> temp;
            sum += temp;
        }
        cout << "CASE #" << i << ": " << sum%M << endl;
    }
    return 0;
}