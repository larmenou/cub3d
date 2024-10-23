# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 13:52:28 by bahommer          #+#    #+#              #
#    Updated: 2023/11/24 11:50:38 by bahommer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = srcs/
O = obj/
I = include/
D = dep/
LIB_DIR	= ./minilibx
LFT_DIR = ./libft/

SRC		= 	$Smain.c \
		 	$Ssrcs_mlx/mlx.c \
			$Ssrcs_mlx/texture.c \
			$Ssrcs_mlx/draw.c \
		 	$Ssrcs_mlx/events.c \
		  	$Ssrcs_mlx/free_mlx.c \
			$Sraycast/raycasting.c \
			$Sraycast/move.c \
			$Sraycast/rota.c \
			$Sraycast/player.c \
		 	$Sparsing/free.c \
		 	$Sparsing/is_spaces.c \
			$Sparsing/read_file.c \
			$Sparsing/set_map.c \
			$Sparsing/format_map.c \
			$Sparsing/set_nsew_in_data.c \
			$Sparsing/set_noso.c \
			$Sparsing/set_start_position.c \
			$Sparsing/check_legit_map.c \
			$Sparsing/check_map_elements.c \
			$Sparsing/error.c \
			$Sparsing/main_parsing.c \
			$Sparsing/rgb_to_hexa.c \
			$Sparsing/set_texture.c \
			$Sparsing/display_data_map.c

SRC_BONUS	= 	$Smain.c \
		 	$Ssrcs_mlx/mlx.c \
			$Ssrcs_mlx/texture.c \
			$Ssrcs_mlx/draw.c \
		 	$Ssrcs_mlx/events.c \
		  	$Ssrcs_mlx/free_mlx.c \
			$Sraycast/raycasting.c \
			$Sraycast/move_bonus.c \
			$Sraycast/rota.c \
			$Sraycast/player.c \
		 	$Sparsing/free.c \
		 	$Sparsing/is_spaces.c \
			$Sparsing/read_file.c \
			$Sparsing/set_map.c \
			$Sparsing/format_map.c \
			$Sparsing/set_nsew_in_data.c \
			$Sparsing/set_noso.c \
			$Sparsing/set_start_position.c \
			$Sparsing/check_legit_map.c \
			$Sparsing/check_map_elements.c \
			$Sparsing/error.c \
			$Sparsing/main_parsing.c \
			$Sparsing/rgb_to_hexa.c \
			$Sparsing/set_texture.c \
			$Sparsing/display_data_map.c

OBJ		= $(SRC:.c=.o)
DEP		= $(SRC:.c=.d)

OBJ_BONUS	= $(SRC_BONUS:.c=.o)
DEP_BONUS	= $(SRC_BONUS:.c=.d)

CC 		= cc

RM		= rm -f
RMDIR	= rmdir

CFLAGS	= -Wall -Wextra -Werror -g3 -I$(I) 
MLX		= -lmlx -lXext -lX11 -lm 
LFT		= -lft

NAME	= cub3D 

all:	$(NAME)

$(O):	
	@mkdir -p $@

$(OBJ):	| $(O)

$(OBJ_BONUS): | $(O)

$(O)%.o:	$(S)%
	    $(CC) $(CFLAGS) -c $< -o $@

$(D):	
	@mkdir -p $@

$(DEP):	| $(D)

$(DEP_BONUS):	| $(D)

$(D)%.d:	$(S)%
	    $(CC) $(CFLAGS) -MM -MF $@ -MT $(O)$*.o $<

$(NAME):	$(OBJ)
		make all -C ${LIB_DIR}
		make all -C ${LFT_DIR}
		${CC} $^ -L${LIB_DIR} -L${LFT_DIR} ${MLX} ${LFT} -o $@

clean:		
		$(RM) $(wildcard $(OBJ)) $(wildcard $(DEP)) $(wildcard $(DEP_BONUS)) $(wildcard $(OBJ_BONUS))
		-$(RMDIR) $(O) $(D)
		make clean -C ${LFT_DIR}
		make clean -C ${LIB_DIR}

fclean:	clean
		make fclean -C ${LFT_DIR}
		${RM} ${NAME}

re:		fclean all

bonus: $(OBJ_BONUS)
		make all -C ${LIB_DIR}
		make all -C ${LFT_DIR}
		${CC} $^ -L${LIB_DIR} -L${LFT_DIR} ${MLX} ${LFT} -o $(NAME)


-include $(DEP)

.PHONY:	clean fclean re norme all bonus
