# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 18:25:14 by tatahere          #+#    #+#              #
#    Updated: 2024/10/25 19:08:06 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------------------------------------------------#
#	some usfull variable names												#
#---------------------------------------------------------------------------#

AR		= ar rcs
RF		= rm -rf
CC		= cc

SRCDIR	= src/
BINDIR	= bin/
INCDIR	= inc/

CINC			= -I$(LIBFTDIR) -I$(LIBMLXDIR)include -I$(INCDIR)
CDEBUG			= -g -fsanitize=address
CFLAGS			= -Wall -Wextra -Werror $(CINC) $(CDEBUG)

#---------------------------external libraries------------------------------#

#	libft

LIBFTDIR	=	libft/
LIBFTNAME	=	libft.a
LIBFT		=	$(LIBFTDIR)$(LIBFTNAME)

#	https://github.com/42-Fundacion-Telefonica/MLX42

#---------------------------------sections----------------------------------#

LIBMLXDIR	=	MLX42/
LIBMLXNAME	=	libmlx42.a
LIBMLX		=	$(LIBMLXDIR)build/$(LIBMLXNAME)
CFLAGSMLX	=	-ldl -lglfw -pthread -lm
CMAKELISTMLX	=	$(LIBMLXDIR)CMakeLists.txt

#	managment of the interface with the user
INTERFACE_SECTION_NAME		=	interface
INTERFACE_SECTION_DIR		=	$(SRCDIR)$(INTERFACE_SECTION_NAME)/
INTERFACE_SECTION			=	$(BINDIR)$(INTERFACE_SECTION_NAME).a

#	parsing of the files to be read by the grafics
FILE_PARSER_SECTION_NAME	=	parser
FILE_PARSER_SECTION_DIR		=	$(SRCDIR)$(FILE_PARSER_SECTION_NAME)/
FILE_PARSER_SECTION			=	$(BINDIR)$(FILE_PARSER_SECTION_NAME).a

#	render of the images to be displayed by the interface
GRAPHICS_SECTION_NAME		=	graphics
GRAPHICS_SECTION_DIR		=	$(SRCDIR)$(GRAPHICS_SECTION_NAME)/
GRAPHICS_SECTION			=	$(BINDIR)$(GRAPHICS_SECTION_NAME).a

#---------------------------------------------------------------------------#
#	main program															#
#---------------------------------------------------------------------------#

NAME	=	fdf
LIBS	=	$(FILE_PARSER_SECTION) $(INTERFACE_SECTION) $(GRAPHICS_SECTION) \
			$(LIBFT) $(LIBMLX)

SRCNAME	=	main.c			\
			init_state.c	\
			print_state.c	\
			rotations.c		\
			translations.c	\
			zooms.c			\

SRC		=	$(addprefix $(SRCDIR),$(SRCNAME))

OBJNAME	=	$(notdir $(SRC:.c=.o))
OBJ		=	$(addprefix $(BINDIR),$(OBJNAME))

DEPNAME	=	$(notdir $(SRC:.c=.d))
DEP		=	$(addprefix $(BINDIR),$(DEPNAME))

all: libmlx libft $(BINDIR) sections $(NAME)

$(NAME): $(OBJ) $(LIBS) Makefile
	echo $^
	echo $(LIBS)
	$(CC) $(CFLAGS) $(CFLAGSMLX) $(OBJ) $(LIBS) -o $(NAME)

$(BINDIR)%.o : $(SRCDIR)%.c Makefile
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BINDIR):
	mkdir -v $@

#---------------------------------------------------------------------------#
#	program sections														#
#---------------------------------------------------------------------------#


sections:
	make -C $(INTERFACE_SECTION_DIR)
	make -C $(FILE_PARSER_SECTION_DIR)
	make -C $(GRAPHICS_SECTION_DIR)

#---------------------------------------------------------------------------#
#	external libraries														#
#---------------------------------------------------------------------------#

#	libft

libft:	Makefile
	make -C $(LIBFTDIR) all

#	mlx

libmlx: $(CMAKELISTMLX) Makefile
	cmake $(LIBMLXDIR) -B $(LIBMLXDIR)/build && make -C $(LIBMLXDIR)/build -j4

$(CMAKELISTMLX):
	git submodule init
	git submodule update

#---------------------------------------------------------------------------#
#	some usefull utilyties													#
#---------------------------------------------------------------------------#

clean:
	rm -rf $(BINDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBMLXDIR)/build
	make -C $(LIBFTDIR) fclean

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus libmlx libft sections

-include $(DEP)
