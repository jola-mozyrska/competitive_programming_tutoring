#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define endl '\n'

const ll mod = 1000000007;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dist(n, vector<int>(n, 1e18));
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w; u--; v--;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    while(q--)
    {
        int u, v;
        cin >> u >> v; u--; v--;
        cout << (dist[u][v] == 1e18 ? -1 : dist[u][v]) << endl;
    }

    return 0;
}