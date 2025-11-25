# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dievarga <dievarga@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/05 12:31:55 by dievarga          #+#    #+#              #
#    Updated: 2025/11/25 10:58:28 by dievarga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags -i cflag would include some dir to be searched for headers
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I.

# Library name
NAME    = libftprintf.a

# Source and object files
SRCS	= ft_printf.c ft_decimals.c ft_chars.c ft_strings.c ft_hexu.c ft_hexl.c ft_pointers.c ft_unsigned.c

OBJ     = $(SRCS:%.c=%.o)
HEADER = ft_printf.h

# Default rule
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule to compile .c to .o
%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean objects + library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
