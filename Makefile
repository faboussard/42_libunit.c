# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 13:08:13 by dguillon          #+#    #+#              #
#    Updated: 2024/01/27 09:57:19 by dguillon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SERVER

NAME:=serveur
#NAMEBONUS:=Serveur

SRCDIR:= serveur_dir/sources
OBJDIR:= serveur_dir/obj
#OBJDIRBONUS:= serveur_dir/objbonus
SRC:=\

#SRCBONUS:=\

SERVINCLUDE:= -I header\
-I libft
SRC:=$(SRC:%=$(SRCDIR)/%)
OBJ:=$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
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

$(NAME): $(VOBJ)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@printf "\n$(CYAN)==================|$(END)"
	@printf "\n$(GREEN)$(NAME) is finish\n$(END)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
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
	@rm -rf $(OBJ)
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