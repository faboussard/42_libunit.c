# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 17:00:34 by dguillon          #+#    #+#              #
#    Updated: 2024/01/22 12:55:36 by dguillon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
OTHERFLAGS = -I. -MMD -MP 
AR = ar
ARFLAGS = -r -c -s
NAME = libft.a

-include ../colors.mk

SRC = ft_atoi\
ft_bzero\
ft_calloc\
ft_isalnum\
ft_isalpha\
ft_isascii\
ft_isdigit\
ft_isprint\
ft_itoa\
ft_memchr\
ft_memcmp\
ft_memcpy\
ft_memmove\
ft_memset\
ft_putchar_fd\
ft_putendl_fd\
ft_putnbr_fd\
ft_putstr_fd\
ft_split\
ft_strchr\
ft_strdup\
ft_striteri\
ft_strjoin\
ft_strlcat\
ft_strlcpy\
ft_strlen\
ft_strmapi\
ft_strncmp\
ft_strnstr\
ft_strrchr\
ft_strtrim\
ft_substr\
ft_tolower\
ft_toupper\
ft_lstnew_bonus\
ft_lstadd_front_bonus\
ft_lstsize_bonus\
ft_lstlast_bonus\
ft_lstadd_back_bonus\
ft_lstdelone_bonus\
ft_lstclear_bonus\
ft_lstiter_bonus\
ft_lstmap_bonus\
ft_printf\
put_hexa\
str\
write_nbr\
get_next_line_bonus\
get_next_line_utils_bonus
OBJ = $(SRC:%=%.o)
DEPS = $(OBJ:.o=.d)

default: all

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^
	@printf "\n$(ERASE)$(CYAN)==================|$(END)"
	@printf "\n$(GREEN)$(NAME) is finish\n$(END)\n"

%.o: %.c libft.h Makefile
	@$(CC) $(CFLAGS) $(OTHERFLAGS) -c $<
	@printf "$(ERASE)$(YELLOW)files .o are ready$(END)"
	
clean:
	@rm -f $(OBJ) $(DEPS)
	@printf "$(ERASE)$(RED)files OBJ and DEPS of $(NAME) are deleted$(END)"

fclean: clean
	@rm -f $(NAME)
	@printf "\n$(CYAN)==================|$(END)"
	@printf "\n$(RED)$(NAME) is deleted$(END)\n"

re: fclean
	@$(MAKE) all

show:
	@echo "$(DEPS)"

.PHONY: all clean fclean re
.SILENT:
