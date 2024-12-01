#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9999

int main(void) {
    int arr1[MAX];
    int arr2[MAX];
    int n = 0;

    // Our input loading sequence
    FILE *file;
    char buffer[MAX];
    file = fopen("input.txt", "r");

    while (fgets(buffer, sizeof(buffer), file)) {
        char num1[MAX] = {0};
        char num2[MAX] = {0};
        int i = 0, j = 0;

        // Parse num1
        while (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\0') {
            num1[i] = buffer[i];
            i++;
        }
        num1[i] = '\0';
        i++;  // Skip space

        // Parse num2
        while (buffer[i] != '\n' && buffer[i] != '\0') {
            num2[j++] = buffer[i++];
        }
        num2[j] = '\0';

        arr1[n] = atoi(num1);
        arr2[n] = atoi(num2);
        n++;
    }
    fclose(file);

    // Sort arr1
    for (int q = 0; q < n - 1; q++) {
        for (int r = q + 1; r < n; r++) {
            if (arr1[r] < arr1[q]) {
                int tmp = arr1[q];
                arr1[q] = arr1[r];
                arr1[r] = tmp;
            }
        }
    }

    // Sort arr2
    for (int q = 0; q < n - 1; q++) {
        for (int r = q + 1; r < n; r++) {
            if (arr2[r] < arr2[q]) {
                int tmp = arr2[q];
                arr2[q] = arr2[r];
                arr2[r] = tmp;
            }
        }
    }

    // Calculate the sum
    int sum = 0;
    for (int s = 0; s < n; s++) {
        int tmp = arr1[s] - arr2[s];
        if (tmp < 0) tmp = -tmp;
        sum += tmp;
    }

    printf("SUM: %d\n", sum);
    return 0;
}
