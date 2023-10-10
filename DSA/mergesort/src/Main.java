import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] arr = new int[]{5,2,2,4};
        arr = mergeSort(arr);
        Arrays.stream(arr).forEach(n -> System.out.print(n + " "));
    }

    private static int[] mergeSort(int[] arr) {
        if (arr.length < 2) {
            return arr;
        }
        int midIndx = arr.length / 2;
        int[] leftArr = Arrays.copyOfRange(arr, 0, midIndx);
        int[] rightArr = Arrays.copyOfRange(arr, midIndx, arr.length);
        return merge(mergeSort(leftArr), mergeSort(rightArr));
    }

    private static int[] merge(int[] a, int[] b) {
        int aIndex = 0;
        int bIndx = 0;
        int[] resultArr = new int[a.length + b.length];
        int resultArrIndx = 0;
        while (aIndex < a.length && bIndx < b.length) {
            if (a[aIndex] < b[bIndx]) {
                resultArr[resultArrIndx] = a[aIndex];
                resultArrIndx++;
                aIndex++;
            } else {
                resultArr[resultArrIndx] = b[bIndx];
                resultArrIndx++;
                bIndx++;
            }
        }
        for (int i = aIndex; i < a.length; i++) {
            resultArr[resultArrIndx] = a[i];
            resultArrIndx++;
        }
        for (int i = bIndx; i < b.length; i++) {
            resultArr[resultArrIndx] = b[i];
            resultArrIndx++;
        }
        return resultArr;
    }
}