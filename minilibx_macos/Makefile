#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

NOC		=	\033[0m
GREEN	=	\033[0;32m
BLUE	=	\033[0;34m

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "$(GREEN)LIBMLX ✓ libmlx.a ready$(NOC)"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@echo "$(BLUE)LIBMLX ✓ Removed .o files$(NOC)"

re: clean all
