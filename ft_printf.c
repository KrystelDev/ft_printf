/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:32:15 by kryrodri          #+#    #+#             */
/*   Updated: 2023/06/01 17:29:52 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_printc(int c )
{
	write(1,&c,1);
}
void ft_prints(char *str )
{
	while (*str)
	{
		ft_printc(*str++);
	}
}

int	ft_printf(char const *format, ...)
{
	va_list argv;
	va_start(argv, format);
	size_t	i;

	i = -1;
	while (++i < ft_strlen(format))
	{
		if(format[i]=='%')
		{
			if(format[i+1]=='c')
			{
				ft_printc(va_arg(argv, int));
				i += 2;
			}
			if(format[i+1]=='s')
			{
				ft_prints(va_arg(argv, char *));
				i += 2;
			}
			// if(format[i+1]=='p')
			// {
			// 	ft_printp(va_arg(argv, char *));
			// 	i += 2;
			// }
			// if(format[i+1]=='d')
			// {
			// 	ft_printd(va_arg(argv, char *));
			// 	i += 2;
			// }
			// if(format[i+1]=='i')
			// {
			// 	ft_printi(va_arg(argv, char *));
			// 	i += 2;
			// }
			// if(format[i+1]=='u')
			// {
			// 	ft_printu(va_arg(argv, char *));
			// 	i += 2;
			// }
			// if(format[i+1]=='x')
			// {
			// 	ft_printx(va_arg(argv, char *));
			// 	i += 2;
			// }
			// if(format[i+1]=='X')
			// {
			// 	ft_printX(va_arg(argv, char *));
			// 	i += 2;
			// }
			// if(format[i+1]=='%')
			// {
			// 	ft_prints(va_arg(argv, char *));
			// 	i += 2;
			// }
		}
		write(1, &format[i], sizeof(char));
	}
	
	va_end(argv);
	return (0);
}
