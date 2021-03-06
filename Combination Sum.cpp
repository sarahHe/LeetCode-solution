// Given a set of candidate numbers (C) and a target number (T), 
// find all unique combinations in C where the candidate numbers sums to T.
// The same repeated number may be chosen from C unlimited number of times.
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.

class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> tmp, int pos, int sum, vector<int>& candidates, int target) {
        if (sum == target) {
            res.push_back(tmp);
            return;
        }
        
        for (int i = pos; i < candidates.size(); i++) {
            if (sum + candidates[i] > target)   return;
            
            tmp.push_back(candidates[i]);
            helper(res, tmp, i, sum + candidates[i], candidates, target); // next iteration pos = i
            tmp.pop_back(); // necessary even without &(tmp)
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end()); //sort first!
        helper(res, tmp, 0, 0, candidates, target);
        return res;
    }
};
