# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 17:42:13 by fmesa-or          #+#    #+#              #
#    Updated: 2025/10/28 18:14:41 by fmesa-or         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#Name
NAME = megaphone

#Compile
CC = g++

#Flags
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

#Clean
CLEAN = rm -f

#Sources
SRC = megaphone.cpp

#Objects
OBJ = $(SRC:.cpp=.o)

#Colors
COLOR_INFO = \033[1;36m
COLOR_SUCCESS = \033[1;32m
COLOR_RESET = \033[0m
COLOR_PROGRESS = \033[1;35m
COLOR_HEADER = \033[1;35m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@printf "\r\033[K$(COLOR_SUCCESS)✅ $(NAME) is ready!$(COLOR_RESET)\n"

%.o: %.cpp
	@printf "$(COLOR_INFO)Building $(NAME)...$(COLOR_RESET)\n"
	@$(CC) $(CPPFLAGS) -c $< -o $@


clean:
	@printf "$(COLOR_INFO)Cleaning object files...$(COLOR_RESET)"
	@$(CLEAN) $(OBJ)
	@printf "\r$(COLOR_SUCCESS)✅ Object files cleaned successfully!$(COLOR_RESET)\n"

fclean: clean
	@printf "$(COLOR_INFO)Deleting $(NAME)...$(COLOR_RESET)"
	@$(CLEAN) $(NAME)
	@printf "\r$(COLOR_SUCCESS)✅ $(NAME) deleted successfully!$(COLOR_RESET)\n"

re: fclean $(NAME)

.PHONY: all clean fclean re