#include<bits/stdc++.h>
using namespace std;

const int N = 1000 * 100 + 5;

vector <int> graph[N];
bool visited[N];
int parent[N];

void bfs(int start) {
    queue <int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(int u : graph[v]) {
            if(!visited[u]) {
                visited[u] = true;
                parent[u] = v;
                q.push(u);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);

    if(!visited[n]) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        vector <int> path;
        for(int v = n; v != 1; v = parent[v]) {
            path.push_back(v);
        }
        path.push_back(1);

        cout << path.size() << endl;
        for(int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
}
