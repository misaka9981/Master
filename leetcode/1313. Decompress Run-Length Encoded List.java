package leetcode;

class Solution1313 {
    public int[] decompressRLElist(int[] nums) {
        int size = 0;
        for (int i = 0; i < nums.length; i+=2) {
            size += nums[i];
        }
        int res[] = new int[size], index = 0;
        for (int i = 0; i < nums.length / 2; i++) 
        for (int j = 0; j < nums[i * 2]; j++) 
        res[index++] = nums[i * 2 + 1];
        return res;
    }
}