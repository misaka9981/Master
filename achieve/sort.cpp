#include <iostream>
using namespace std;

void insert_sort(int *a, int n)
{
    int i,j;
    for(i=1;i<n;i++){
        int temp = a[i];
        for(j=i-1;j>=0;j--){
            if(a[j] > a[i]){
                a[j+1] = a[j];
            }else{
                break;
            }
        }
        a[j+1] = temp;
    }
}

void select_sort(int *a,int n)
{
    int i;        // 有序区的末尾位置
    int j;        // 无序区的起始位置
    int min;    // 无序区中最小元素位置

    for(i=0; i<n; i++)
    {
        min=i;

        for(j=i+1; j<n; j++)
        {
            if(a[j] < a[min])
                min=j;
        }

        //若min!=i，则交换 a[i] 和 a[min]。
        //交换后，保证了a[0]..a[i]之间元素有序。
        if(min != i)
            swap(a[i], a[min]);
    }
        
}

void sorttest(){
    int a[] = {12,15,9,20,6,31,24};
    int n = 7;
    select_sort(a,n);
    for (int i=0; i<sizeof(a)/sizeof(a[0]); i++){
        printf(" %d ", a[i]);
    }
    printf("\n");
    
}

int main()
{
    sorttest();
    return 0;
}