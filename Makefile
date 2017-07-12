CC						= g++
CPPFLAGS			+= -W -Wall -Werror --std=c++14
CPPFLAGS			+= -I ./includes

# PROJECT

NAME					= cod_code_codec

SRC_DIR				= ./sources

SRC						=	$(SRC_DIR)/main.cpp				\
								$(SRC_DIR)/ACsvParser.cpp	\
								$(SRC_DIR)/Dialogue.cpp

OBJ						= $(SRC:.cpp=.o)

RM						= rm -f

# TEST

TEST_DIR			=	./tests

# TEST : DIAL

TEST_DIAL			= test_dialogue

TEST_DIAL_SRC	=	$(TEST_DIR)/test_dialogue.cpp \
								$(SRC_DIR)/ACsvParser.cpp			\
								$(SRC_DIR)/Dialogue.cpp

TEST_DIAL_OBJ	=	$(TEST_DIAL_SRC:.cpp=.o)

# RULES

all: 						$(NAME)

$(NAME):				$(OBJ)
								$(CC) $(OBJ) -o $(NAME)

test_dial:			$(TEST_DIAL)

$(TEST_DIAL):		$(TEST_DIAL_OBJ)
								$(CC) $(TEST_DIAL_OBJ) -o $(TEST_DIAL)

clean:
								$(RM) $(OBJ)
								$(RM) $(TEST_DIAL_OBJ)

fclean:					clean
								$(RM) $(NAME)
								$(RM) $(TEST_DIAL)

re:							fclean all

retest_dial:		fclean test_dial

.PHONY:					all $(NAME) clean fclean re test_dial retest_dial
