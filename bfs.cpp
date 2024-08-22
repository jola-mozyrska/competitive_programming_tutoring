// Breath First Search + Connected Components
#include<bits/stdc++.h>
using namespace std;

const int N = 1000 * 1000 + 5;

vector <int> graph[N];
bool visited[N];

void bfs(int start) {
    queue <int> q;
    // q.push(wierzcholek); wepchnij na koniec kolejki
    // q.pop(); zdejmij z poczatku kolejki
    // int v = q.front(); sprawdz element na poczatku kolejki

    // bool czy_pusta = q.empty() sprawdza czy kolejka jest pusta

    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(int u = 0; u < graph[v].size(); ++u) {
            if(!visited[u]) {
                visited[u] = true;
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

}
