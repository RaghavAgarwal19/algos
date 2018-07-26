package sorts;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Raghav
 */
public class QuickSort {
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
        quickSort(a, 0, n-1);
        System.out.println("\nSortd Array :-");
        for(i=0;i<n;i++)
            System.out.println(a[i]);
    }

    private static void quickSort(int[] a, int l, int u) {
        int pivot;
        if(u > l){
            pivot = partition(a, l, u);
            quickSort(a, l, pivot-1);
            quickSort(a, pivot+1, u);
        }
    }

    private static int partition(int[] a, int l, int u) {
        int left = l+1, right = u;
        int pivot = a[l];
        while(left < right){
             while(left<=u && a[left] <= pivot)
                left++;
            while(a[right] > pivot && right>=l)
                right--;
            if(left < right){
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
            }
        }
        a[l] = a[right];
        a[right]=pivot;
        return right;
    }
}
