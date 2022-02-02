// Name.Redacted PM

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
        ll N, K;
        cin >> N >> K;
        vector<ll> V;
        if ((K < 2) && (N > 1))
        {
            cout << "-1\n";
        }
        else if ((K == 1) && (N = 1))
        {
            cout << "1\n";
        }
        // else if (K > N-1)
        //     cout << "-1\n";
        else
        {
            V.push_back(1);
            K -=2;
            int i = 2;
            while (K--)
            {
                V.push_back(i);
                i++;
            }
            int rem = N - V.size();
            for (int i = N; i > N - rem; i--) V.push_back(i);
            for (auto val : V)
            {
                cout << val << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}