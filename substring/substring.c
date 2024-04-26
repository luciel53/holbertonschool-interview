#include <stdlib.h>
#include <string.h>

/**
 * compare_words - function to compare words
 * @word1: first word
 * @word2: second word
 * @word_len: length of the word
 * Return: string comparison result
 */
int compare_words(const char *word1, const char *word2, int word_len)
{
return (strncmp(word1, word2, word_len));
}

/**
 * find_substring - function that finds all the possible substrings
 * @s: the string to scan
 * @words: is the array of words all substrings
 * @nb_words: the number of elements in the array words
 * @n: store the number of elements in the returned array
 * Return: allocated array, storing each index in s
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
int word_len = strlen(words[0]);
int s_len = strlen(s);
int total_len = word_len * nb_words;
int *indices = NULL;
int i;
if (total_len > s_len)
{
*n = 0;
return (NULL);
}
indices = malloc(0 * sizeof(int));
*n = 0;
for (i = 0; i <= s_len - total_len; i++)
{
int found_all_words = 1;
int j;
int *used_words = malloc(nb_words * sizeof(int));
memset(used_words, 0, nb_words * sizeof(int));
for (j = i; j < i + total_len; j += word_len)
{
int found_word = 0, k;
for (k = 0; k < nb_words; k++)
{
if (!used_words[k] && compare_words(s + j, words[k], word_len) == 0)
{
found_word = 1;
used_words[k] = 1;
}
}
if (!found_word)
{
found_all_words = 0;
}
}
if (found_all_words)
{
*n = *n + 1;
indices = realloc(indices, *n * sizeof(int));
indices[*n - 1] = i;
}
}
return (indices);
}
