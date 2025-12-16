class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> l;
        for (char& c : sentence) l.insert(c);

        return l.size() == 26;
    }
};