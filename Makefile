CC				= g++
CPPFLAGS	+= -W -Wall -Werror --std=c++14
CPPFLAGS	+= -I ./includes

NAME			= cod_code_codec

SRC				= sources/main.cpp \
						sources/ACsvParser.cpp

OBJ				= $(SRC:.cpp=.o)

RM				= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
