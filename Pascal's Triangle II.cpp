// Given an index k, return the kth row of the Pascal's triangle.
// For example, given k = 3,
// Return [1,3,3,1].
// Note:
// Could you optimize your algorithm to use only O(k) extra space?

// use a tmp vector to store the previous info
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1, 0);
        dp[0] = 1;
        vector<int> tmp = dp;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = 0; j < i; j++) 
                dp[j+1] += tmp[j];
            tmp = dp;
        }
        return dp;
    }
};


2015.5.24 update
//reduce time from to 0ms
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //k start from 0
        vector<int> row(rowIndex+1, 1);
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) { // j start from i - 1 instead of 1, to avoid override
                row[j] += row[j-1];
            }   
        }
        return row;
    }
};
