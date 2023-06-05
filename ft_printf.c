/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:32:15 by kryrodri          #+#    #+#             */
/*   Updated: 2023/06/05 12:41:02 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printx(unsigned long n, int j, char *hex_digits)
{
	if (j != -1 && n > 0)
	{
		if (n >= 16)
			j = ft_printx(n / 16, j, hex_digits);
		if (j != -1)
			j = ft_printc(hex_digits[n % 16], j);
	}
	else if (j != -1)
		j = ft_printc('0', j);
	return (j);
}

static int	ft_printp(void *str, int j)
{
	unsigned long	ptr;

	ptr = (unsigned long)str;
	j = ft_prints("0x", j);
	j = ft_printx(ptr, j, "0123456789abcdef");
	return (j);
}

static int	ft_next_format(const char *format, va_list argv, int j)
{
	format++;
	if (*format == 'c')
		j = ft_printc((char)va_arg(argv, int), j);
	else if (*format == 's')
		j = ft_prints(va_arg(argv, char *), j);
	else if (*format == 'p')
		j = ft_printp(va_arg(argv, void *), j);
	else if (*format == 'i' || *format == 'd')
		j = ft_printi(va_arg(argv, int), j);
	else if (*format == 'u')
		j = ft_printu(va_arg(argv, unsigned long), j);
	else if (*format == 'x')
		j = ft_printx(va_arg(argv, unsigned int), j, "0123456789abcdef");
	else if (*format == 'X')
		j = ft_printx(va_arg(argv, unsigned int), j, "0123456789ABCDEF");
	else if (*format == '%')
		j = ft_printc(*format, j);
	return (j);
}

int	ft_printf(char const *format, ...)
{
	int			j;
	va_list		argv;

	va_start (argv, format);
	j = 0;
	while ((j != -1) && *format != '\0')
	{
		if (*format == '%')
		{
			j = ft_next_format(format, argv, j);
			format += 2;
		}
		else
		{
			j = ft_printc(*format, j);
			format++;
		}
	}
	va_end(argv);
	return (j);
}
