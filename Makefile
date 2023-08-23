NAME	= cub3D

CC		:= cc
FLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast #-fsanitize=address -g
LIBMLX	:= /Users/$(USER)/MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

INCLUDES = -I$(HEADERS_DIRECTORY) -I $(LIBMLX)/include

HEADERS_DIRECTORY = includes/
HEADERS_LIST =	cub3D.h \
				get_next_line.h \

HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY =	sources/
SOURCES_LIST =	cast.c \
				check_map.c \
				clean_map.c \
				color_set.c \
				cub3D.c \
				door.c \
				face_path.c \
				get_out.c \
				get_rgba.c \
				init_texture.c \
				init.c \
				loop.c \
				mouse.c \
				move.c \
				print_texture.c \
				read_map.c \
				selections.c \
				smap_map.c \
				tot.c \
				free_all.c \
				wall_coll_check.c \

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

LIBFT_DIRECTORY =	libft/
LIBFT_SOURCES_LIST =	ft_atoi.c \
						ft_clean.c \
						ft_itoa.c \
						ft_is.c \
						ft_lstadd_back.c \
						ft_lstclear.c \
						ft_lstlast.c \
						ft_lstnew.c \
						ft_lstsize.c \
						ft_putchar_fd.c \
						ft_putstr_fd.c \
						ft_strdup.c \
						ft_strjoin.c \
						ft_strlen.c \
						ft_strncmp.c \
						ft_strstr.c \
						get_next_line_utils.c \
						get_next_line.c \

LIBFT_SOURCES = $(addprefix $(LIBFT_DIRECTORY), $(LIBFT_SOURCES_LIST))

SOURCES_LIST += $(LIBFT_SOURCES_LIST)
SOURCES += $(LIBFT_SOURCES)

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re libmlx

all: libmlx $(NAME)

bonus: all

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(OBJECTS_DIRECTORY)%.o : $(LIBFT_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
	@make -C $(LIBFT_DIRECTORY) re
