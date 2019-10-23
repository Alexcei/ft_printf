# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpole <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 12:11:32 by bpole             #+#    #+#              #
#    Updated: 2019/10/22 16:52:13 by bpole            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  parser.c \
	  output_c_s.c \
	  output_u.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/

HEAD = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(HEAD) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -rf $(NAME)

re: fclean all
