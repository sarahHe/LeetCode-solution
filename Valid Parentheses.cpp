class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1)
            return false;
        
        set<pair<char, char> >  match;
        match.insert({'(', ')'});
        match.insert({'[', ']'});
        match.insert({'{', '}'});
        set<char>   start;
        
        int i = 0;
        stack<int> stack;
        while (i < s.length()) {
            if (s[i] == '(' || s[i] =='[' || s[i] == '{')
                stack.push(s[i]);
            else {
                if (stack.empty())  return false;
                
                if (match.find({stack.top(), s[i]}) != match.end())
                    stack.pop();
                else 
                    return false;
            }
            i++;
        }
        if (!stack.empty()) return false;
        return true;
    }
};


2015.2.25 update:
class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1)
            return false;
        stack<char> stk;
        unordered_map<char, char> mp;
        mp['('] = ')'; mp['{'] = '}'; mp['['] = ']';
        for (int i = 0; i < s.length(); i++) {
            if (mp[s[i]] != '\0')
                stk.push(s[i]);
            else {
                if (stk.empty())
                    return false;
                else if (mp[stk.top()] != s[i])
                        return false;
                else 
                    stk.pop();
            }
        }
        return stk.empty();
    }
};



2015.5.28 update
class Solution {
public:
    bool isValid(string s) {
        //speed up the program;
        if (s.length() % 2 == 1)    return false;
        unordered_set<string> mySet = {"()", "{}", "[]"};
        stack<char> myStack;
        for (int i = 0; i < s.length(); i++) {
            if (myStack.empty()) {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                    myStack.push(s[i]);
                else
                    return false;
            } else {
                string tmp(1, myStack.top()); //!!
                tmp += string(1, s[i]);
                if (mySet.count(tmp) == 0)
                    myStack.push(s[i]); //!!
                else
                    myStack.pop();
            }
        }
        return myStack.empty(); //!!
    }
};
