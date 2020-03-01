/*
 * @lc app=leetcode id=160 lang=java
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
package leetcode;
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution160 {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        for (ListNode a = headA; a != null; a=a.next) {
            for (ListNode b = headB; b != null; b=b.next) {
                if(a==b){
                    return a;
                }
            }
        }
        return null;
    }
}
// @lc code=end

