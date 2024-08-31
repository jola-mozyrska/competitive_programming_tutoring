#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1000003];
bool visited[1000003];

// n = liczba wierzcholkow
// m = liczba krawedzi
int n, m;


// depth first search
void dfs(int wierzcholek) {
    visited[wierzcholek] = true;
    // zrob aktualizacje, informacje, co chcesz zrobic z wierzcholkiem
    for(int i = 0; i < graph[wierzcholek].size(); ++i) {
        if(visited[i] == false) {
            dfs(i);
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
