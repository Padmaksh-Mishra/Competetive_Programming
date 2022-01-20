// Coding_Duck PM

#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string xyz;
    cin >> xyz;
    vector<char> a;
    for (int i = 0; i < xyz.size(); i++)
    {
        if (xyz[i] == '+')
        {
            continue;
        }

        a.push_back(xyz[i]);
    }
    sort(a.begin(), a.end());
    cout << a[0];
    for (int i = 1; i < a.size(); i++)
    {
        cout << "+" << a[i];
    }

    return 0;
}