class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool>    match(s.length() + 1, false);
        match[0] = true;
        for (int i = 0; i < s.length(); i++) {
            if (match[i]) { //match[i] == true mens the string can be broken until i.
                for (int j = 1; j <= s.length() - i; j++) {//j <= s.length() - i
                    if (dict.find(s.substr(i, j)) != dict.end())
                        match[i + j] = true;
                }
            }
        }
        return match.back();
    }
};


Solution #2:
bool wordBreak(string s, unordered_set<string> &dict) {
    vector<bool> wordB(s.length() + 1, false);
    wordB[0] = true;
    for (int i = 1; i < s.length() + 1; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (wordB[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                wordB[i] = true;
                break; //只要找到一种切分方式就说明长度为i的单词可以成功切分，因此可以跳出内层循环。
            }
        }
    }
    return wordB[s.length()];
}
