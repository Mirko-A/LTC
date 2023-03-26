




boolean stringCompare(uint8_t *string1, uint8_t *string2)
{
    uint8_t str1_len = strlen(string1);
    uint8_t str2_len = strlen(string2);
    
    if (str1_len != str2_len) return FALSE;
    
    uint8_t current_char;
    
    for (current_char = 0; current_char < str1_len; current_char++)
    {
        if (string1[current_char] != string2[current_char]) return FALSE;
    }

    return TRUE;
}