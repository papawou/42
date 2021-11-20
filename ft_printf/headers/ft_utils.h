#ifndef FT_UTILS_H
# define FT_UTILS_H

#include <stdint.h>
#include <stdbool.h>

#include "t_flags.h"
#include "t_va.h"

bool		ft_strchr_bool(const char *src, const char c);
bool		ft_isdigit(char c);
int			ft_strlen(const char *s);
char		*atoi_s(const char *s, int *nb);
t_va		utoa(const uintptr_t nb, const t_va va_base);

#endif