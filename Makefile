# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvoltair <mvoltair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 12:01:51 by mvoltair          #+#    #+#              #
#    Updated: 2022/09/11 12:48:32 by mvoltair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
CC			=	gcc
CFLAGS		=	-g3 -Wall -Wextra
CLIBS		=	-Llibs -lftprintf -lmlx_Linux -lmlx -lX11 -lXext -lm
RM			=	rm -fr
ECHO		=	$(shell echo)

SRCS		=	main.c fdf.c fdf_utils.c mapcheck.c mapcheck_2.c free.c\
				project.c wu.c mapclean.c gooey.c colors.c artistry.c linedrawing.c
				
OBJ_S		=	$(SRCS:.c=.o)

LIBS		=	libftprintf.a libmlx.a libmlx_Linux.a
LIB_DIR		=	./libs/
SRC_LIBS	=	$(addprefix $(LIB_DIR), $(LIBS))

UTILS_SRCS	=	get_next_line.c get_next_line_utils.c
UTILS_DIR	=	get_next_line/
UTILS		=	$(addprefix $(UTILS_DIR), $(UTILS_SRCS))
OBJ_U		=	$(UTILS:.c=.o)

HEADER_SRCS	=	fdf.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

%.o: %.c		$(HEADER) Makefile
				${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_U) $(OBJ_S)
				#$(MAKE) bonus -C ./libft
				$(MAKE) bonus -C ./ft_printf
				$(MAKE) -C ./minilibx-linux
				#cp ./libft/libft.a $(LIB_DIR)
				cp ./ft_printf/libftprintf.a $(LIB_DIR)
				cp ./minilibx-linux/libmlx.a $(LIB_DIR)
				cp ./minilibx-linux/libmlx_Linux.a $(LIB_DIR)
				$(CC) $(OBJ_U) $(OBJ_S) $(CLIBS) -o $(NAME)
				@echo "$(NAME) executable created!\n"

all:			$(NAME)

clean:
				#$(MAKE) clean -C ./libft
				$(MAKE) clean -C ./ft_printf
				$(RM) $(OBJ_S)
				$(RM) $(OBJ_U)
				@echo "object files deleted.\n"

fclean:			clean
				#$(MAKE) fclean -C ./libft
				$(MAKE) fclean -C ./ft_printf
				$(RM) $(NAME)
				$(RM) $(SRC_LIBS)
				@echo "all files deleted.\n"

gitm: fclean
	git add .
	git commit
	git push

TIME = `date +"%d/%m/%Y %Hh%M %Z"`

git: fclean
	@if [ -d "./.git" ]; then\
		git add .;\
		git commit -m "$(NAME) :$(TIME)";\
		git push;\
	else\
		echo "not a git repository.\n";\
	fi

re:				fclean all

.PHONY:		all clean fclean re
