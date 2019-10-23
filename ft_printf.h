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
    int         sign;
    int         precision;
    int         dot_prec;
    int         flag_min;
    int         flag_plus;
    int         flag_space;
    int         flag_null;
    int         flag_grid;
    int         modifier_h;
    int         modifier_l;
    int         modifier_L;

    int dif;
}               t_tab;

# define PF_FLAG "-+ 0#"
# define PF_TYPE "scp%"

int     ft_printf(const char *format, ...);
void    parser(t_box *box, t_tab *tab);
void    parser_form(t_box *box, t_tab *tab);
void    output_s(t_box *box, t_tab *tab);
void    output_c(t_box *box, t_tab *tab);
void    output_p(t_box *box, t_tab *tab);
void    output_persent(t_box *box, t_tab *tab);
void    output_d(t_box *box, t_tab *tab);

#endif
