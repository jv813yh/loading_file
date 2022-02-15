#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t  *loading_file(char *file, 
                        uint32_t *fileSize, 
                        int my_file);

int main() {

     char own_file[150];

    printf("you can enter file name\n");
    scanf("%s", own_file);

    uint8_t *data;
    uint32_t file_size = 0;


    data = loading_file(own_file, &file_size, 0);

    printf("size file is: %d\n", file_size);
    
    for(int i = 0; i < file_size; i++){
        printf("%c", data[i]);
    }


    free(data);


   

    return 0;
}

uint8_t *loading_file(char *file, uint32_t *fileSize, int my_file)
{   
    FILE *stream;
    uint8_t *input;
    uint32_t expected_size_file,
             range;

    /**
     * if my_file == 0 -> test file 
     * if my_file == 1 -> your file 
     * 
     * Creating our random test file
     * 
     */

    if(!my_file) 
    {
        if ((stream = fopen(file, "wb")) == NULL) 
        {
            printf("Failed to open file %s\n", file);
            exit(0);
        }

        int i = 0;

        printf("Enter the approximate file size in bytes: \n");
        scanf("%ld",&expected_size_file);
        expected_size_file = expected_size_file / 
                            (sizeof(expected_size_file) * sizeof(expected_size_file));
        printf("Enter max integer (range): \n");
        scanf("%ld",&range);

        while(i++ < expected_size_file)
        {
            fprintf(stream, "Number %lu. %lu, ", i,  rand() % range);
        }

        fprintf(stream, "\nThis is the end of the file being tested :)");

        if(fclose(stream) == EOF) printf("Failed to closed file\n");

    }

    if ((stream = fopen(file, "rb")) == NULL) 
    {
        printf("Failed to open file %s\n", file);
        exit(0);
    }

    fseek(stream, 0L, SEEK_END);
    *fileSize = ftell(stream);
    fseek(stream, 0L, SEEK_SET);

    input = (uint8_t *) malloc(*fileSize);
    if (input == NULL) 
    {
        printf("Memory not allocated.\n");
        exit(0);
    }

    fread(input, 1, *fileSize, stream);


    if(fclose(stream) == EOF) printf("Failed to closed file\n");

    return input;

}
