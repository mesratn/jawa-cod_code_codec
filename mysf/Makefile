CC				= g++
CPPFLAGS	+= -Wall -Wextra -pedantic -Werror -o3 -std=c++14 -fPIC
CPPFLAGS	+= -I ./includes
# CPPFLAGS	+= -I /usr/local/include

LIBSFML		= -L /usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

SRC				= sources/Binding.cpp \
						sources/Engine.cpp \
						sources/Event.cpp \
						sources/GraphicLayer.cpp \
						sources/GraphicLayerSet.cpp \
						sources/GraphicRender.cpp \
						sources/Joysticks.cpp \
						sources/Key.cpp \
						sources/Mouse.cpp \
						sources/SceneNode.cpp \
						sources/SoundPlayer.cpp

OBJ				= $(SRC:.cpp=.o)

NAME			= mysf
NAME_STC	= lib$(NAME).a
NAME_DYN	= lib$(NAME).so

RM				= rm -f

all: $(NAME_STC) $(NAME_DYN)

$(NAME_STC): $(OBJ)
	ar rcs $(NAME_STC) $(OBJ)

$(NAME_DYN): $(OBJ)
	$(CC) -shared $(OBJ) $(CPPFLAGS) $(LIBSFML) -o $(NAME_DYN)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME_STC) $(NAME_DYN)

re: fclean all

.PHONY		= all $(NAME_STC) $(NAME_DYN) clean fclean re
