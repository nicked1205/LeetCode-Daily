/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *list = malloc(sizeof(struct ListNode));
    list->val = 0;
    list->next = NULL;
    bool prevExtra = false;
    struct ListNode *head = list;
    while (l1 != NULL || l2 != NULL || prevExtra) {
        int sum = 0;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        if (prevExtra) {
            sum++;
            prevExtra = false;
        }
        if (sum >= 10) prevExtra = true;

        head->next = malloc(sizeof(struct ListNode));
        head = head->next;
        head->val = sum % 10;
        head->next = NULL;
    }
    struct ListNode *res = list->next;
    free(list);
    return res;
}