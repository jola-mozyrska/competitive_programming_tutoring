#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
ll dystanse[100002];
priority_queue<pair<ll, int>> pq;
vector <pair <int, ll >> graf[100002];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graf[u].push_back({v, w});
    }

    for (int i = 0; i <= n; i++){
        dystanse[i] = 1e18;
    }

    dystanse[1] = 0;
    pq.push({0, 1});

    while ( !pq.empty()){
            pair <ll, int> para = pq.top();

            ll waga_sciezki = -para.first;
            int v = para.second;

            pq.pop();

            if ( waga_sciezki > dystanse[v]) continue;

            for (int i = 0; i < graf[v].size(); i++){
                    int sasiad = graf[v][i].first;
                    int waga_do_sasiada = graf[v][i].second;

                    if ( dystanse[sasiad] > dystanse[v] + waga_do_sasiada){
                        dystanse[sasiad] = dystanse[v] + waga_do_sasiada;

                        pq.push({-dystanse[sasiad], sasiad});
                    }
            }
    }

    for (int i = 1; i <= n; i++){
        cout << dystanse[i] << " ";
    }
    cout << endl;
}
