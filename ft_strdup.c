/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:19:18 by kryrodri          #+#    #+#             */
/*   Updated: 2023/06/02 16:12:47 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "ft_strlen.c"
// #include <string.h>

char	*ft_strdup(char *s)
{
	char	*copia_cpy;
	size_t	i;

	i = -1;
	copia_cpy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (copia_cpy == NULL)
	{
		return (NULL);
	}
	while (s[++i])
		copia_cpy[i] = s[i];
	copia_cpy[i] = '\0';
	return (copia_cpy);
}

// int main()
// {
// 	char *original = "Hola, mundo!";
// 	char *copia;
// 	// Usando ft_strdup para duplicar la cadena original
// 	copia = ft_strdup(original);
// 	if (copia == NULL)
// 	{
// 		printf("Error: No se pudo asignar memoria.\n");
// 		return 1;
// 	}
// 	// Imprimir la cadena original y la copia
// 	printf("Cadena original: %s\n", original);
// 	printf("Copia: %s\n", copia);
// 	// Liberar la memoria asignada
// 	free(copia);
// 	return 0;
// }