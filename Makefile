NAME	=	computor
SRCS	=  	main.c  src/poly_helpers.c src/poly_logic.c src/poly_parsing.c
OBJ_DIR	=	obj
OBJS	= 	$(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))
CFLAGS	=   -Wall -Wextra -Werror
CC 		=	clang  -g
RM		=	rm -rf
RMDIR	= 	rmdir

all : 	$(NAME)

$(NAME): $(OBJS)
	 	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)


$(OBJ_DIR)/main.o: main.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@$(RM) $(OBJS)
	@echo "clean , Done !"

fclean:
	@$(RM) $(OBJS) $(NAME)
	@$(RM) $(OBJ_DIR)
	@echo " Done !"
	

re: fclean all

.PHONY:	re fclean clean all
