#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9999

int main(void) {
    int arr1[MAX];
    int arr2[MAX];
    int n = 0;

    // Our input loading seqence
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

    // Compute the sum
    int sum = 0;
    for (int q = 0; q < n; q++) {
        int run_mult = 0;	// Running multiplier for each iteration
        for (int r = 0; r < n; r++) {
            if (arr2[r] == arr1[q]) {
                run_mult++;
            }
        }
        sum += arr1[q] * run_mult;
    }

    printf("SUM: %d\n", sum);
    return 0;
}
