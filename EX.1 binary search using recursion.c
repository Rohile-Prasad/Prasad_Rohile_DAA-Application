#include <stdio.h>

int binary_search(int a[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (a[mid] == key) return mid;
    if (key < a[mid]) return binary_search(a, low, mid - 1, key);
    return binary_search(a, mid + 1, high, key);
}

int main() {
    int n;
    printf("Enter number of registered roll numbers: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter roll numbers in sorted order:\n");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int key;
    printf("Enter roll number to search: ");
    scanf("%d", &key);

    int pos = binary_search(a, 0, n - 1, key);

    if (pos == -1)
        printf("Roll number %d not found in records.\n", key);
    else
        printf("Roll number %d found at position %d.\n", key, pos + 1);

    return 0;
}
