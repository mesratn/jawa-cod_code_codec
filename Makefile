CC						= g++
CPPFLAGS			+= -W -Wall -Wextra -Werror --std=c++14
CPPFLAGS			+= -I ./includes -I ./mysf/includes

# PROJECT

NAME					= cod_code_codec

LIBSFML				= -L /usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
LIBMYSF				= -L ./mysf -lmysf

LIB						= $(LIBSFML) $(LIBMYSF)

SRC_DIR				= ./sources

SRC						=	$(SRC_DIR)/main.cpp					\
								$(SRC_DIR)/ACsvParser.cpp		\
								$(SRC_DIR)/Dialogue.cpp			\
								$(SRC_DIR)/CodCodeCodec.cpp	\
								$(SRC_DIR)/CodecRender.cpp	\
								$(SRC_DIR)/SpriteNode.cpp

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

all: 						libmysf $(NAME)
								cp mysf/libmysf.a mysf/libmysf.so .

libmysf:
								make -C mysf/

$(NAME):				$(OBJ)
								$(CC) $(CPPFLAGS) $(LIB) $(OBJ) -o $(NAME)

test_dial:			$(TEST_DIAL)

$(TEST_DIAL):		$(TEST_DIAL_OBJ)
								$(CC) $(TEST_DIAL_OBJ) -o $(TEST_DIAL)

clean:
								$(RM) $(OBJ)
								$(RM) $(TEST_DIAL_OBJ)
								make clean -C mysf/

fclean:					clean
								$(RM) $(NAME)
								$(RM) $(TEST_DIAL)
								make fclean -C mysf/

re:							fclean all
								make re -C mysf/

retest_dial:		fclean test_dial

.PHONY:					all libmysf $(NAME) test_dial $(TEST_DIAL) clean fclean re retest_dial
