#include <bits/stdc++.h>
using namespace std;
int n, t[300005];
unordered_map<int, int> count_left, count_right;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

  for (int i = 1; i <= n; i++) {
        cin >> t[i];
        count_right[t[i]]++;
  }

  int most_frequent_left_number = t[1];
  int most_frequent_left_number_count = 1;

  int answer = 0;
  for(int i = 1; i <= n; i++) {
        int length_left = i;
        int length_right = n - i;

        count_left[t[i]]++;
        count_right[t[i]]--;

        // update left potential leader
        if(most_frequent_left_number_count < count_left[t[i]]) {
            most_frequent_left_number_count = count_left[t[i]];
            most_frequent_left_number = t[i];
        }

        // check if left has a leader
        if(2 * most_frequent_left_number_count <= length_left) {
            continue;
        }

        //check if right has the same leader
        int potential_right_leader_count = count_right[most_frequent_left_number];

        if(2 * potential_right_leader_count > length_right) {
            answer++;
        }
  }

  cout << answer << endl;
}
