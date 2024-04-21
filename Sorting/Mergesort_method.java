class Mergesort_method{
     public static void main(String[] args) {
        int[] array = {12, 32, 1, 90, 54, 78, 11};

        System.out.print("The unsorted array: ");
        for(int i : array) System.out.print(i + " ");

        MergeSort(array);
        System.out.print("\n");
        System.out.print("Sorted: ");
        for(int i : array) System.out.print(i + " ");
    }

    private static void MergeSort(int[] array) {
        int l = array.length;
        if (l <= 1) return;
        else {
            int midl = l/2;
            int[] leftpart = new int[midl];
            int[] rightpart = new int[l - midl];
            int right_index = 0;
            for (int i = 0; i < l; i++) {
                if (i < midl) leftpart[i] = array[i];
                else{
                    rightpart[right_index] = array[i];
                    right_index++;
                }
            }
            MergeSort(rightpart);
            MergeSort(leftpart);
            Merge(leftpart, rightpart, array);            
        }
    }

    private static void Merge(int[] leftArray, int[] rightArray, int[] OGarray) {
        int OG_index = 0;
        int left_index = 0;
        int right_index = 0;
        while (left_index < leftArray.length && right_index < rightArray.length)
        {    
            if(leftArray[left_index] < rightArray[right_index])
            {
                OGarray[OG_index] = leftArray[left_index];
                left_index++;
            } else {
                OGarray[OG_index] = rightArray[right_index];
                right_index++;
            }
            OG_index++;
        }
        
        while (left_index < leftArray.length)
        {
            OGarray[OG_index] = leftArray[left_index];
            OG_index++;
            left_index++;
        }

        while (right_index < rightArray.length)
        {
            OGarray[OG_index] = rightArray[right_index];
            OG_index++;
            right_index++;
        }
    }
}

