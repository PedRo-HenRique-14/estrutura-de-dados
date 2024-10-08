/* 
 * Código extraido de https://www.geeksforgeeks.org/heap-sort/
 */

#include <stdio.h>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()
#include <time.h>

long times[3][10];
long changes[3][10];
long comparison[3][10];

// To heapify a subtree rooted with node i
// which is an index in arr[].
void heapify(int arr[], int n, int i, long *changes, long *comparison) {

    // Initialize largest as root
    int largest = i; 

    // left index = 2*i + 1
    int l = 2 * i + 1; 

    // right index = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    comparison++;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    comparison++;

    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        changes++;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, changes, comparison);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n, long *changes, long *comparison) {

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, changes, comparison);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {

        // Move current root to end
        int temp = arr[0]; 
        arr[0] = arr[i];
        arr[i] = temp;
        changes++;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0, changes, comparison);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void gerar_vetor(int *vetor, int n, int opt) {
    int j, aux;
    switch (opt) {
        case 1: // Ordenado
            for(int i = 0; i < n; i++) {
                vetor[i] = i;
            }
            break;
    
        case 2: // Decrescente
            j = n - 1;
            for(int i = 0; i < n; i++) {
                vetor[i] = j--;
            }
            break;

        case 3: // Aleatório
            for(int i = 0; i < n; i++) {
                vetor[i] = i;
            }

            srand(time(0));
            for(int i = 0; i < n; i++) {
                j = rand() % n;
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
            break;
    }
}

/* void printInfo() {
    for(int caso = 0; caso < 3; caso++) {
        for(int casoExecNum = 0; casoExecNum < 10; casoExecNum++) {
            
        }
    }
} */

// Driver's code
int main() {

    const int n = 10;
    int arr[n];

    for(int caso = 1; caso <= 3; caso++) {
        for(int casoExecNum = 0; casoExecNum < 10; casoExecNum++) {
            // Vamos fingir que estamos entendendo
            // Para garantir, não mexa, por favor :)
            changes[caso][casoExecNum] = 0;
            comparison[caso][casoExecNum] = 0;

            gerar_vetor(arr, n, caso);

            clock_t start = clock();
            heapSort(arr, n, &changes[caso - 1][casoExecNum], &comparison[caso - 1][casoExecNum]);
            clock_t end = clock();
            times[caso - 1][casoExecNum] = ((long)(end-start));
        }
    }



    printf("Sorted array is \n");
    printArray(arr, n);
    return 0;
}