NAME	= libftprintf
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
ARFLAGS	= -rcs
INC		= ft_printf.h
RM		= rm -rf

SRCS	= ft_printf_flags.c ft_printf.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME).a

$(NAME).a: $(OBJS)
	ar $(ARFLAGS) $(NAME).a $(OBJS)

%.o: %.c $(INC)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME).a
re: fclean all

.PHONY: all clean fclean re