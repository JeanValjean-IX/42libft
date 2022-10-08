NAME =  libft.a

SRCS  = ft_memset.c		/
		ft_isdigit.c

INCLUDE = include

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@(gcc $(FLAGS) -c $(SRCS) -I $(INCLUDE))
	@(ar rc $(NAME) $(OBJS))
	@(ranlib $(NAME))

clean:
	@(rm -f $(OBJS))

fclean: clean
	@(rm -f $(NAME))

re: fclean all
