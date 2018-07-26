/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sorts;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author Raghav
 */
public class BucketSort {
    private static final int DEFAULT_BUCKET_SIZE = 10;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter length : ");
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        int i;
        System.out.println("Enter array elements :");
        for(i=0;i<n;i++){
            System.out.print("Enter element " + (i+1) + " : ");
            a[i] = Integer.parseInt(br.readLine());
        }
        a = binSort(a);
        System.out.println("\nSortd Array :- ");
        for(i=0;i<n;i++)
            System.out.println(a[i]);
    }

    private static int[] binSort(int[] a) {
        int l = a.length;
        int min = a[0];
        int max = a[0];
        int i;
        for (i = 1; i < a.length; i++) {
            if (a[i] < min) {
                min = a[i];
            } else if (a[i] > max) {
                max = a[i];
            }
        }
        int bucketCount = (max - min) / DEFAULT_BUCKET_SIZE + 1;
        List<List<Integer>> bucket = new ArrayList<List<Integer>>(bucketCount);
        for (i = 0; i < bucketCount; i++) {
            bucket.add(new ArrayList<Integer>());
        }
        for(i=0;i<l;i++){
            bucket.get((a[i]-min)/DEFAULT_BUCKET_SIZE).add(a[i]);
        }
        
        int c = 0;
        for(i=0;i<bucket.size();i++){
            Integer[] bucketArray = new Integer[bucket.get(i).size()];
            bucketArray = bucket.get(i).toArray(bucketArray);
            Arrays.sort(bucketArray);
            for (int j = 0; j < bucketArray.length; j++) {
                a[c++] = bucketArray[j];
            }
        }
        return a;
    }
}
