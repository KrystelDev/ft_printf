# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 11:09:46 by kryrodri          #+#    #+#              #
#    Updated: 2023/06/05 11:34:18 by kryrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

# Nombre del proyecto
NAME	= libftprintf.a

# Archivos que uso al compilar
FUNCTION	=  ft_printf.c ft_itoa.c ft_strlen.c ft_calloc.c ft_put.c
				

# Tenemos que transformar los .c en .o para poder compilar
OBJS	= $(FUNCTION:.c=.o)

# La libreria
HEADER	= ft_printf.h

# Se compila el archivo binario (ejecutable).
all: ${NAME}

# Se compila los objetos con las librerias y archivos.
# ${NAME}: ${OBJS} ${HEADER}
# 	@echo "ejecutando ${NAME}"
# 	$(CC) $(FLAGS) main.c ${OBJS} -o ${NAME}

# Si no tuvieramos main.c usariamos el ar rcs en su lugar.
${NAME}: ${OBJS} ${HEADER}
	@echo "Generando la libreria ${NAME}..."
	ar rcs $(NAME) ${OBJS}

# Mirar google TODO
%.o: %.c ${HEADER} Makefile 
	@echo "Compilando el objeto $@..."
	@$(CC) -c $(FLAGS) $< -o $@
#	gcc -c -Wall -Wextra -Werror ...
# $@  = (todos los .o)
# $< = (Todos los inputs, seria todos los .c y su header (.h))
# -c es para convertir los .c en .o (.o = objetos, listos para usar)

# -f es para decir que si no existen ignoralos (evitando avisos como de errores innecesarios.)
clean:
	@echo "Ejecutando clean..."
	@rm -f $(OBJS) 

fclean: clean
	@echo "Ejecutando fclean..."
	@rm -f $(NAME)

re: fclean all
	@echo "Ejecutando re..."

# Le dice al make que estos nombre no son archivos
.PHONY: re fclean clean all