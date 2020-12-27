package Ch1_1;

public class Ex9{
    public static void main(String[] args) {
        int N = 12;
        String s = "";
        for (int n = N; n > 0; n /= 2) {
            s = (n % 2) +s;
        }
        System.out.println(s);
        Ex9 e = new Ex9();
        String a = e.getClass().getResource("/").getPath();    
        System.out.println(a);
    }
}