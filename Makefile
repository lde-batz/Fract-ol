# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 14:35:23 by lde-batz          #+#    #+#              #
#    Updated: 2019/02/12 16:39:18 by lde-batz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = 	main.c\
		main1/main1.c\
		main1/graph.c\
		main1/img.c\
		main1/fract_fct.c\
		main1/mandelbrot.c\
		main1/mandel_tricorn.c\
		main1/mandel_ship.c\
		main1/julia.c\
		main1/julia_tricorn.c\
		main1/julia_ship.c\
		main1/koch.c\
		main1/flocon.c\
		main1/segment.c\
		main1/segment_1st_half.c\
		main1/segment_2nd_half.c\
		main1/color_init.c\
		main1/color_init2.c\
		main1/color.c\
		main1/key.c\
		main1/move.c\
		main1/move_specific.c\
		main1/iteration.c\
		main1/head.c\
		main1/color_change.c\
		main1/color_change2.c\
		main1/mouse.c\
		main1/zoom.c\
		main1/go_julia.c\
		main1/scroll.c\
		main1/expose.c\
		main2/main2.c\
		main2/graph.c\
		main2/img.c\
		main2/fract_fct.c\
		main2/mandel.c\
		main2/mandel_tricorn.c\
		main2/mandel_ship.c\
		main2/julia.c\
		main2/julia_tricorn.c\
		main2/julia_ship.c\
		main2/koch.c\
		main2/flocon.c\
		main2/segment.c\
		main2/segment_1st_half.c\
		main2/segment_2nd_half.c\
		main2/color_init.c\
		main2/color_init2.c\
		main2/color.c\
		main2/key.c\
		main2/move.c\
		main2/move_specific.c\
		main2/iteration.c\
		main2/head.c\
		main2/color_change.c\
		main2/color_change2.c\
		main2/mouse.c\
		main2/zoom.c\
		main2/expose.c\

SRC_DIR = srcs/

OBJ_DIR = objects/

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC := $(addprefix $(SRC_DIR), $(SRC))

INC =	-I includes/fractol1.h -I includes/fractol2.h -I libft/srcs/libft.h

LIB = -L libft/ -lft -L /usr/local/lib/ -lmlx

GCC = gcc -Wall -Wextra -Werror -o -o1 -o2 -o3

MLX_FLAG = -framework OpenGL -framework AppKit

THREAD_FLAG = -lpthread

.SILENT:

all: lib $(NAME)

$(NAME): $(OBJ)
	$(GCC) -o $(NAME) $(SRC) $(LIB) $(MLX_FLAG) $(THREAD_FLAG)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Fractol"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/main1
	mkdir -p $(OBJ_DIR)/main2
	$(GCC) -c $< -o $@ $(INC)
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

lib:
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJ)
	rm -Rf $(OBJ_DIR)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Fractol"

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Fractol"

re: fclean all

.PHONY: all clean fclean re
