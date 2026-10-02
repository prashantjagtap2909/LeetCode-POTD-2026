class Solution {
    vector<string> ans;

    void backtrack(string& s, int open, int close, int n) {
        // A complete valid combination is formed
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add '(' if we still have opening brackets available
        if (open < n) {
            s.push_back('(');

            backtrack(s, open + 1, close, n);

            // Undo the choice
            s.pop_back();
        }

        // Add ')' only when it is safe
        if (close < open) {
            s.push_back(')');

            backtrack(s, open, close + 1, n);

            // Undo the choice
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        ans.clear();

        string s;
        s.reserve(2 * n);

        backtrack(s, 0, 0, n);

        return ans;
    }
};
