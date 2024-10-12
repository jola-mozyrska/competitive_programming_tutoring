#include <bits/stdc++.h>
using namespace std;
int odwiedzone[200001], poprzednicy[200001];
vector <int> graf [200001];
vector <int> cykl, wierzcholki;
bool t[200001];
int n, m, licznik, poczatek_cyklu, koniec_cyklu;
bool mamy_cykl;
 
void dfs ( int w)
{
    if ( mamy_cykl == true) return;
  odwiedzone[w] = 1;
 
  for (int i=0; i<graf[w].size(); i++)
  {
      int sasiad = graf[w][i];
      if (odwiedzone[sasiad] != 1)
      {
          poprzednicy[sasiad] = w;
          dfs(sasiad);
          if (mamy_cykl == true) return;
      }
     else if ( sasiad != poprzednicy[w])
     {
        poczatek_cyklu = sasiad; //1
        koniec_cyklu = poprzednicy[w]; //5
 
        cykl.push_back(poczatek_cyklu);
        cykl.push_back(w);
        cykl.push_back(koniec_cyklu);
 
        while ( poczatek_cyklu != koniec_cyklu)
        {
          koniec_cyklu = poprzednicy[koniec_cyklu];
          cykl.push_back(koniec_cyklu);
        }
        mamy_cykl = true;
        return;
     }
 
 
 
  }
 
 
 
 
}
 
int main ()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
 
    int a, b;
    for (int i=0; i<m; i++)
    {
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
        if ( t[a] == false ) {wierzcholki.push_back(a); t[a] = true;}
        if ( t[a] == false ) {wierzcholki.push_back(b); t[b] = true;}
    }
 
   for (int i=0; i<wierzcholki.size(); i++)
   {
       if (mamy_cykl == false && odwiedzone[wierzcholki[i]] == false) dfs(wierzcholki[i]);
   }
 
    if ( mamy_cykl != true )
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    licznik = cykl.size();
 
    cout << licznik << endl;
 
    for (int i=0; i<licznik; i++)
    {
        cout << cykl[i] << " ";
    }
 
   return 0;
}
