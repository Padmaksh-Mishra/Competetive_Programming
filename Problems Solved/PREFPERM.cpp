// Name.Redacted || Coding_Duck || PM

#include <bits/stdc++.h> //iostream already included

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;
    while (TC--){
        int N,K;
        cin >> N >> K;
        vector<int> V;
        int array[K];
        for(int i = 0; i < K;i++) {
            cin >> array[i];
            for(int j = array[i]; V.size()<array[i];j--) V.push_back(j);
        }
        for(auto val : V) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}