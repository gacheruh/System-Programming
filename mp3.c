#include <stdio.h>
#include <stdlib.h>

int main() {
    // Path to the output file 
    const char *outputFilePath = "/mnt/c/Users/alvin/documents/vs/systprog/derrick.txt";

    // Build the command to search for .mp3 files in the Music folder using the snprintf() command
    // snprintf formats the string and stores it in the 'command' variable.
    // `-type f` ensures only files are searched
    // `-exec ls -lh {} +` executes `ls -lh` on found files in a human-readable format, and `> \"%s\"` redirects the output to the specified file path (where `%s` will be replaced by `outputFilePath`).
    char command[512];
    snprintf(command, sizeof(command), 
             "find /mnt/c/Users/alvin/Music -type f -name \"*.mp3\" -exec ls -lh {} + > \"%s\"", 
             outputFilePath);

    // The system() function executes a shell command specified by the string passed to it in this case the output of the snprintf() funtion
    int result = system(command);

    if (result == -1) {
        perror("Error executing system command");
        return 1; //if command fails return an error code
    }

    printf("The .mp3 file list has been saved to %s\n", outputFilePath);
    return 0;
}
