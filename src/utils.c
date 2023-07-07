#include <utils.h>

void fatal_err(const char* msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

char* bin2hex(const unsigned char* input, size_t len)
{
    char* result = NULL;
    char* hexs = "0123456789ABCDEF";

    if (input == NULL || len <= 0)
        return NULL;

    int result_len = (len*3) + 1;
    result = malloc(result_len);

    if (result == NULL)
        return NULL;
    
    // clear space for hex
    bzero(result, result_len);

    for (int i = 0; i < len; i++) {
        result[i*3] = hexs[input[i] >> 4];
        result[(i*3) + 1] = hexs[input[i] & 0x0F];
        result[(i*3) + 2] = ' ';
    }

    return result;
}