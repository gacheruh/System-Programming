#include <stdio.h>

int main() {
    int num;
    FILE *file;

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Opening the file in write mode
    file = fopen("kenya.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the integer to the file
    fprintf(file, "%d", num);

    // Close the file
    fclose(file);

    printf("Integer saved successfully to Kenya.txt\n");
    return 0;
}
