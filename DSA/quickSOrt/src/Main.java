import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] arr = new int[]{5,2,2,3};
        quickSort(arr, 0, arr.length - 1);
        Arrays.stream(arr).forEach(e -> System.out.print(e + " "));
    }

    private static void quickSort(int[] arr, int start, int end) {
        if (start >= end) return;
        int pivotindx = partition(arr, start, end);
        quickSort(arr, start, pivotindx - 1);
        quickSort(arr, pivotindx + 1, end);

    }

    private static int partition(int[] arr, int start, int end) {
        int pivot = arr[end];

        int i = start - 1;
        for (int j = start; j <= end - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int t = arr[j];
                arr[j] = arr[i];
                arr[i] = t;
            }
        }
        i++;
        int t = arr[i];
        arr[i] = arr[end];
        arr[end] = t;
        return i;
    }
}