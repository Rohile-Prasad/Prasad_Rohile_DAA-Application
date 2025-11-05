#include <stdio.h>

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);

    int size[n];
    for (int i = 0; i < n; i++) {
        printf("Enter size of file %d: ", i + 1);
        scanf("%d", &size[i]);
    }

    sort(size, n);

    int total = 0;
    for (int i = 0; i < n - 1; i++) {
        size[i + 1] = size[i] + size[i + 1];
        total += size[i + 1];
        sort(size + i + 1, n - i - 1);
    }

    printf("\nMinimum total merge cost: %d\n", total);
    return 0;
}
