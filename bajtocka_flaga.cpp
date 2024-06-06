#include <bits/stdc++.h>
using namespace std;
int n;
int maxi_parz1, maxi_parz2, maxi_nparz1, maxi_nparz2;
int kand_parz1, kand_nparz1,  kand_parz2,  kand_nparz2;
int t[1000002], parz[1000002], nparz[1000002];

int main ()
{
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

  cin >> n;

  for (int i=1; i<=n; i++)
  {
      cin >> t[i];
  }

  for (int i=1; i<=n; i++)
  {
      if (i%2 == 0)
      {
          parz[t[i]]++;
      }
      else
      {
          nparz[t[i]]++;
      }

  }

  for (int i=1; i<=n; i++) {
      if (i%2 == 0)
      {
          if(t[i] == kand_parz1 || t[i] == kand_parz2)
            continue;

          if (parz[t[i]] > maxi_parz1) {
              maxi_parz2 = maxi_parz1;
              kand_parz2 = kand_parz1;
              maxi_parz1 = parz[t[i]];
              kand_parz1 = t[i];
          }
          else if (parz[t[i]] > maxi_parz2) {
              maxi_parz2 = parz[t[i]];
              kand_parz2 = t[i];
          }
      }
      else
      {
          if(t[i] == kand_nparz1 || t[i] == kand_nparz2)
            continue;

          if (nparz[t[i]] > maxi_nparz1) {
              maxi_nparz2 = maxi_nparz1;
              kand_nparz2 = kand_nparz1;
              maxi_nparz1 = nparz[t[i]];
              kand_nparz1 = t[i];
          }
          else if (nparz[t[i]] > maxi_nparz2) {
              maxi_nparz2 = nparz[t[i]];
              kand_nparz2 = t[i];
          }
      }
  }


//   cout << "maxi_parz1:" << maxi_parz1 << endl << "maxi_nparz1:" << maxi_nparz1 << endl << "maxi_parz2:" << maxi_parz2 << endl << "maxi_nparz2:" << maxi_nparz2 << endl;

  if ( kand_parz1 != kand_nparz1 )
  {
      cout << n - maxi_parz1 - maxi_nparz1;
      return 0;
  }
  int potencjalny_wynik, potencjalny_wynik2;

  if (kand_parz1 != kand_nparz2)
  {
      potencjalny_wynik = n - maxi_parz1 - maxi_nparz2;
  }
  if (kand_nparz1 != kand_parz2)
  {
      potencjalny_wynik2 = n - maxi_nparz1 - maxi_parz2;
  }

 cout << min (potencjalny_wynik, potencjalny_wynik2) << endl;

return 0;
}
