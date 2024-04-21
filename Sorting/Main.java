class Main{
     public static void main(String[] args) {

        int array[] = {2, 4, 1, 9, 34, 654};
        System.out.print("The unsorted array: ");
        for (int i : array) {System.out.print(i + " ");}

        InsertionSort(array);
        System.out.print("\n");
        System.out.print("Sorted: ");
        for (int i : array){ 
            System.out.print(i + " ");
        }

    }

    private static void InsertionSort(int[] array) {
        for (int index = 1; index < array.length; index++) {
            int index2 = index - 1; 
            int temp = array[index];

            while(index2 >= 0 && array[index2] > temp){
                array[index2 + 1] = array[index2];
                index2--;
            }
            array[index2 + 1] = temp; 
        }
    }
}