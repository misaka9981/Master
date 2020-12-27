package leetcode;
/*
 * @lc app=leetcode id=234 lang=java
 *
 * [234] Palindrome Linked List
 */


class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head ==null || head.next==null){
            return true;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast!=null && fast.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
        }   
        ListNode tmp=slow.next;
        ListNode newhead=null;
        slow.next=null;
        while(tmp!=null){
            ListNode cur=tmp.next;
            tmp.next=newhead;
            newhead=tmp;
            tmp=cur;
        }
        while(newhead!=null){
            if(newhead.val!=head.val){
                return false;
            }
            newhead=newhead.next;
            head=head.next;
        }
        return true;
        
    }
}
// @lc code=end

