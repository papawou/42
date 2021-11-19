#ifndef		BASE_HELPERS_H
# define	BASE_HELPERS_H

#include "t_va.h"

#define _base_HEX "0123456789ABCDEF"
#define _base_hex "0123456789abcdef"
#define _base_10 "0123456789"
#define _va_base_HEX (t_va) {.s = _base_HEX, .len = 16}
#define _va_base_hex (t_va) {.s = _base_hex, .len = 16}
#define _va_base_10 (t_va) {.s = _base_10, .len = 10}

#endif