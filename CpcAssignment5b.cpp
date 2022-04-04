
#include <bits/stdc++.h>


using namespace std;

void adjacencyList(vector<int> adj[], int a, int b)
{
    adj[a - 1].push_back(b-1);
    adj[b - 1].push_back(a-1);
}

int main()
{
    int nodes;
    cin >> nodes;

    //creating adjacency list for n test cases
    vector<int> adj[nodes];
    for (int i = 0; i < nodes - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjacencyList(adj, a, b);
    }

    queue<pair<int, int>> q; // pair<node, node's parent>
    q.push({0, -1});

    int level = 0, oddLevelNodes = 0, evenLevelNodes = 0;
    while (!q.empty())
    {
        level ^= 1; // to find whether the level is even or odd
        if (level == 1)
        {
            oddLevelNodes += q.size();
        }
        else
        {
            evenLevelNodes += q.size();
        }

        int s = q.size();
        while (s--)
        {
            int current = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[current])
            {
                if (it == parent)
                {
                    continue;
                }
                q.push({it, current});
            }
        }
    }
    long long m = oddLevelNodes * (oddLevelNodes - 1) / 2;
    long long n = evenLevelNodes * (evenLevelNodes - 1) / 2;
    
    // long long ans = 1ll * oddLevelNodes * (oddLevelNodes - 1) / 2 + 1ll * evenLevelNodes * (evenLevelNodes - 1) / 2;
    cout << m+n << endl;
    return 0;
}