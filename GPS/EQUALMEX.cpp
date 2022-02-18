// Name.Redacted || Coding_Duck || PM

#include <bits/stdc++.h> //iostream already included

using namespace std;
typedef long long ll;

// int MEX(set<int> &S,int N){
//     int i = 0;
//     for(auto val : S){
//         if(val!=i){
//             return i;
//         }
//         i++;
//     }
//     return N;
// }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;
    while (TC--)
    {
        int N;
        cin >> N;
        map<int, int> M;
        int T = N * 2;
        int i = 0, tempF;
        bool won = true;
        while (T--)
        {
            cin >> tempF;
            M[tempF]++;
        }
        for (auto val : M)
        {
            if (val.first != i)
            {
                won = true;
                break;
            }
            if(val.second == 1){
                won = false;
                break;
            } 
            i++;
        }
        
        if ((i == N) && !won)
            won = true;
        if (won)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}