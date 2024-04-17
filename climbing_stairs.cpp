// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> t(3, 0);
        t[1] = 1; t[2] = 2;
        
        for(int i = 3; i <= n; ++i) {
            t.push_back(t[i - 1] + t[i - 2]);
        }
        
        return t[n];
    }
};
