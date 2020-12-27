package Ch1_1;

public class Ex14 {
    public static void main(String[] args) {
        System.out.println(lg(8));
    }
    public static int lg(int N) {
        
        int i = 0;
        while(n2(i) <= N)
            i++;
        return i-1;
    }
    
    public static int n2(int n) {
        int result = 1;
        for(int i = 0; i < n; i++)
            result *= 2;
        return result;
    }

}