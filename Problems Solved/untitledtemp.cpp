#include <bits/stdc++.h>

using namespace std;

vector<int> adj1[100000], adj2[100000];
bool visited[100000];

void DFS1(int a){
    if(visited[a]){
        return;
    }
    visited[a] = true;
    for(int b: adj1[a]){
        DFS1(b);
    }
}

void DFS2(int a){
    if(visited[a]){
        return;
    }
    visited[a] = true;
    for(int b: adj2[a]){
        DFS2(b);
    }
}

int main(){

    /* By assuming that 1 is the "root" node of this graph
       you can check if all nodes are connected to 1 since
       we know that if they are, then it must be connected
       to all the other cities as well.

       Check both going to and coming back...
    */

    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        --a, --b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    fill(visited, visited + n, false);

    // Check if you can get from node 1 to i...

    DFS1(0);

    for(int i=0; i<n; i++){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << 1 << " " << i + 1 << endl;
            return 0;
        }
    }

    fill(visited, visited+n, false);

    // Check if you can get from node i to 1...

    DFS2(0);

    for(int i=0; i<n; i++){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << i + 1 << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

}