/*
 * @lc app=leetcode id=2 lang=java
 *
 * [2] Add Two Numbers
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res = new ListNode();
        int carry = 0;
        while (l1.next!=null && l2.next!=null) {
            int val1 = l1?l1.val:0;
            int val2 = l2?l2.val:0;
            int val3 = val1+val2+carry;
            if(val3>10){
                val3 = val3 - 10;
                carry = 1;
            }
            else
                carry = 0;
            ListNode newNode = new ListNode(val3);
            
            newNode.next = null;
        }
    }
}

