package leetcode;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution1290 {
    public int getDecimalValue(ListNode head) {
        ListNode tmp = head;
        int length=0,sum=0;
        while(tmp!=null){
            length++;
            tmp = tmp.next;
        }
        int tmplen = length;
        for(int i=1;i<=length;i++){
            if(head.val==1){
                sum+=1*Math.pow(2,tmplen-1);
                head = head.next;
                tmplen--;
            }else{
                head = head.next;
                tmplen--;
            }
        }
        return sum;
    }
}

class Test1290{
    public static void main(String[] args) {
        int[] l1 = {1,0,1};
        ListNode dummyRoot = new ListNode(0);
        ListNode ptr = dummyRoot;
        for(int item : l1) {
            ptr.next = new ListNode(item);
            ptr = ptr.next;
        }
        Solution1290 s1 = new Solution1290();
        System.out.println(s1.getDecimalValue(dummyRoot.next));
    }
}