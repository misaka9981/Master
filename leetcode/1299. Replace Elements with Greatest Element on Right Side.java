package leetcode;

class Solution1299 {
    public int[] replaceElements(int[] arr) {
        int len = arr.length;
        if(len<2){
            arr[0]=-1;
            return arr;
        }
        for (int i = 0; i < len-2; i++) {
            arr[i]=arr[i+1];
            for(int j=i+2;j<len;++j){
                if(arr[j]>arr[i]){
                    arr[i]=arr[j];
                }
            }
        }
        arr[len-2]=arr[len-1];
        arr[len-1]=-1;
        return arr;

    
    }
}