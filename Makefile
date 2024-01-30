# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 13:08:13 by dguillon          #+#    #+#              #
#    Updated: 2024/01/28 16:27:39 by dguillon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SERVER

NAME:= libunit
#NAMEBONUS:=Serveur

#OBJDIRBONUS:= serveur_dir/objbonus
SRC:=\
    functions_to_test/wrong_ft_itoa.c\
    functions_to_test/wrong_ft_strlen.c\
    functions_to_test/wrong_is_alpha.c\
    functions_to_test/wrong_ft_lstsize.c\
    tests/atoi/00_launcher.c\
    tests/atoi/01_basic_test.c\
    tests/atoi/02_null_test.c\
    tests/atoi/03_int_MIN_test.c\
    tests/itoa/00_launcher.c\
    tests/itoa/01_basic_test.c\
    tests/itoa/02_null_test.c\
    tests/itoa/03_int_MIN_test.c\
    tests/lstsize/00_launcher.c\
    tests/lstsize/01_basic_test.c\
    tests/lstsize/02_null_test.c\
    tests/lstsize/03_other_test.c\
    tests/strlen/00_launcher.c\
    tests/strlen/01_basic_test.c\
    tests/strlen/02_null_test.c\
    tests/strlen/03_bigger_str_test.c\
    tests/is_alpha/00_launcher.c\
    tests/is_alpha/01_basic_test.c\
    tests/is_alpha/02_null_test.c\
    tests/is_alpha/03_other_test.c\
    main.c
#SRCBONUS:=\

SERVINCLUDE:= -I header\
-I libft
OBJ:=$(SRC:%.c=%.o)
DEPS:=$(OBJ:.o=.d)
#SRCBONUS:=$(SRCBONUS:%_bonus.c=$(SRCDIR)/%_bonus.c)
#OBJBONUS:=$(SRCBONUS:$(SRCDIR)/%_bonus.c=$(OBJDIRBONUS)/%_bonus.o)
#DEPSBONUS:=$(OBJBONUS:.o=.d)

#common
IFLAGS:= -MMD -MP
CC:= cc
CFLAGS := -Wall -Werror -Wextra
LIB:= libft/libft.a

-include colors.mk

#======================================================================================================|
#with no bonus

default: all

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJ)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@printf "\n$(CYAN)==================|$(END)"
	@printf "\n$(GREEN)$(NAME) is finish\n$(END)\n"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) $(IFLAGS) -c -o $@ $<
	@printf "$(ERASE)$(YELLOW)Files OBJ and DEPS of $(NAME) are ready$(END)"

#=========================================================================================================|
#with bonus

#bonus: $(EXECSERVBONUS) $(EXECCUSTOMERBONUS)

#$(LIB):
#	@$(MAKE) -C ./libft

#-include $(SERVDEPSBONUS)

#$(EXECSERVBONUS): $(LIB) $(SERVOBJBONUS)
#	@$(CC) $(CFLAGS) $(SERVOBJBONUS) $(LIB) -o $(EXECSERVBONUS)
#	@printf "\n$(CYAN)==================|$(END)"
#	@printf "\n$(GREEN)$(EXECSERVBONUS) is finish\n$(END)\n"

#$(OBJSERVDIRBONUS)/%.o: $(SRCSERVDIR)/%.c
#	@mkdir -p $(@D)
#	@$(CC) $(CFLAGS) $(SERVINCLUDE) $(IFLAGS) -c -o $@ $<
#	@printf "$(ERASE)$(YELLOW)Files OBJ and DEPS of $(EXECSERVBONUS) are ready$(END)"

#-include $(CUSTOMERDEPSBONUS)

#$(EXECCUSTOMERBONUS): $(LIB) $(CUSTOMEROBJBONUS)
#	@$(CC) $(CFLAGS) $(CUSTOMEROBJBONUS) $(LIB) -o $(EXECCUSTOMERBONUS)
#	@printf "\n$(CYAN)==================|$(END)"
#	@printf "\n$(GREEN)$(EXECCUSTOMERBONUS) is finish\n$(END)\n"

#$(OBJCUSTOMERDIRBONUS)/%.o: $(SRCCUSTOMERDIR)/%.c
#	@mkdir -p $(@D)
#	@$(CC) $(CFLAGS) $(CUSTOMERINCLUDE) $(IFLAGS) -c -o $@ $<
#	@printf "$(ERASE)$(YELLOW)Files OBJ and DEPS of $(EXECCUSTOMERBONUS) are ready$(END)"

#=====================================================================================================|
#clean and re

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ) $(DEPS)
	@printf "$(ERASE)$(RED)files OBJ and DEPS of  and $(NAME) are deleted$(END)\n"	
	@printf "$(CYAN)============================================|$(END)\n"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME) 
	@printf "\n$(CYAN)======================|$(END)"
	@printf "\n$(RED)$(NAME) are deleted$(END)\n"
	@printf "\n$(CYAN)============================================|$(END)\n\n"

re: fclean all

#====================================================================================================|
#clean and re bonus

#cleanb:
#	@$(MAKE) clean -C ./libft
#	@rm -rf $(OBJSERVDIRBONUS) $(OBJCUSTOMERDIRBONUS)
#	@printf "$(ERASE)$(RED)files OBJ and DEPS of $(EXECCUSTOMERBONUS) and $(EXECSERVBONUS) are deleted$(END)\n"	
#	@printf "$(CYAN)============================================|$(END)\n"

#fcleanb: cleanb
#	@$(MAKE) fclean -C ./libft
#	@rm -f $(EXECSERVBONUS) $(EXECCUSTOMERBONUS)
#	@printf "\n$(CYAN)=======================|$(END)"
#	@printf "\n$(RED)$(EXECCUSTOMERBONUS) and $(EXECSERVBONUS) are deleted$(END)\n"
#	@printf "\n$(CYAN)============================================|$(END)\n\n"

#reb: fcleanb bonus

.PHONY: all re clean fclean
.SILENT: