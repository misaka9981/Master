package leetcode;
/*
 * @lc app=leetcode id=203 lang=java
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
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

class Solution203 {
    public ListNode removeElements(ListNode head, int val) {
        ListNode res = new ListNode(0);
        res = head;
        ListNode tmp = res;
        while (tmp.next!=null) {
            if (tmp.next.val==val) {
                tmp.next=tmp.next.next;
            }else{
                tmp = tmp.next;
            }
        }
        return res;
    }
}
// @lc code=end

