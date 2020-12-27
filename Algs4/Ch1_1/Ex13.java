package Ch1_1;

import java.util.Scanner;


public class Ex13 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter M");
        int M = sc.nextInt();
        System.out.println("enter N");
        int N = sc.nextInt();
        int [][] mat = mat(M, N);
        int[][] newmat = new int[N][M];
        sc.close();
        for (int i = 0; i < mat[i].length; i++) {
            for (int j = 0; j < mat.length; j++) {
                newmat[i][j] = mat[j][i];
            }
        }
        System.out.println(newmat.toString());
    }
    private static int[][] mat(int M,int N) {
        int[][] res = new int[M][N];
        for (int i = 0; i < res.length; i++) {
            for (int j = 0; j < res[i].length; j++) {
                res[i][j] = (int)(1+Math.random()*10);
            }
        }
        return res;
    }
}