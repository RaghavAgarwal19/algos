package sorts;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 *
 * @author Raghav
 */
public class CountingSort {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter length : ");
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        int[] sorted = new int[n];
        int[] count = new int[256];
        Arrays.fill(count, 0);
        int i;
        System.out.println("Enter array elements :");
        for(i=0;i<n;i++){
            System.out.print("Enter element " + (i+1) + " : ");
            a[i] = Integer.parseInt(br.readLine());
        }
        for(i=0;i<n;i++)
            ++count[a[i]];
        for(i=1;i<256;i++)
            count[i] = count[i] + count[i-1];
        for(i=0;i<n;i++){
            sorted[count[a[i]] - 1] = a[i];
            --count[a[i]];
        }
        System.out.println("\nSortd Array :-");
        for(i=0;i<n;i++)
            System.out.println(sorted[i]);
    }
}
