/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:40:41 by kryrodri          #+#    #+#             */
/*   Updated: 2023/06/05 12:56:35 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    printf("\n");
    printf("Con la %%c:\n");
    printf("%i\n", ft_printf("ftprintf %c ", '0'));
    printf("%i\n", printf("Original %c ", '0'));
    printf("\n");
    
    printf("Con la %%s:\n");
    printf("%i\n", ft_printf("ftprintf %s ", "hola"));
    printf("%i\n", printf("Original %s ", (char *)NULL));
    printf("\n");

    char k = 'K';
    char *p = &k;
    printf("Con la %%p:\n");
    printf("%i\n", ft_printf("ftprintf %p ", p));
    printf("%i\n", printf("Original %p ", p));
    printf("\n");

    printf("Con la %%d:\n");
    printf("%i\n", ft_printf("ftprintf %d ", 5));
    printf("%i\n", printf("Original %d ", 5));
    printf("\n");

    printf("Con la %%i:\n");
    printf("%i\n", ft_printf("ftprintf %i ", -2));
    printf("%i\n", printf("Original %i ", -2));
    printf("\n");

    printf("Con la %%u:\n");
    printf("%i\n", ft_printf("ftprintf %u ", -1));
    printf("%i\n", printf("Original %u ", -1));
    printf("\n");

    printf("Con la %%x:\n");
    printf("%i\n", ft_printf("ftprintf %x .", 5698));
    printf("%i\n", printf("Original %x .", 5698));
    printf("\n");

    printf("Con la %%X:\n");
    printf("%i\n", ft_printf("ftprintf %X .", 5698));
    printf("%i\n", printf("Original %X .", 5698));
    printf("\n");

    printf("Con el %%%%:\n");
    printf("%i\n", ft_printf("ftprintf %%%% "));
    printf("%i\n", printf("Original %%%% "));
    
    return 0;
}
