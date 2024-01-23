#include <stdio.h>

int main() {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        j = i + 1;
        k = j + 1;
        printf("Philosopher %d is thinking\n", i);
        printf("Philosopher %d is eating\n", j);
        printf("Philosopher %d is eating\n", k);
    }
    return 0;
}