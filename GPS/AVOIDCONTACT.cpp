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
        int X, Y;
        cin >> X >> Y;
        if (X - Y)
            cout << (2 * Y) + (X - Y) << endl;
        else
            cout << (2 * Y) + (X - Y) - 1 << endl;
    }
    return 0;
}