#include <stdio.h>

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter number of products: ");
    scanf("%d", &n);

    int price[n];
    for (int i = 0; i < n; i++) {
        printf("Enter price of product %d: ", i + 1);
        scanf("%d", &price[i]);
    }

    quickSort(price, 0, n - 1);

    printf("\nProduct prices in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", price[i]);
    }
    printf("\n");

    return 0;
}
