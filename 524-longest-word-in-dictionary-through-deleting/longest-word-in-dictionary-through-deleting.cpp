class Solution {
public:
    bool solve(string &s, string &p) {
        int i = 0, j = 0;

        while(i < s.size() && j < p.size()) {
            if(s[i] == p[j]) {
                j++;
            }
            i++;
        }

        return j == p.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end());

        string ans = "";

        for(int i = 0; i < dictionary.size(); i++) {
            if(solve(s, dictionary[i])) {
                if(dictionary[i].size() > ans.size()) {
                    ans = dictionary[i];
                }
            }
        }

        return ans;
    }
};