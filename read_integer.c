#include <stdio.h>

int main() {
    int num;
    FILE *file;

    file = fopen("kenya.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the integer from the file
    fscanf(file, "%d", &num);

    fclose(file);

    printf("The integer read from kenya.txt is: %d\n", num);
    return 0;
}
