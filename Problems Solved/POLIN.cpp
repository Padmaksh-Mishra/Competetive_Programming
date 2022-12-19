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
    while (TC--)
    {
        int N, X, Y;
        set<int> sx, sy;
        cin >> N;
        while (N--)
        {
            cin >> X >> Y;
            sx.insert(X);
            sy.insert(Y);
        }
        cout << sx.size() + sy.size() << endl;
    }
    return 0;
}