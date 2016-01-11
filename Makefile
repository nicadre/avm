#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 14:26:45 by llapillo          #+#    #+#              #
#    Updated: 2016/01/11 14:27:05 by llapillo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	avm

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++1z

DSRC	=	./sources/

DOBJ	=	./objects/

DINC	=	./includes/

SRC		=	AOperand.template.cpp					\
			main.cpp

OBJ		=	$(patsubst %.cpp, $(DOBJ)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n\033[0;32m$(NAME) compiled:\t\033[0;m\c"
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(DOBJ)%.o: $(DSRC)%.cpp
	@mkdir -p $(DOBJ)
	@echo "\033[32m$< compiled:\t\033[0;m\c"
	$(CC) $(FLAGS) -o $@ -c $< -I$(DINC)

clean:
	rm -f $(OBJ)
	@rm -rf $(DOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
