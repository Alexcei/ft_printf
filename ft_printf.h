#ifndef IT_IS_MY_PRINTF_FT_PRINTF_H
# define IT_IS_MY_PRINTF_FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef struct  s_box
{
    const char  *format;
    char        *str;
    int         res;
    int         i;
    va_list     av;

}               t_box;

typedef struct  s_tab
{
    int         len;
    int         width;
    int         dif;
    int         precision;
    int         flag_prec;
    int         flag;
}               t_tab;

int     ft_printf(const char *format, ...);
void    parser(t_box *box, t_tab *tab);
void    parser_form(t_box *box, t_tab *tab);
void    output_s(t_box *box, t_tab *tab);
void    output_c(t_box *box, t_tab *tab);

#endif
