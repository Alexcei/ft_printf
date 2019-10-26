#include "ft_printf.h"

void    parser_type(t_box *box, t_tab *tab)
{
	if (box->format[box->i] == 's' && ++box->i)
		output_s(box, tab);
	else if (box->format[box->i] == 'c' && ++box->i)
		output_c(box, tab);
	else if ((box->format[box->i] == 'i' || box->format[box->i] == 'd') && ++box->i)
		output_d(box, tab);
	else if (box->format[box->i] == 'u' && ++box->i)
		output_u(box, tab);
	else if (box->format[box->i] == 'U' && ++box->i && (tab->modifier_l += 2))
		output_u(box, tab);
	else if (box->format[box->i] == 'o' && ++box->i)
		output_o(box, tab);
	else if (box->format[box->i] == 'x' && ++box->i)
		output_x(box, tab, 'x');
	else if (box->format[box->i] == 'X' && ++box->i)
		output_x(box, tab, 'X');
	else if (box->format[box->i] == 'f' && ++box->i)
		output_f(box, tab);
	else if (box->format[box->i] == 'p' && ++box->i)
		output_p(box, tab);
	else if (box->format[box->i] == '%' && ++box->i)
		output_persent(box, tab);
}

void    parser_flag(t_box *box, t_tab *tab)
{
    int     i;

    i = box->i;
    if (box->format[box->i] == '-' && ++box->i)
        tab->flag_min = 1;
    if (box->format[box->i] == '+' && ++box->i)
        tab->flag_plus = 1;
    if (box->format[box->i] == ' ' && ++box->i)
        tab->flag_space = 1;
    if (box->format[box->i] == '0' && ++box->i)
        tab->flag_null = 1;
    if (box->format[box->i] == '#' && ++box->i)
        tab->flag_grid = 1;
    if (i != box->i)
        parser_flag(box, tab);
}

void    parser_modifier(t_box *box, t_tab *tab)
{
    int     i;

    i = box->i;
    if (box->format[box->i] == 'h' && ++box->i)
        tab->modifier_h += 1;
    if (box->format[box->i] == 'l' && ++box->i)
        tab->modifier_l += 1;
	if (box->format[box->i] == 'j' && ++box->i)
		tab->modifier_l += 1;
	if (box->format[box->i] == 'z' && ++box->i)
		tab->modifier_l += 1;
    if (box->format[box->i] == 'L' && ++box->i)
        tab->modifier_L = 1;
    if (i != box->i)
		parser_modifier(box, tab);
}

void	parser_number(t_box *box, t_tab *tab, int *pars)
{
	if ((!*pars || tab->wildcard) && ft_isdigit(box->format[box->i]))
	{
		*pars = 0;
		while (ft_isdigit(box->format[box->i]))
		{
			*pars *= 10;
			*pars += box->format[box->i] - '0';
			box->i++;
		}
	}
}

void	parser_wildcard(t_box *box, t_tab *tab, int *pars)
{
	int	i;

	if (box->format[box->i] == '*' && ++box->i)
	{
		tab->wildcard = 1;
		if ((i = (int)va_arg(box->av, int)))
		{
			*pars = FT_ABS(i);
			if (i < 0)
			{
				tab->precision = i % 10;
				tab->flag_min = 1;
			}
		}
		else
			tab->flag_null = 1;
	}
}

void    parser_form(t_box *box, t_tab *tab)
{
	int     i;

	i = box->i;
    parser_flag(box, tab);
	parser_wildcard(box, tab, &tab->width);
	parser_number(box, tab, &tab->width);
    if (box->format[box->i] == '.' && ++box->i)
    {
		tab->dot_prec++;
    	tab->precision = 0;
		parser_wildcard(box, tab, &tab->precision);
		parser_number(box, tab, &tab->precision);
	}
    parser_modifier(box, tab);
	if (i != box->i)
		parser_form(box, tab);
	else
		parser_type(box, tab);
}

void    parser(t_box *box, t_tab *tab)
{
    while (box->format[box->i])
    {
        if (box->format[box->i] == '%' && ++box->i)
        {
            ft_bzero(tab, sizeof(t_tab));
            parser_form(box, tab);
        }
        else
        {
            ft_putchar(box->format[box->i]);
            box->res++;
            box->i++;
        }
    }
}

