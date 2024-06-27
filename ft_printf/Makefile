LIBFT		=	./libft/libft.a

NAME		=	libftprintf.a

SRCS_FILES 	=	ft_printf.c ft_conversion.c ft_process_width.c ft_utoa.c \
				ft_ulltoa_base.c ft_putchar.c ft_str_tolower.c ft_precisionprint.c \
				ft_process_string.c ft_process_char.c ft_process_pointer.c ft_process_int.c \
				ft_process_uint.c ft_process_percent.c ft_process_hex.c ft_process_flags.c

SRCS_DIR	=	./sources/

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

INCLUDES 	=	-I./includes

OBJS 		=	$(SRCS:.c=.o)

%.o			: 	%.c	$(HEADER) Makefile
				${CC} ${FLAGS} -c $< -o $@

$(NAME)		:	$(OBJS)
				$(MAKE) bonus -C ./libft
				cp libft/libft.a $(NAME)
				#$(CC) $(FLAGS) $(INCLUDES) $(OBJS)
				ar -rcs $(NAME) $(OBJS)

all			:	$(NAME)

bonus		:	all

clean		:	
				$(MAKE) clean -C ./libft
				#rm -rf $(SURPL_O) 
				rm -rf $(OBJS)
				
fclean 		:	clean
				$(MAKE) fclean -C ./libft
				rm -rf $(NAME)

re 			: fclean all

.PHONY		: bonus all clean fclean re
