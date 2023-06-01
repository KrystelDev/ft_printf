/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:29:40 by kryrodri          #+#    #+#             */
/*   Updated: 2023/06/01 16:29:39 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h> // printf
# include <stdlib.h> // malloc y free
# include <unistd.h> // write
# include <stdarg.h> // va_list, va_start...

int	ft_printf(char const *, ...);
size_t	ft_strlen(const char *s);

#endif