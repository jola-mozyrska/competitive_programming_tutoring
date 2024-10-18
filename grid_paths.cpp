#include <bits/stdc++.h>
using namespace std;
char t[1002][1002];
int oznaczenie[1002][1002];
int n;
long long modulo = 1000 * 1000 * 1000 + 7;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);



  cin >> n;

  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < n; j++)
      {
          cin >> t[i][j];
          if ( t[i][j] == '*') oznaczenie[i][j] = 0;
      }
  }
  
  if(t[0][0] == '*') {
    cout << 0;
    return 0;
  }
  

 oznaczenie[0][0] = 1;

  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < n; j++)
      {
        if(i == 0 and j == 0) continue;
        if(t[i][j] == '*') continue;

		int wart_z_gory = 0;
		if(i - 1 >= 0) wart_z_gory = oznaczenie[i-1][j];

		int wart_z_lewej = 0;
		if(j - 1 >= 0)  wart_z_lewej = oznaczenie[i][j-1];

        oznaczenie[i][j] = (wart_z_gory + wart_z_lewej) % modulo;
      }
  }


  cout << oznaczenie[n - 1][n - 1] << endl;

 return 0;
}
