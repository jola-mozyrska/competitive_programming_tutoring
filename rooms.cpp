#include<bits/stdc++.h>
using namespace std;

int n, m;
bool t[1003][1003];
bool czy_odwiedzony[1003][1003];

int idz_x[4] = {1, 0, -1, 0};
int idz_y[4] = {0, 1, 0, -1};


void dfs(int rzad, int kolumna) {
    // cout << "Jestem na polu " << rzad << " " << kolumna << endl;
    // zaznacz jako odwiedzony
    czy_odwiedzony[rzad][kolumna] = true;

    //     t[rzad+1][kolumna]
    //     t[rzad][kolumna+1]
    //     t[rzad-1][kolumna]
    //     t[rzad][kolumna-1]
    for(int i = 0; i < 4; ++i) {
        int nowy_rzad = rzad + idz_x[i];
        int nowa_kolumna = kolumna + idz_y[i];

        if(nowy_rzad >= 0 && nowy_rzad < n && nowa_kolumna >= 0 && nowa_kolumna < m && t[nowy_rzad][nowa_kolumna] && !czy_odwiedzony[nowy_rzad][nowa_kolumna]) {
            dfs(nowy_rzad, nowa_kolumna);
        }
    }
}


int main() {
    // speed up cin and cout
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // t[0....n-1][0....m-1]

    string s;
    for(int rzad = 0; rzad < n; ++rzad) {
        cin >> s;
        for(int kolumna = 0; kolumna < m; ++kolumna) {
            if(s[kolumna] == '.') {
                t[rzad][kolumna] = true;
            }
            else {
                t[rzad][kolumna] = false;
            }
        }
    }

    int ile_pokoi = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(t[i][j] && !czy_odwiedzony[i][j]) {
                ile_pokoi++;
                dfs(i, j);
            }
        }
    }

    cout << ile_pokoi << endl;



//     t[rzad][kolumna]

//     t[rzad+1][kolumna]
//     t[rzad][kolumna+1]
//     t[rzad-1][kolumna]
//     t[rzad][kolumna-1]
}
