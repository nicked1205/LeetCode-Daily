class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int i = 1;
        if (words.size() == 1) return words;
        
        while (1) {
            if (areAnagrams(words[i], words[i - 1])) {
                words.erase(words.begin() + i);
            }
            else i++;

            if (i >= words.size()) break;
        }

        return words;
    }

    bool areAnagrams(string s1, string s2) {
        if (s1.length() != s2.length()) return false;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2;
    }
};