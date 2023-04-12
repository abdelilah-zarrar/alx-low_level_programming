#include <stdlib.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str)
{
    int count = 0, i = 0;
    while (str[i] != '\0')
    {
        while (is_space(str[i])) i++;
        if (str[i] != '\0')
        {
            count++;
            while (!is_space(str[i]) && str[i] != '\0') i++;
        }
    }
    return count;
}

char *copy_word(char *str, int start, int end)
{
    char *word;
    int i;
    word = malloc(end - start + 2);
    if (word == NULL) return NULL;
    for (i = start; i <= end; i++)
        word[i - start] = str[i];
    word[i - start] = '\0';
    return word;
}

char **strtow(char *str)
{
    int i, j, k, n, count;
    char **words;
    if (str == NULL || str[0] == '\0') return NULL;
    count = count_words(str);
    words = malloc(sizeof(char *) * (count + 1));
    if (words == NULL) return NULL;
    for (i = 0, k = 0; i < count; i++)
    {
        while (is_space(str[k])) k++;
        j = k;
        while (!is_space(str[j]) && str[j] != '\0') j++;
        n = j - k;
        words[i] = copy_word(str, k, j-1);
        if (words[i] == NULL)
        {
            for (j = 0; j < i; j++) free(words[j]);
            free(words);
            return NULL;
        }
        k = j;
    }
    words[count] = NULL;
    return words;
}
