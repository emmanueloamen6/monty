#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to execute Monty bytecode instructions
void execute_bytecode(const char *bytecode) {
    // Placeholder function for bytecode execution
    // You should implement this function to execute each bytecode instruction
    printf("Executing bytecode: %s\n", bytecode);
}

int main(int argc, char *argv[]) {
    // Check if the number of arguments is not exactly 2 (executable name + file path)
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    // Open the Monty byte code file for reading
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;
        // Remove newline character from the end of the line
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // Execute the Monty bytecode instruction
        execute_bytecode(line);

        // Check for errors during execution
        // For demonstration purposes, assume an error occurs if the bytecode contains the word "error"
        if (strstr(line, "error") != NULL) {
            fprintf(stderr, "Error occurred on line %d\n", line_number);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    // Close the file when done
    fclose(file);

    return 0;
}

