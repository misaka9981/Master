package leetcode;

class Solution1266 {
    public int minTimeToVisitAllPoints(int[][] points) {
        // int len = points.length;
        // int sec = 0;

        // for (int i = 0; i < len-1; i++) {
        //     sec += cal(points[i][i], points[i][i+1], points[i+1][i], points[i+1][i+1]);
        // }
        // return sec;
        int sum = 0;
        for (int i = 1; i < points.length; ++ i) {
            int xt = Math.abs(points[i][0]-points[i-1][0]);
            int yt = Math.abs(points[i][1]-points[i-1][1]);
            sum += Math.min(xt, yt) + Math.abs(yt-xt);
        }
        return sum;
    }
    // public int cal(int x1,int y1,int x2,int y2){
    //     int res = 0;
    //     res = (int)Math.sqrt(Math.pow((x1-x2),2) + Math.pow((y1-y2),2));
    //     return res;
    // }
}