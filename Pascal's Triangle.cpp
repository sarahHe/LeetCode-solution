// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//   [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (!numRows)   return res;
        
        vector<int> tmp1(1, 1);
        res.push_back(tmp1);
        for (int i = 1; i < numRows; i++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j < i; j++) {
                tmp.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
};


2015.3.12 update
//1ms faster and just use O(n) space
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows < 1)    return res;
        
        vector<int> dp;
        dp.push_back(1);
        res.push_back(dp);
        if (numRows == 1)
            return res;
        
        for (int i = 1; i < numRows; i++) {
            vector<int> tmp(dp);
            for (int j = 1; j < dp.size(); j++) {
                tmp[j] = dp[j] + dp[j-1];
            }
            tmp.push_back(1);
            dp.assign(tmp.begin(), tmp.end());
            res.push_back(tmp);
        }
        return res;
    }
};



2015.5.24 update
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0)   return res;
        for (int i = 1; i <= numRows; ++i) {
            vector<int> tmp (i, 1); // size is i;
            for (int j = 1; j < i-1; j++) // j = 1; j < i - 1
                tmp[j] = res[i-2][j-1] + res[i-2][j]; // res[i-2][]
            res.push_back(tmp);
        }
        return res;
    }
};
