package leetcode;
//Given a non-empty, singly linked list with head node head, return a middle nod
//e of linked list. 
//
// If there are two middle nodes, return the second middle node. 
//
// 
//
// 
// Example 1: 
//
// 
//Input: [1,2,3,4,5]
//Output: Node 3 from this list (Serialization: [3,4,5])
//The returned node has value 3.  (The judge's serialization of this node is [3,
//4,5]).
//Note that we returned a ListNode object ans, such that:
//ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next =
// NULL.
// 
//
// 
// Example 2: 
//
// 
//Input: [1,2,3,4,5,6]
//Output: Node 4 from this list (Serialization: [4,5,6])
//Since the list has two middle nodes with values 3 and 4, we return the second 
//one.
// 
//
// 
//
// Note: 
//
// 
// The number of nodes in the given list will be between 1 and 100. 
// 
// 
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

class Solution876 {
    public ListNode middleNode(ListNode head) {
        int length = 0;
        ListNode tmp = head;
        while (tmp!=null) {
            length++;
            tmp = tmp.next;
        }
        if(length%2==0) {
            for (int i = 0; i < ((length/2)+1); i++) {
                head = head.next;
            }
        }else{
            for (int i = 0; i < length/2; i++) {
                head = head.next;
            }
        }
        return head;
    }
}

class Test876{
    public static void main(String[] args) {
        int[] l1 = {1,2,3,4,5};
        ListNode dummyRoot = new ListNode(0);
        ListNode ptr = dummyRoot;
        for(int item : l1) {
            ptr.next = new ListNode(item);
            ptr = ptr.next;
        }
        Solution876 s2 = new Solution876();
        s2.middleNode(dummyRoot.next);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
