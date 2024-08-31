#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1000003];
bool visited[1000003];

// n = liczba wierzcholkow
// m = liczba krawedzi
int n, m;


// depth first search
void dfs(int node) {
    visited[node] = true;
    // zrob aktualizacje, informacje, co chcesz zrobic z wierzcholkiem
    for(int i = 0; i < graph[node].size(); ++i) {
        int u = graph[node][i];
        if(visited[u] == false) {
            dfs(u);
        }
    }
}

int main() {
    // scanf("%d %d", &n, &m);
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int a, b;
        // scanf("%d %d", &a, &b);
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // for(int i = 1; i <= n; ++i) {
        // if(!visited[i]) {
            dfs(0);
        // }
    // }

    // printf("%d\n", components);
}
