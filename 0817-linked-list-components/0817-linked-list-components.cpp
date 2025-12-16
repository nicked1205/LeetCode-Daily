/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> inNums;
        for (auto& num : nums) {
            inNums[num]++;
        }
        ListNode* cur = head;
        int res = 0;
        bool comp = false;
        while (cur) {
            if (!inNums[cur->val]) {
                if (comp) res++;
                comp = false;
            } else comp = true;
            cur = cur->next;
        }
        if (comp) res++;

        return res;
    }
};