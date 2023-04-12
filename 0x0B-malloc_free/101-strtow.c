#include <stdlib.h>
#include "main.h"

/**
 * word_count - count the number of words in a string
 * @str: the string to count words in
 *
 * Return: the number of words in the string
 */
static int word_count(char *str)
{
    int count = 0, in_word = 0;

    while (*str)
    {
        if (*str == ' ' || *str == '\t' || *str == '\n')
            in_word = 0;
        else if (in_word == 0)
        {
            in_word = 1;
            count++;
        }
        str++;
    }

    return (count);
}

/**
 * strtow - split a string into words
 * @str: the string to split
 *
 * Return: a pointer to an array of strings (words), or NULL on failure
 */
char **strtow(char *str)
{
    char **words;
    int count, word_len, i;
    char *word;

    if (str == NULL || *str == '\0')
        return (NULL);

    count = word_count(str);
    words = malloc(sizeof(char *) * (count + 1));
    if (words == NULL)
        return (NULL);

    i = 0;
    while (*str)
    {
        if (*str == ' ' || *str == '\t' || *str == '\n')
            str++;
        else
        {
            word_len = 0;
            while (str[word_len] && str[word_len] != ' '
                   && str[word_len] != '\t' && str[word_len] != '\n')
                word_len++;

            word = malloc(sizeof(char) * (word_len + 1));
            if (word == NULL)
            {
                while (--i >= 0)
                    free(words[i]);
                free(words);
                return (NULL);
            }

            for (int j = 0; j < word_len; j++)
                word[j] = str[j];
            word[word_len] = '\0';
            words[i++] = word;
            str += word_len;
        }
    }

    words[i] = NULL;
    return (words);
}
