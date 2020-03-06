package leetcode;


class Solution1252 {
    public int oddCells(int n, int m, int[][] indices) {
        int[][] obj = new int[n][m];
        int res = 0;
        for(int i=0; i<indices.length; i++){
            
            for(int j=0; j<m; j++){
                obj[indices[i][0] ][j] += 1; 
            }
            
            for(int k=0; k<n; k++){
                obj[k][ indices[i][1] ] += 1; 
            }
        }
        
        for(int a=0; a<n; a++){
            for(int b=0; b<m; b++){
                if(obj[a][b] % 2!=0){
                    res++;
                }
            }
        }

        return res;
    }
}