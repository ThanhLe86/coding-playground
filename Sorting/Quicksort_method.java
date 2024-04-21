public class Quicksort_method {
    public static void main(String[] args) {
        int[] main_array = {7, 8, 5, 9, 31, 50, 4, 10, 9};
        System.out.print("The unsorted array: ");
        for (int i : main_array) System.out.print(i + " ");
        System.out.print("\n");

        Quicksort(main_array, 0, main_array.length - 1);

        System.out.print("The sorted array: ");
        for (int i : main_array) System.out.print(i + " ");
    }

    private static void Quicksort(int[] main_array, int StartPos, int EndPos) {
        if (EndPos <= StartPos) return;
        int pivot = Partition(main_array, StartPos, EndPos);
        Quicksort(main_array, StartPos, pivot - 1);
        Quicksort(main_array, pivot + 1, EndPos);
    }

    private static int Partition(int[] main_array, int startPos, int endPos) {
        int pivot = main_array[endPos];
        int index = startPos - 1;

        for (int index2 = startPos; index2 <= endPos - 1; index2++) {
            if (main_array[index2] < pivot)
            {
                index++;
                int temp = main_array[index2];
                main_array[index2] = main_array[index];
                main_array[index] = temp;
            }
        }
        index++;
        int temp = main_array[endPos];
        main_array[endPos] = main_array[index];
        main_array[index] = temp;

        return index;
    }    
}
