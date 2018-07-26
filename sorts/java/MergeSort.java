package sorts;

import java.io.*;

/**
 *
 * @author Raghav
 */
public class MergeSort {
    public static int[] a;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter length : ");
        int n = Integer.parseInt(br.readLine());
        a = new int[n];
        int i;
        System.out.println("Enter array elements :");
        for(i=0;i<n;i++){
            System.out.print("Enter element " + (i+1) + " : ");
            a[i] = Integer.parseInt(br.readLine());
        }
        mergeSort(a, 0, n-1);
        System.out.println("\nSortd Array :- ");
        for(i=0;i<n;i++)
            System.out.println(a[i]);
    }

    private static void mergeSort(int[] a, int l, int u) {
        if(l<u){
            int mid = (l+u)/2;
            mergeSort(a, l, mid);
            mergeSort(a, mid+1, u);
            merge(a, l, mid, u);
        }
    }

    private static void merge(int[] a, int l, int mid, int u) {
        int[] b =new int[u-l+1];
        int i=l;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=u){
            if (a[i]<=a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        }
        while(i<=mid)
            b[k++] = a[i++];
        while(j<=u)
            b[k++] = a[j++];
        
        i=l;
        for(k=0;k<u-l+1;k++){
            a[i++]=b[k];
        }
        
    }
    
}
