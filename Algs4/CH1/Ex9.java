package CH1;

public class Ex9{
    public static void main(String[] args) {
        int N = 12;
        String s = "";
        for (int n = N; n > 0; n /= 2) {
            s = (n % 2) +s;
        }
        System.out.println(s);
    }
}