#include <stdio.h>
#include <stdlib.h>
#define RESET "\033[0m" // resets the terminal text color back to its default after printing colored text. 

int main() {
    FILE *file;
    char line[256];
    // define ANSI escape color codes
    const char *colors[] = {
        "\033[31m",    // RED
        "\033[38;5;214m", // ORANGE
        "\033[33m",    // YELLOW
        "\033[32m",    // GREEN
        "\033[34m",    // BLUE
        "\033[38;5;93m", // INDIGO
        "\033[35m"     // VIOLET
    };
    int colorIndex = 0;

    file = fopen("/mnt/c/Users/alvin/documents/vs/systprog/derrick.txt", "r"); //openign the .txt file in read mode
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    // fgets() reads a line of text from the file into the line array.
    while (fgets(line, sizeof(line), file)) {
        printf("%s%s%s", colors[colorIndex], line, RESET); //print the line in the current color
        colorIndex = (colorIndex + 1) % 7; //update to next color
    }

    fclose(file); 
    return 0;
}
