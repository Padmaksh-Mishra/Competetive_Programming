// Coding_Duck PM

#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TT;
    cin >> TT;
    while (TT--)
    {
        int N, K;
        cin >> N >> K;
        map<int, set<pair<int, int>>> max_customers;
        for (int i = 0; i < N; i++)
        {
            int s, f , p;
            cin >> s >> f >> p;
            max_customers[p].insert({f, s});
        }
        int cus = 0;
        for (auto miniMAP : max_customers)
        {
            int  endT = 0;
            for (auto pairs : miniMAP.second)
            {
                //cout << miniMAP.first <<" --> "<< pairs.first << " " << pairs.second << endl;   
                if (pairs.second >= endT)
                {
                    endT = pairs.first;
                    cus++;
                }
            }
        }
        cout << cus << endl;
    }
    return 0;
}