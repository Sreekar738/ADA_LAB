#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int temp[100000];
    while (i <= mid && j <= high) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];
    for (i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int a[100000], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (i = 0; i < n; i++)
        a[i] = rand() % 100000;

    printf("\nGenerated Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    mergesort(a, 0, n - 1);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("\nTime taken to sort %d elements: %f seconds\n", n, cpu_time_used);

    return 0;
}
