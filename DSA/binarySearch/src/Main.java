import java.nio.file.ClosedFileSystemException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[] arr = new int[1024];
        for (int i = 0; i < 1024; i++) {
            arr[i] = i;
        }
        Scanner scanner = new Scanner(System.in);
        System.out.println("Number to find: ");
        int search = Integer.parseInt(scanner.nextLine());
        binarySearch(arr, search);
    }

    private static void binarySearch(int[] arr, int search) {
        int steps = 0;
        int l = 0;
        int r = arr.length - 1;
        while (r >= l) {
            int mid = (l + r) / 2;
            steps++;
            if (arr[mid] == search) {
                System.out.printf("Found in %d steps\n", steps);
                return;
            }
            else if (arr[mid] > search) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        System.out.print("Not found\n");
    }
}