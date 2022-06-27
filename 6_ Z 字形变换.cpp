class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> lines(numRows);
        int i = 0, flag = 1;
        for (char c : s) {
            lines[i].push_back(c);
            i += flag;
            if (i == -1 || i == numRows) {
                flag = -flag;
                i += 2 * flag;
            }
        }

        string res;
        for (const string& line : lines) {
            res += line;
        }
        return res;
    }
};
