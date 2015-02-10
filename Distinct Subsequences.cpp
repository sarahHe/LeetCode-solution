// Given a string S and a string T, count the number of distinct subsequences of T in S.
// A subsequence of a string is a new string which is formed from 
// the original string by deleting some (can be none) of the 
// characters without disturbing the relative positions of the 
// remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
// Here is an example:
// S = "rabbbit", T = "rabbit"
// Return 3.

class Solution {
public:
    int numDistinct(string S, string T) {
        if (S == "" || S.length() < T.length())
            return 0;
        vector<vector<int> > res(S.length() + 1, vector<int> (T.length() + 1, 0));
        for (int i = 0; i <= S.length(); i++)
            res[i][0] = 1;
        
        for (int i = 1; i <= S.length(); i++) {
            for (int j = 1; j <= T.length(); j++) {
                if (S[i-1] == T[j-1])
                    res[i][j] = res[i-1][j-1] + res[i-1][j];
                else
                    res[i][j] =  res[i-1][j];
            }
        }
        return res.back().back();
    }
};

//another solution using O(m) space
public int numDistinct(String S, String T) {
  if(T.length()==0)
  {
    return 1;
  }
  if(S.length()==0)
    return 0;
  int[] res = new int[T.length()+1];
  res[0] = 1;
  for(int i=0;i<S.length();i++)
  {
    for(int j=T.length()-1;j>=0;j--)
    {
      res[j+1] = (S.charAt(i)==T.charAt(j)?res[j]:0)+res[j+1];
    }
  }
  return res[T.length()];
}