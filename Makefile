#                                     #
#            _       _ _____ _______  #
#           (_)     (_)  __ \__   __| #
#  _ __ ___  _ _ __  _| |__) | | |    #
# | '_ ` _ \| | '_ \| |  _  /  | |    #
# | | | | | | | | | | | | \ \  | |    #
# |_| |_| |_|_|_| |_|_|_|  \_\ |_|    #
#                                     #

# Compiler to be used
CC				:= cc

# Compiler flags
CFLAGS			+= -Wall -Wextra -Werror
CFLAGS			+= -pedantic -Wunreachable-code
CFLAGS			+= -Wshadow

ifeq ($(DEBUG), 1)
	CFLAGS		+= -gdwarf-2 -ggdb3
endif

# Libraries to be linked
LIBS			+= -L$(LFT_DIR) -lft
LIBS			+= -L$(MLX_BUILD_DIR) -lmlx42
LIBS			+= -ldl -lglfw -pthread -lm

MLX_DIR			:= lib/MLX42
MLX_BUILD_DIR	:= $(MLX_DIR)/build
MLX_A			:= $(MLX_BUILD_DIR)/libmlx42.a
MLX_LIB_LINK	:= https://github.com/codam-coding-college/MLX42/archive/refs/tags/v2.3.4.tar.gz

LFT_DIR			:= lib/libft
LFT_A			:= $(LFT_DIR)/libft.a

# Include directories
INCLUDES		:= -Iinc -I$(MLX_DIR)/include

# Target executable
NAME			:= minirt

# Source files directory
SRC_DIR			:= src

# MAIN
#SRC_FILES		+= tempmain.c

# INPUT Sources
SRC_FILES		+= input/flags/check_value_format.c
SRC_FILES		+= input/flags/create_flag_nodes.c
SRC_FILES		+= input/flags/flag_formatting.c
SRC_FILES		+= input/flags/flag_utils.c
SRC_FILES		+= input/flags/handle_values.c

SRC_FILES		+= input/scene_file/append.c
SRC_FILES		+= input/scene_file/check_data.c
SRC_FILES		+= input/scene_file/create_mand.c
SRC_FILES		+= input/scene_file/create_obj.c
SRC_FILES		+= input/scene_file/file_data.c
SRC_FILES		+= input/scene_file/file_utils.c
SRC_FILES		+= input/scene_file/ruleset.c
SRC_FILES		+= input/scene_file/to_object.c

SRC_FILES		+= input/input.c
SRC_FILES		+= input/find_scene_file.c
SRC_FILES		+= input/tests.c #remove

SRC_FILES		+= RTC/main.c

#MATRIX
SRC_FILES		+= RTC/operations/matrix/matrix_ops_1.c
SRC_FILES		+= RTC/operations/matrix/matrix_ops_2.c
SRC_FILES		+= RTC/operations/matrix/matrix_ops_3.c
SRC_FILES		+= RTC/operations/matrix/matrix_transform_1.c
SRC_FILES		+= RTC/operations/matrix/matrix_transform_2.c

#OBJECTS
SRC_FILES		+= RTC/operations/objects/object_struct.c
SRC_FILES		+= RTC/operations/objects/shapes.c
SRC_FILES		+= RTC/operations/objects/objects.c
SRC_FILES		+= RTC/operations/objects/triangle.c

#PATTERNS
SRC_FILES		+= RTC/operations/patterns/patterns.c
SRC_FILES		+= RTC/operations/patterns/pattern_types.c

#RAY
SRC_FILES		+= RTC/operations/rays/ray_normal.c
SRC_FILES		+= RTC/operations/rays/ray_reflect.c
SRC_FILES		+= RTC/operations/rays/ray.c

#REFLECTIONS
SRC_FILES		+= RTC/operations/reflections/reflection.c

#TUPLES
SRC_FILES		+= RTC/operations/tuples/tuples_init.c
SRC_FILES		+= RTC/operations/tuples/tuples_ops_1.c
SRC_FILES		+= RTC/operations/tuples/tuples_ops_2.c
SRC_FILES		+= RTC/operations/tuples/tuples_ops_3.c

#UTILS
SRC_FILES		+= RTC/default.c
SRC_FILES		+= RTC/operations/utils/utils_1.c

#WORLD
SRC_FILES		+= RTC/operations/world/comps.c
SRC_FILES		+= RTC/operations/world/intersect.c
SRC_FILES		+= RTC/operations/world/transparency.c
SRC_FILES		+= RTC/operations/world/view.c
SRC_FILES		+= RTC/operations/world/camera.c

SRC_FILES		+= RTC/operations/intersection/intersection.c
SRC_FILES		+= RTC/operations/intersection/obj_inter.c
SRC_FILES		+= RTC/operations/intersection/inter_helper.c

#TEXTURES
SRC_FILES		+= RTC/operations/textures/align_check.c
SRC_FILES		+= RTC/operations/textures/cube_uv_dir.c
SRC_FILES		+= RTC/operations/textures/cube_uv.c
SRC_FILES		+= RTC/operations/textures/uv.c
SRC_FILES		+= RTC/operations/textures/map.c

#IMAGE
SRC_FILES		+= RTC/operations/image/bump_map.c
SRC_FILES		+= RTC/operations/image/write_ppm.c
SRC_FILES		+= RTC/operations/image/read_ppm.c

SRC_FILES		+= RTC/operations/group/inherit.c
SRC_FILES		+= RTC/operations/group/group.c
SRC_FILES		+= RTC/operations/group/group_objs.c
SRC_FILES		+= RTC/operations/group/bounds.c

SRC_FILES		+= RTC/operations/wavefront_obj/parser.c

SRC_FILES		+= RTC/test.c


# Object files directory
OBJ_DIR			:= .obj

# Object files
OBJ_FILES		:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Dependency files directory
DEP_DIR			:= .dep

# Dependency files
DEPENDS			:= $(patsubst %.o, $(DEP_DIR)/%.d, $(OBJ_FILES))
-include $(DEPENDS)

RM				:= /bin/rm -f
MKDIR			:= /bin/mkdir -p
TOUCH			:= /bin/touch
WGET			:= /bin/wget
TAR				:= /bin/tar
MV				:= /bin/mv

.DEFAULT_GOAL	:= all

all: ## Build this project
	@$(MAKE) mlx
	@$(MAKE) libft
	@$(MAKE) -j $(NAME)

libft: ## Build libft
	$(MAKE) -C $(LFT_DIR)

mlx: ## Build MLX42
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Oops! No MLX here, gonna install one, hope you'r Ok with that :)"; \
		$(RM) lib/$(notdir $(MLX_LIB_LINK))*; \
		$(WGET) $(MLX_LIB_LINK) -P lib; \
		echo $(notdir $(MLX_LIB_LINK)); \
		$(TAR) -zxf lib/$(notdir $(MLX_LIB_LINK)) -C lib; \
		$(MV) lib/MLX42-* $(MLX_DIR); \
		echo "Ready!"; \
	else \
		echo "Oh, you already have MLX42, nice!"; \
	fi
	cmake $(MLX_DIR) -B $(MLX_DIR)/build
	cmake --build $(MLX_DIR)/build -j4

WIDTH		?= 720
# Compilation rule for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o, %.d, $@) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@$(MKDIR) $@

# Rule for linking the target executable
$(NAME): $(OBJ_FILES) $(LFT_A) $(MLX_A)
	$(CC) $(CFLAGS) -pg -o $(NAME) $(OBJ_FILES) $(INCLUDES) $(LIBS)
	-@echo -n "🚀 $(MAGENTA)" && ls -lah $(NAME) && echo -n "$(RESET)"

c clean: ## Clean objects and dependencies
	$(RM) $(OBJ_FILES)
	$(RM) -r $(OBJ_DIR)
	$(RM) $(DEPENDS)
	$(RM) -r $(DEP_DIR)

fc fclean: clean ## Restore project to initial state
	$(RM) $(NAME)

re: fclean all ## Rebuild project

h help: ## Show help info
	@grep -E '^[a-zA-Z_-_\ ]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "$(BOLD)$(GREEN)/%-12s--$(RESET) %s\n", $$1, $$2}'

.PHONY: all re c clean fc fclean h help

# Delete failed targets
.DELETE_ON_ERROR:

###### COLORS ######
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
