package CH1;
/**
 * c1111
 */
public class Ex11 {
    public static void main(String[] args) {
        
        boolean[][] arr = new boolean[7][6];
        for(int i = 0; i < 7; i++) {
            for(int j = 0; j < 6; j++) {
                if(j > 2)
                    arr[i][j] = true;
                else
                    arr[i][j] = false;
            }
        }
        
        printBoolArr(arr);

    }
    
    public static void printBoolArr (boolean[][] arr) {
        System.out.print(' ');
        for (int i = 0; i < arr[0].length; i++) {
            System.out.println(i);
        }
        System.out.flush();
        for (int i = 0; i < arr.length; i++) {
            System.out.print(i);
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] ? '*' : ' ');
            }
            System.out.flush();
        }
    }

}