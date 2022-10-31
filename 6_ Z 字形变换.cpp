class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> lines(numRows);
        int i = 0, flag = 1; //flag控制的是方向，1是向下，-1 是向上
        for (char c : s) {
            lines[i].push_back(c);
            i += flag;
            if (i == -1 || i == numRows) {
                flag = -flag; // 当到底或者到顶的时候，改变方向
                i += 2 * flag; // 改变方向后，并回到正确的位置，以i = -1为例，这时i=0的位置已经添加完成，需要添加的是i=1的位置，所以是i+=2
            }
        }

        string res;
        for (const string& line : lines) {
            res += line;
        }
        return res;
    }
};
