class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        int min_idx = INT_MAX;
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(freq[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};