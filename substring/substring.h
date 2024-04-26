# ifndef SUBSTRING_H
# define SUBSTRING_H


int *find_substring(char const *s, char const **words, int nb_words, int *n);
int is_valid_substring(char const *s, char const **words, int nb_words, int word_len);

# endif /* SUBSTRING_H */
