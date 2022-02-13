#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main()
{
    FILE *stream;
    size_t size;
    uint32_t fileSize = 0;
    char *input;
    int result1, result2;

    // Open file, find the size of it
    stream = fopen("4GB.bin", "rb");
    if (result1 = _fseeki64(stream, 0L, SEEK_END) != 0)
    {
        printf("_fseeki64 result1 error\n");
    }
    fileSize = _ftelli64(stream);

    if (result2 = _fseeki64(stream, 0L, SEEK_SET)!= 0)
    {
        printf("_fseeki64 result2 error\n");
    }

    input = (char *) malloc(fileSize + 1);

    if (input == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }


    //Stream file into memory
    size = fread(input, 1, fileSize, stream);
    input[size] = 0;
    fclose(stream);

    printf("size file is: %u\n", fileSize);

    free(input);

    return 0;

}
