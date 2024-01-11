import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] arr = new int[]{5, 2, 3, 6345, 5, 4, 36, 12, 34, 2, 4, 2, 4};
        bubblesort(arr);
        Arrays.stream(arr).forEach(i -> System.out.print(i + " "));
    }

    private static void bubblesort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] > arr[j]) {
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }

            }
        }
    }

    private static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int minIndx = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[minIndx]) {
                    minIndx = j;
                }
            }
            int temp = arr[minIndx];
            arr[minIndx] = arr[i];
            arr[i] = temp;

        }
    }

    private static void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
}