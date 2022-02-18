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
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        cout << (A[0] & A[1]) << " ";
        for (int i = 1; i < N-1 ; i++)
        {
            cout << max((A[i] & A[i - 1]), (A[i] & A[i + 1])) << " ";
        }
        cout << (A[N - 1] & A[N-2]) << "\n";
    }
    return 0;
}