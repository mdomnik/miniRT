#                                     #
#            _       _ _____ _______  #
#           (_)     (_)  __ \__   __| #
#  _ __ ___  _ _ __  _| |__) | | |    #
# | '_ ` _ \| | '_ \| |  _  /  | |    #
# | | | | | | | | | | | | \ \  | |    #
# |_| |_| |_|_|_| |_|_|_|  \_\ |_|    #
#                                     #

# Compiler to be used
CC              := cc

# Compiler flags
CFLAGS          += -Wall -Wextra -Werror
CFLAGS          +=  -Wunreachable-code
CFLAGS          += -Wshadow

ifeq ($(DEBUG), 1)
    CFLAGS      += -ggdb3 -gdwarf-4
endif

# Libraries to be linked
LIBS            += -L$(LFT_DIR) -lft
LIBS            += -L$(MLX_BUILD_DIR) -lmlx_Linux
LIBS            += -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz

MLX_DIR         := lib/minilibx-linux
MLX_BUILD_DIR   := $(MLX_DIR)
MLX_A           := $(MLX_BUILD_DIR)/libmlx_Linux.a

LFT_DIR         := lib/libft
LFT_A           := $(LFT_DIR)/libft.a

# Include directories
INCLUDES        := -Iinc -I$(MLX_DIR)

# Target executable
NAME            := miniRT

# Source files directory
SRC_DIR         := src

# DEBUG
SRC_FILES	+=	debug/debug_methods.c
SRC_FILES	+= debug/close_and_free.c

# GROUPS
SRC_FILES	+=	groups/group_op.c
SRC_FILES	+=	groups/inherit.c
SRC_FILES	+=	groups/bound_op.c
SRC_FILES	+=	groups/bound_types.c

# INITIALIZE
SRC_FILES	+=	initialize/init_else.c
SRC_FILES	+=	initialize/init_complex_obj.c
SRC_FILES	+=	initialize/struct_op.c
SRC_FILES	+=	initialize/init_basic_obj.c

# INTERSECTION
SRC_FILES	+=	intersection/intersect_complex_obj.c
SRC_FILES	+=	intersection/intersect_op.c
SRC_FILES	+=	intersection/intersect_and_hit.c
SRC_FILES	+=	intersection/intersect_basic_obj.c
SRC_FILES	+=	intersection/intersect_cap_obj.c
SRC_FILES	+=	intersection/ico_utils.c
SRC_FILES	+=	intersection/intersect_complex_utils.c

# LIGHTING
SRC_FILES	+=	lighting/transparency.c
SRC_FILES	+=	lighting/find_normal.c
SRC_FILES	+=	lighting/light_and_reflect.c
SRC_FILES	+=	lighting/shadows_and_computations.c
SRC_FILES	+=	lighting/reflection_and_refraction.c
SRC_FILES	+=	lighting/ray_op.c
SRC_FILES	+=	lighting/ambient.c

# MATRIX
SRC_FILES	+=	matrix/matrix_inverse.c
SRC_FILES	+=	matrix/matrix_inverse2.c
SRC_FILES	+=	matrix/matrix_basic_op.c
SRC_FILES	+=	matrix/matrix_basic_transform.c
SRC_FILES	+=	matrix/matrix_shear_transform.c

# PARSE/MAT
SRC_FILES	+=	parse/mat/mat_format_op.c
SRC_FILES	+=	parse/mat/mat_format_op2.c
SRC_FILES	+=	parse/mat/mat_format.c
SRC_FILES	+=	parse/mat/mat_format_utils.c
SRC_FILES	+=	parse/mat/mat_texture.c
SRC_FILES	+=	parse/mat/set_texture.c
SRC_FILES	+=	parse/mat/mat_uv_set.c
SRC_FILES	+=	parse/mat/mat_skybox.c

# PARSE/OBJ
SRC_FILES	+=	parse/obj/obj_to_faces.c
SRC_FILES	+=	parse/obj/obj_to_faces_helper.c
SRC_FILES	+=	parse/obj/parse_obj.c

# PARSE/PPM
SRC_FILES	+=	parse/ppm/write_to_ppm.c
SRC_FILES	+=	parse/ppm/canvas_utils.c
SRC_FILES	+=	parse/ppm/ppm_file_handler.c
SRC_FILES	+=	parse/ppm/canvas_from_ppm.c
SRC_FILES	+=	parse/ppm/ppm_canvas_work.c

# PARSE/RT
SRC_FILES	+=	parse/rt/find_scene_file.c
SRC_FILES	+=	parse/rt/input.c
SRC_FILES	+=	parse/rt/canvas_colors.c

# PARSE/RT/FLAGS
SRC_FILES	+=	parse/rt/flags/flag_formatting.c
SRC_FILES	+=	parse/rt/flags/check_value_format.c
SRC_FILES	+=	parse/rt/flags/flag_utils.c
SRC_FILES	+=	parse/rt/flags/create_flag_nodes.c

# PARSE/RT/SCENE_FILE
SRC_FILES	+=	parse/rt/scene_file/create_mand.c
SRC_FILES	+=	parse/rt/scene_file/create_complex.c
SRC_FILES	+=	parse/rt/scene_file/create_cone.c
SRC_FILES	+=	parse/rt/scene_file/create_cylinder.c
SRC_FILES	+=	parse/rt/scene_file/create_shapes.c
SRC_FILES	+=	parse/rt/scene_file/file_data.c
SRC_FILES	+=	parse/rt/scene_file/check_data.c
SRC_FILES	+=	parse/rt/scene_file/create_bonus.c
SRC_FILES	+=	parse/rt/scene_file/to_object.c
SRC_FILES	+=	parse/rt/scene_file/append.c
SRC_FILES	+=	parse/rt/scene_file/ruleset.c
SRC_FILES	+=	parse/rt/scene_file/file_utils.c
SRC_FILES	+=	parse/rt/scene_file/create_obj.c
SRC_FILES	+=	parse/rt/scene_file/check_objects.c

# TEXTURES
SRC_FILES	+=	textures/texture_init.c
SRC_FILES	+=	textures/cube_obj.c
SRC_FILES	+=	textures/map_basic_obj.c
SRC_FILES	+=	textures/pattern_lib.c
SRC_FILES	+=	textures/cube_side_align_2.c
SRC_FILES	+=	textures/uv.c
SRC_FILES	+=	textures/pattern.c
SRC_FILES	+=	textures/align_check.c
SRC_FILES	+=	textures/bump_map.c
SRC_FILES	+=	textures/cube_side_align_1.c
SRC_FILES	+=	textures/mapped_cube.c

# TUPLE
SRC_FILES	+=	tuple/tuple_basic_op.c
SRC_FILES	+=	tuple/tuple_utils.c
SRC_FILES	+=	tuple/tuple_init.c
SRC_FILES	+=	tuple/tuple_color.c
SRC_FILES	+=	tuple/tuple_product_op.c

# VIEW
SRC_FILES	+=	view/camera_op.c
SRC_FILES	+=	view/view_transformation.c
SRC_FILES	+=	view/rotate_xyz.c

# RENDER

SRC_FILES	+=	render/free.c
SRC_FILES	+=	render/free2.c
SRC_FILES	+=	render/process_pixel.c
SRC_FILES	+=	render/process_pixel_2.c
SRC_FILES	+=	render/process_step_pixel.c
SRC_FILES	+=	render/render_loop_init.c
SRC_FILES	+=	render/render_loop.c
SRC_FILES	+=	render/render_mt.c
SRC_FILES	+=	render/render_standard.c
SRC_FILES	+=	render/render_standard2.c
SRC_FILES	+=	render/render_utils.c
SRC_FILES	+=	render/render_utils_2.c
SRC_FILES	+=	render/render_worker.c
SRC_FILES	+=	render/render_rand.c

# MAIN
SRC_FILES	+=	main.c

# Object files directory
OBJ_DIR         := .obj

# Object files
OBJ_FILES       := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Dependency files directory
DEP_DIR         := .dep

# Dependency files
DEPENDS         := $(patsubst %.o, $(DEP_DIR)/%.d, $(OBJ_FILES))
-include $(DEPENDS)

RM              := /bin/rm -f
MKDIR           := /bin/mkdir -p

.DEFAULT_GOAL   := all

all: ## Build this project
	@$(MAKE) libft
	@$(MAKE) mlx
	@$(MAKE) -j $(NAME)

libft: ## Build libft
	$(MAKE) -C $(LFT_DIR)

mlx: ## Build MLX42
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "MLX42 not found, please ensure it is cloned in $(MLX_DIR)"; \
		exit 1; \
	else \
		cd $(MLX_DIR) && ./configure && $(MAKE); \
	fi

WIDTH       ?= 720

# Compilation rule for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o, %.d, $@) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@$(MKDIR) $@

# Rule for linking the target executable
$(NAME): $(OBJ_FILES) $(LFT_A) $(MLX_A)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(INCLUDES) $(LIBS)
	-@echo -ne "🚀 $(MAGENTA)" && ls -lah $(NAME) && echo -ne "$(RESET)"

c clean: ## Clean objects and dependencies
	$(RM) $(OBJ_FILES)
	$(RM) -r $(OBJ_DIR)
	$(RM) $(DEPENDS)
	$(RM) -r $(DEP_DIR)

fc fclean: clean ## Restore project to initial state
	$(RM) $(NAME)

re: fclean all ## Rebuild project

h help: ## Show help info
	@grep -E '^[a-zA-Z_-_ ]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "$(BOLD)$(GREEN)/%-12s--$(RESET) %s\n", $$1, $$2}'

.PHONY: all re c clean fc fclean h help

# Delete failed targets
.DELETE_ON_ERROR:

###### COLORS ######
RESET       := \033[0m
BOLD        := \033[1m
UNDERLINE   := \033[4m

# Regular colors
BLACK       := \033[30m
RED         := \033[31m
GREEN       := \033[32m
YELLOW      := \033[33m
BLUE        := \033[34m
MAGENTA     := \033[35m
CYAN        := \033[36m
WHITE       := \033[37m

# Background colors
BG_BLACK    := \033[40m
BG_RED      := \033[41m
BG_GREEN    := \033[42m
BG_YELLOW   := \033[43m
BG_BLUE     := \033[44m
BG_MAGENTA  := \033[45m
BG_CYAN     := \033[46m
BG_WHITE    := \033[47m
