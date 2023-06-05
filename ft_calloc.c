/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:50:10 by kryrodri          #+#    #+#             */
/*   Updated: 2023/06/05 12:41:05 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	char	*copia_cpy;
	size_t	i;

	copia_cpy = malloc(num_elements * element_size);
	if (!copia_cpy)
		return (NULL);
	i = 0;
	while (i < num_elements)
		(copia_cpy)[i++] = '\0';
	return (copia_cpy);
}
