/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:29:40 by kryrodri          #+#    #+#             */
/*   Updated: 2023/06/02 15:57:03 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdio.h> // printf
# include <stdlib.h> // malloc y free
# include <unistd.h> // write
# include <stdarg.h> // va_list, va_start...
# include <limits.h>

int	ft_printf(char const *, ...);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t num_elements, size_t element_size);
char	*ft_strdup(char *s);
char	*ft_itoa(long n);

#endif