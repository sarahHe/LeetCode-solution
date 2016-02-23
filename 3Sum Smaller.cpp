//Given an array of n integers nums and a target, find the number of index triplets i, j, k 
//with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

//For example, given nums = [-2, 0, 1, 3], and target = 2.
//Return 2. Because there are two triplets which sums are less than 2:
//[-2, 0, 1]
//[-2, 0, 3]
//Follow up:
//Could you solve it in O(n^2) runtime?

int threeSumSmaller(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        int j = i+1, k = nums.size()-1;
        while (j < k) {
            if (nums[i] + nums[j] + nums[k] >= target)
                k--;
            else {
                res += k - j;
                j++;
            }
        }
    }
    return res;
}