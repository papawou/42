#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

#include <stdint.h>
#include <stdbool.h>

void ft_putstr(char *s);
bool ft_isdigit(char c);
size_t ft_strlen(const char *s);
size_t	ft_strncpy_len(const char *src, const size_t src_len, char **dst, size_t n);
char *q_atoi_s(const char *s, int *nb);
size_t	q_itoa(const int nb, const char *base, char **dst);
bool ft_strchr_bool(const char *src, const char c);
size_t	q_utoa(const uintptr_t nb, const char *base, char **dst);
#endif