#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *stream;
    size_t size;
    int fileSize = 0;
    char *input;

    // Open file, find the size of it
    stream = fopen("3GB.bin", "rb");
    fseek(stream, 0L, SEEK_END);
    fileSize = ftell(stream);
    fseek(stream, 0L, SEEK_SET);

    input = (char *)malloc(fileSize + 1);

    // Stream file into memory
    size = fread(input, 1, fileSize, stream);
    input[size] = 0;
    fclose(stream);

    printf("size file is: %d\n", fileSize);

    free(input);

    return 0;
}
