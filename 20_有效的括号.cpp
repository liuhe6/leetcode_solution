class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m;
        m.insert(make_pair(')', '('));
        m.insert(make_pair(']', '['));
        m.insert(make_pair('}', '{'));
        stack<char> my_stack;
        for(auto c : s) {
            if(!m.count(c)) my_stack.push(c);
            else if(my_stack.size() && m[c] == my_stack.top()) my_stack.pop();
            else return false;
        }
        return my_stack.empty();
    }
};