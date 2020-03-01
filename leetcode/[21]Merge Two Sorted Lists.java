package leetcode;
//Merge two sorted linked lists and return it as a new list. The new list should
// be made by splicing together the nodes of the first two lists. 
//
// Example:
// 
//Input: 1->2->4, 1->3->4
//Output: 1->1->2->3->4->4
// 
// Related Topics Linked List


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode pNode = head;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                pNode.next = l1;
                l1 = l1.next;
            } else {
                pNode.next = l2;
                l2 = l2.next;
            }
            pNode = pNode.next;
        }
        if (l1 != null) {
            pNode.next = l1;
        } else if (l2 != null) {
            pNode.next = l2;
        }
        return head.next;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
