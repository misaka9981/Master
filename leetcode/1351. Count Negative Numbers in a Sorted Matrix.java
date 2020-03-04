package leetcode;

class Solution1351 {
    public int countNegatives(int[][] grid) {
        int res = 0;
        for (int[] is : grid) {
            for (int is2 : is) {
                if (is2 < 0) {
                    res++;
                }
            }
        }
        return res;
    }
}