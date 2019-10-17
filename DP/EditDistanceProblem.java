public class EditDistanceProblem{
    public int editDistanceRecursion(String s1,String s2,int m,int n){
        if(m==0)
            return n;
        if (n==0)
            return m;

        if(s1.charAt(m-1)==s2.charAt(n-1))
            return editDistanceRecursion(s1,s2,m-1,n-1);

        return 1 + Math.min(editDistanceRecursion(s1, s2, m, n-1), //Insert
                Math.min(editDistanceRecursion(s1, s2, m-1, n), // Remove
                        editDistanceRecursion(s1, s2, m-1, n-1))); //Replace
    }

    public static void main(String[] args) {
        String s1 = "cat";
        String s2 = "dog";
        EditDistanceProblem ed = new EditDistanceProblem();
        int res = ed.editDistanceRecursion(s1, s2, s1.length(), s2.length());
        System.out.println("Minimum Edit Distance -(Recursion): " + res);
    }
}

