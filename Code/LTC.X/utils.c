#include "utils.h"

boolean stringCompare(byte string1[], byte string2[])
{
    byte str1_len = strlen((char *) string1);
    byte str2_len = strlen((char *) string2);
    
    if (str1_len != str2_len) return FALSE;
    
    byte current_byte;
    
    for (current_byte = 0; current_byte < str1_len; current_byte++)
    {
        if (string1[current_byte] != string2[current_byte]) return FALSE;
    }

    return TRUE;
}