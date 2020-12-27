package Ch1_3;

public class Ex1<Item> {
    private String[] a;//stack netries
    private int N;//size
    public Ex1(int cap) {
        a = new String[cap];
    }
    public boolean isEmpty() {
        return N == 0;
    }
    public int size(){
        return N;
    }
    public void push(String item) {
        if (isFull()) {
            throw new RuntimeException("stack is full!");
        }
        a[N++] = item;
    }
    public String pop() {
        if (isEmpty()) {
            throw new RuntimeException("pop in an empty stack");
        }
        return a[--N];
    }
    public boolean isFull() {
        return N == a.length;
    }
        
}