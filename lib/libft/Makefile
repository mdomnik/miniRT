#### MAIN SETTINGS ####

# Compiler to be used
CC				:= cc

# Compiler flags
CFLAGS			+= -Wall -Werror -Wextra -O3
CFLAGS			+= -pedantic

# Libraries to be linked (if any)
LIBS			:=

# Include directories
INCLUDES		:= -I./

HEADERS			:= libft.h

# Target executable
NAME			:= libft.a

# Source files directory
SRC_DIR			:= src/
# Object files directory
OBJ_DIR			:= .obj/
# Dependency files directory
DEP_DIR			:= .dep/

# Source files
SRC_FILES		+= memory/ft_memset.c
SRC_FILES		+= memory/ft_memcpy.c
SRC_FILES		+= memory/ft_memmove.c
SRC_FILES		+= memory/ft_memchr.c
SRC_FILES		+= memory/ft_memcmp.c
SRC_FILES		+= memory/ft_calloc.c
SRC_FILES		+= memory/ft_malloc.c

SRC_FILES		+= string/ft_strlen.c
SRC_FILES		+= string/ft_strlcpy.c
SRC_FILES		+= string/ft_strlcat.c
SRC_FILES		+= string/ft_strrchr.c
SRC_FILES		+= string/ft_strncmp.c
SRC_FILES		+= string/ft_strnstr.c
SRC_FILES		+= string/ft_strdup.c
SRC_FILES		+= string/ft_substr.c
SRC_FILES		+= string/ft_strjoin.c
SRC_FILES		+= string/ft_strtrim.c
SRC_FILES		+= string/ft_split.c
SRC_FILES		+= string/ft_strmapi.c
SRC_FILES		+= string/ft_striteri.c
SRC_FILES		+= string/ft_strchr.c
SRC_FILES		+= string/ft_strarray.c
SRC_FILES		+= string/ft_strarray_more.c

SRC_FILES		+= utils/ft_isalnum.c
SRC_FILES		+= utils/ft_isalpha.c
SRC_FILES		+= utils/ft_isascii.c
SRC_FILES		+= utils/ft_isdigit.c
SRC_FILES		+= utils/ft_isprint.c
SRC_FILES		+= utils/ft_bzero.c
SRC_FILES		+= utils/ft_toupper.c
SRC_FILES		+= utils/ft_tolower.c
SRC_FILES		+= utils/ft_atoi.c
SRC_FILES		+= utils/ft_itoa.c
SRC_FILES		+= utils/ft_abs.c
SRC_FILES		+= put/ft_putchar_fd.c
SRC_FILES		+= put/ft_putstr_fd.c
SRC_FILES		+= put/ft_putendl_fd.c
SRC_FILES		+= put/ft_putnbr_fd.c

SRC_FILES		+= list/ft_lstnew_bonus.c
SRC_FILES		+= list/ft_lstadd_front_bonus.c
SRC_FILES		+= list/ft_lstsize_bonus.c
SRC_FILES		+= list/ft_lstlast_bonus.c
SRC_FILES		+= list/ft_lstadd_back.c
SRC_FILES		+= list/ft_lstdelone_bonus.c
SRC_FILES		+= list/ft_lstclear_bonus.c
SRC_FILES		+= list/ft_lstiter_bonus.c
SRC_FILES		+= list/ft_lstmap_bonus.c

SRC_FILES		+= deque/deque_back.c
SRC_FILES		+= deque/deque_front.c
SRC_FILES		+= deque/deque_emplace_back.c
SRC_FILES		+= deque/deque_emplace_front.c
SRC_FILES		+= deque/deque_push_back.c
SRC_FILES		+= deque/deque_push_front.c
SRC_FILES		+= deque/deque_pop_back.c
SRC_FILES		+= deque/deque_pop_front.c

SRC_FILES		+= hash_table/hashtable.c
SRC_FILES		+= hash_table/ht_utils.c

SRC_FILES		+= gnl/get_next_line.c

SRC_FILES		+= ftprintf/formatter_c.c
SRC_FILES		+= ftprintf/formatter_di.c
SRC_FILES		+= ftprintf/formatter_ptr.c
SRC_FILES		+= ftprintf/formatter_s.c
SRC_FILES		+= ftprintf/formatter_u.c
SRC_FILES		+= ftprintf/formatter_xX.c
SRC_FILES		+= ftprintf/ft_printf.c
SRC_FILES		+= ftprintf/parser.c

# Object files
OBJ_FILES		:= $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES))

# Dependency files
DEPENDS			:= $(patsubst %.c, $(DEP_DIR)%.d, $(SRC_FILES))
-include $(DEPENDS)

#### SHELL COMMANDS ####

RM				:= /bin/rm -f
MKDIR			:= /bin/mkdir -p
TOUCH			:= /bin/touch

#### DEBUG SETTINGS ####

ifeq ($(DEBUG), 1)
	CFLAGS		+= -g3 -O0
endif

#### NAME COMPILATION ####

.DEFAULT_GOAL	:= all

a all: $(NAME) ## Build this project

# Compilation rule for object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for linking the target executable
$(NAME): $(OBJ_FILES)
	ar rcs $@ $^
	-@echo -n "$(MAGENTA)" && ls -lah $(NAME) && echo -n "$(RESET)"

#### LOCAL LIBS COMPILATION ####

#### ADDITIONAL RULES ####

c clean: ## Clean objects and dependencies
	$(RM) $(OBJ_FILES)
	$(RM) -r $(OBJ_DIR)
	$(RM) $(DEPENDS)
	$(RM) -r $(DEP_DIR)

fc fclean: clean ## Restore project to initial state
	$(RM) $(NAME)

r re: fclean all ## Rebuild project

h help: ## Show help info
	@grep -E '^[a-zA-Z_-_\ ]+:.*?## .*$$' Makefile | sort | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "$(BOLD)$(GREEN)%-12s--$(RESET) %s\n", $$1, $$2}'

.PHONY: a all r re c clean fc fclean h help

#### COLORS ####
# Color codes
RESET		:= \033[0m
BOLD		:= \033[1m
UNDERLINE	:= \033[4m

# Regular colors
BLACK		:= \033[30m
RED			:= \033[31m
GREEN		:= \033[32m
YELLOW		:= \033[33m
BLUE		:= \033[34m
MAGENTA		:= \033[35m
CYAN		:= \033[36m
WHITE		:= \033[37m

# Background colors
BG_BLACK	:= \033[40m
BG_RED		:= \033[41m
BG_GREEN	:= \033[42m
BG_YELLOW	:= \033[43m
BG_BLUE		:= \033[44m
BG_MAGENTA	:= \033[45m
BG_CYAN		:= \033[46m
BG_WHITE	:= \033[47m
