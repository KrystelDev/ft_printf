/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:32:15 by kryrodri          #+#    #+#             */
/*   Updated: 2023/06/02 20:51:44 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_printc(int c, size_t	j)
{
	write(1, &c, 1);
	j++;
	return (j);
}

static size_t	ft_prints(char *str, size_t	j)
{
	char *s;

	s = str;
	if (s == NULL)
	{
		s= "(null)";
	}
	
	while (*s)
	{
		j = ft_printc(*s++, j);
	}
	return (j);
}

static size_t	ft_printi(int n, size_t	j)
{
	char	*itoa;

	itoa = ft_itoa((long)n);
	if (!itoa)
		return (0);
	j = ft_prints(itoa, j);
	free(itoa);
	return (j);
}

static size_t	ft_printu(int n, size_t j)
{
	char	*itoa;
	unsigned int	nb;
	
	nb = n;
	if (n < 0)
	{
		nb = (n + 1) + 4294967295;
	}
	itoa = ft_itoa((long) nb);
	if (!itoa)
		return (0);
	j = ft_prints(itoa, j);
	free(itoa);
	return (j);
}
// static size_t ft_printhex(unsigned long n, size_t j)
// {
//     const char *hex_digits = "0123456789abcdef";

//     if (n >= 16)
//         j = ft_printhex(n / 16, j); // Llamada recursiva para imprimir dígitos más significativos primero
//     j = ft_printc(hex_digits[n % 16], j); // Imprimir dígito hexadecimal
//     return j;
// }
static size_t ft_printhex(unsigned long n, size_t j)
{
    const char *hex_digits = "0123456789abcdef";

    if (n > 0)
    {
        if (n >= 16)
            j = ft_printhex(n / 16, j);
        j = ft_printc(hex_digits[n % 16], j);
    }
    else
    {
        j = ft_printc('0', j);
    }

    return j;
}
static size_t ft_printp(void *str, size_t j)
{
	unsigned long ptr;
	
	ptr = (unsigned long)str;
	j = ft_prints("0x", j);
	j = ft_printhex(ptr, j);

	return (j);
}

int	ft_printf(char const *format, ...)
{
	va_list argv;
	va_start(argv, format);
	size_t	i;
	size_t	j;

	char	mirar;
	char	mirar1;

	i = 0;
	j = 0;
	while (i < ft_strlen(format))
	{
		mirar = format[i];
		mirar1 = format[i + 1];
		if(format[i]=='%')
		{
			if(format[i+1]=='c')
				j = ft_printc(va_arg(argv, int), j);
			else if(format[i+1]=='s')
				j = ft_prints(va_arg(argv, char *), j);
			else if(format[i+1]=='p')
				ft_printp(va_arg(argv,void *), j);
			if(format[i+1]=='i' || format[i+1]=='d')
				j = ft_printi(va_arg(argv, int), j);
			if(format[i+1]=='u')
			{
				j = ft_printu(va_arg(argv, unsigned long), j);
			}
			// if(format[i+1]=='x')
			// {
			// 	ft_printx(va_arg(argv, char *), j);
			// }
			// if(format[i+1]=='X')
			// {
			// 	ft_printX(va_arg(argv, char *), j);
			// }
			else if(format[i+1]=='%')
				j = ft_printc(format[i+1], j);
			i += 2;
		}
		else
		{
			j = ft_printc(format[i], j);
			i++;
		}
	}
	
	va_end(argv);
	return (j);
}
