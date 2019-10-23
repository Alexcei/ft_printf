#include "ft_printf.h"

static void     print_hex(unsigned long n)
{
    if (n >= 16)
        print_hex(n / 16);
    n = n % 16;
    n += n < 10 ? '0' : 'a' - 10;
    write(1, &n, 1);
}

static void		ft_putchar_count(t_box *box, char c)
{
	ft_putchar(c);
	box->res++;
}

static void    put_sign(t_box *box, t_tab *tab)
{
    if (tab->flag_plus && !tab->sign)
		ft_putchar_count(box, '+');
    if (tab->sign)
		ft_putchar_count(box, '-');
    else if (tab->flag_space && !tab->flag_plus)
		ft_putchar_count(box, ' ');;
}

static void    put_dif(t_box *box, t_tab *tab)
{
	if (tab->flag_space || tab->flag_plus || tab->sign)
		tab->width--;
	if (tab->flag_null && !tab->dot_prec)
	{
		put_sign(box, tab);
		while (tab->width-- > 0)
			ft_putchar_count(box, '0');
	}
	else
    {
		if (!tab->flag_min)
		{
			while (tab->width-- > 0)
				ft_putchar_count(box, ' ');;
		}
        put_sign(box, tab);
    }
	while (tab->precision--  > 0)
		ft_putchar_count(box, '0');;
}

void    output_d(t_box *box, t_tab *tab)
{
    int     n;

	n  = (int)va_arg(box->av, int);
	if (n < 0 && ++tab->sign)
		n *= -1;
	if ((tab->len = ft_intlen(n)))
		box->res += tab->len;
	if (n == 0 && tab->dot_prec)
	{
		tab->precision++;
		tab->width++;
	}
    if (tab->precision > tab->len)
    {
		tab->width -= tab->precision;
		tab->precision -= tab->len;
	}
    else
	{
    	tab->width -= tab->len;
		tab->precision -= tab->len;
	}
    put_dif(box, tab);
    if (n || !tab->dot_prec)
        ft_putnbr(n);
    else
    	box->res--;
    if (tab->flag_min)
    {
        while (tab->width-- > 0)
			ft_putchar_count(box, ' ');
    }
}

void    output_p(t_box *box, t_tab *tab)
{
    unsigned long    p;
    unsigned long    p_copy;

    p = (unsigned long)va_arg(box->av, unsigned long);
    p_copy = p;
    tab->len += 3;
    while (p_copy /= 16)
        tab->len++;
    if (tab->width > tab->len)
        tab->dif = tab->width - tab->len;
    box->res += tab->len + tab->dif;
    if (tab->flag_min)
    {
        write(1, "0x", 2);
        print_hex(p);
        while (tab->dif--)
            ft_putchar(' ');
    }
    else
    {
        while (tab->dif--)
            ft_putchar(' ');
        write(1, "0x", 2);
        print_hex(p);
    }
}

void    output_persent(t_box *box, t_tab *tab)
{
    tab->len = 1;
    if (tab->width > 1)
        tab->dif = tab->width - 1;
    box->res += 1 + tab->dif;
    if (tab->flag_min)
    {
        ft_putchar('%');
        while (tab->dif--)
            ft_putchar(' ');
    }
    else
    {
        while (tab->dif--)
        {
            if (tab->flag_null)
                ft_putchar('0');
            else
                ft_putchar(' ');
        }
        ft_putchar('%');
    }
}

int     ft_printf(const char *format, ...)
{
    t_box   box;
    t_tab   tab;

    ft_bzero(&box, sizeof(t_box));
    box.format = format;
    va_start(box.av, format);
    parser(&box, &tab);
    va_end(box.av);
    return (box.res);
}