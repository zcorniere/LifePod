##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile 3.3
##

SRC	=	$(wildcard $(addprefix source/, *).c)
NOM	=	$(basename $(notdir $(SRC)))
OBJ	=	$(addprefix object/, $(addsuffix .o, $(NOM)))

LNAME	=	libmy.a
LIB		=	my
LIB-PATH	=	./lib/my
SRC-LIB	=	$(wildcard $(addprefix $(LIB-PATH)/, *).c)
NOM-LIB	=	$(basename $(notdir $(SRC-LIB)))
OBJ-LIB	=	$(addprefix object/, $(addsuffix .o, $(NOM-LIB)))
LFLAGS	=	-L $(LIB-PATH) -l$(LIB)

CNAME   =   libmycurs.a
CURS    =   mycurs
CURS-PATH   =   ./lib/mycurs
SRC-CURS    =   $(wildcard $(addprefix $(CURS-PATH)/, *).c)
NOM-CURS    =   $(basename $(notdir $(SRC-CURS)))
OBJ-CURS    =   $(addprefix object/, $(addsuffix .o, $(NOM-CURS)))
CFLAGS  =   -L $(CURS-PATH) -l$(CURS) -lncurses

HEADP	=	./include/
NAME	=	LifePod

END     =	\033[0m
BOLD	=	\033[1m
RED	=	\033[31m
GREEN	=	\033[32m
BLUE	=	\033[34m
CYAN	=	\033[36m
WHITE	=	\033[37m

CC	=	gcc

.PHONY: re clean lib curs my

all: lib $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS) $(CFLAGS)
	@echo -e "$(GREEN)* * * * * BINARY $(WHITE)$(BOLD)$(NAME)$(END)$(GREEN) COMPLETED * * * * *$(END)"

clear:
	@echo -e "$(BOLD)Deleting junks files$(END)"
	@rm -fv lib/my/*~
	@rm -fv source/*~
	@rm -fv *~
	@rm -fv include/*~
	@rm -fv vgcore.*
	@echo -e "$(CYAN)* * * * * CLEANED * * * * *$(END)"

clean:
	@echo -e "$(BOLD)Deleting OBJ.o files"
	@rm -f $(OBJ)
	@echo -e "$(END)$(CYAN)* * * * * DONE * * * * *$(END)"

lib: my curs

my: $(OBJ-LIB)
	@ar rc $(addprefix $(LIB-PATH)/, $(LNAME)) $(OBJ-LIB)
	@echo -e "$(GREEN)* * * * * LIBRARY $(WHITE)$(BOLD)$(LIB)$(END)$(GREEN) COMPLETED * * * * *$(END)"

curs: $(OBJ-CURS)
	@ar rc $(addprefix $(CURS-PATH)/, $(CNAME)) $(OBJ-CURS)
	@echo -e "$(GREEN)* * * * * LIBRARY $(WHITE)$(BOLD)$(CURS)$(END)$(GREEN) COMPLETED * * * * *$(END)"

lclean:
	@echo -e "$(BOLD)Deleting $(LNAME)$(END)"
	@rm -f $(OBJ-LIB) $(OBJ-CURS) $(LNAME) $(CNAME)
	@echo -e "$(CYAN)* * * * * LIBRARIES REMOVED * * * * *$(END)"

fclean: clean
	@echo -e "$(BOLD)Deleting $(NAME)$(END)"
	@rm -f $(NAME)
	@echo -e "$(CYAN)* * * * * CLEANED * * * * *$(END)"

re:	clear fclean lclean lib all

object/%.o: source/%.c
	@$(CC) -g3 -I $(HEADP) -Wall -Wextra -fPIC -fno-builtin -c -o $@ $<	\
	&& echo -e "[ $(GREEN)OK$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"      \
    || echo -e "[ $(RED)KO$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"


object/%.o: $(LIB-PATH)/%.c
	@$(CC) -I $(HEADP) -Wall -Wextra -fPIC -fno-builtin -c -o $@ $<	\
	&& echo -e "[ $(GREEN)OK$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"      \
    || echo -e "[ $(RED)KO$(END) ] Generate $(BOLD)$(WHITE)" $< "$(END)"


object/%.o: $(CURS-PATH)/%.c
	@$(CC) -I $(HEADP) -Wall -Wextra -fPIC -fno-builtin -c -o $@ $<	\
	&& echo -e "[ $(GREEN)OK$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"      \
	|| echo -e "[ $(RED)KO$(END) ] Generate$(BOLD)$(WHITE)" $< "$(END)"