SRC			=	${OPERATION} ${PARS} \
				${SORT} ${CORE}

PARS		=	src/parser/ft_atoi.c src/parser/parser_utils.c \
				src/parser/parser.c

SORT		=	src/sort/sort.c src/sort/sort_utils.c src/sort/score.c \
				src/sort/quick_sort.c src/sort/push_rotate.c \
				src/sort/mini_sort.c src/sort/full_sort.c

OPERATION	=	src/operations/operations_A.c src/operations/operations_B.c \
				src/operations/operations_common.c src/operations/operations_AB.c

CORE		=	src/core/push_swap.c src/core/program_finish.c \
				src/core/rollback_context.c src/core/safe_malloc.c

OBJ			=	${SRC:.c=.o}

INCLUDES	=	includes/

NAME		=	push_swap

CFLAGS		=	-Wall -Werror -Wextra

%.o:			%.c Makefile $(INCLUDES)push_swap.h $(INCLUDES)operations.h \
								$(INCLUDES)parser.h $(INCLUDES)push_swap.h \
				 				$(INCLUDES)rollback_context.h $(INCLUDES)sort.h
				${CC} $(CFLAGS) -c $< -o  $@ -I ${INCLUDES}

all:			$(NAME)

$(NAME):		$(OBJ) $(INCLUDES)push_swap.h $(INCLUDES)operations.h \
								$(INCLUDES)parser.h $(INCLUDES)push_swap.h \
				 				$(INCLUDES)rollback_context.h $(INCLUDES)sort.h
				${CC} ${CFLAGS} ${OBJ} -o $(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
