CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar -rc
RM := rm -f

NAME_S := server
NAME_C := client  

BONUS_S := server_bonus
BONUS_C := client_bonus

SRC_S := server.c handle_char.c handle_int.c  handle_str.c handle_hexa.c handle_ptr.c  hundle_unsg.c ft_printf.c 
SRC_C := client.c handle_char.c handle_int.c  handle_str.c handle_hexa.c handle_ptr.c  hundle_unsg.c ft_printf.c 

SRCB_S := server_bonus.c handle_char.c handle_int.c  handle_str.c handle_hexa.c handle_ptr.c  hundle_unsg.c ft_printf.c 
SRCB_C := client_bonus.c handle_char.c handle_int.c  handle_str.c handle_hexa.c handle_ptr.c  hundle_unsg.c ft_printf.c 

OBJ_S := $(SRC_S:%.c=%.o)
OBJ_C := $(SRC_C:%.c=%.o)

OBJB_S := $(SRCB_S:%.c=%.o)
OBJB_C := $(SRCB_C:%.c=%.o)

.PHONY : all clean fclean re bonus

all : $(NAME_S) $(NAME_C)
bonus : $(BONUS_S) $(BONUS_C)

$(NAME_S) : $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_S) 
$(NAME_C) : $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)


$(BONUS_S) :  $(OBJB_S)
	$(CC) $(CFLAGS) $(OBJB_S) -o $(BONUS_S)
$(BONUS_C) :  $(OBJB_C)
	$(CC) $(CFLAGS) $(OBJB_C) -o $(BONUS_C)

clean : 
	$(RM) $(OBJ_S) $(OBJ_C) $(OBJB_S) $(OBJB_C)

fclean : clean
	$(RM) $(NAME_S) $(NAME_C) $(BONUS_S) $(BONUS_C)

re : fclean all bonus
.SECONDARY : $(OBJ_S) $(OBJ_C) $(OBJB_S) $(OBJB_C)