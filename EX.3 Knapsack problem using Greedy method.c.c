#include <stdio.h>

struct Item {
    int price;
    int value;
};

void sortItems(struct Item a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double r1 = (double)a[i].value / a[i].price;
            double r2 = (double)a[j].value / a[j].price;
            if (r1 < r2) {
                struct Item t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

double maximizeValue(struct Item a[], int n, int budget) {
    sortItems(a, n);
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (budget >= a[i].price) {
            totalValue += a[i].value;
            budget -= a[i].price;
        } else {
            totalValue += (double)a[i].value * budget / a[i].price;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, budget;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item a[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and price of item %d: ", i + 1);
        scanf("%d %d", &a[i].value, &a[i].price);
    }

    printf("Enter total budget: ");
    scanf("%d", &budget);

    double maxValue = maximizeValue(a, n, budget);
    printf("\nMaximum value that can be purchased: %.2f\n", maxValue);

    return 0;
}
