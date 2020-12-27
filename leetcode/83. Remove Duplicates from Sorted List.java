/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
package leetcode;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode pNode = head;
        while (pNode!=null && pNode.next!=null) {
            if (pNode.val==pNode.next.val) {
                pNode.next = pNode.next.next;
            }else{
                pNode = pNode.next;
            }
        }
        return head;
    }
}

