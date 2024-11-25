# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 18:25:14 by tatahere          #+#    #+#              #
#    Updated: 2024/10/25 13:31:15 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------------------------------------------------#
#	some usfull variable names												#
#---------------------------------------------------------------------------#

AR		= ar rcs
RF		= rm -rf
CC		= cc

GIT_ROOTDIR	=	../../

SRCDIR		= ./
BINDIR		= $(GIT_ROOTDIR)bin/
INCDIR		= $(GIT_ROOTDIR)inc/

LIBFTDIR	=	$(GIT_ROOTDIR)libft/
LIBFTNAME	=	libft.a
LIBFT		=	$(LIBFTDIR)$(LIBFTNAME)

LIBMLXDIR	=	$(GIT_ROOTDIR)MLX42/include
LIBMLXNAME	=	libmlx42.a
LIBMLX		=	$(LIBMLXDIR)$(LIBMLXNAME)

CINC			= -I$(LIBMLXDIR) -I$(LIBFTDIR) -I$(INCDIR)
CDEBUG			= -g -fsanitize=address
CFLAGS			= -Wall -Wextra -Werror $(CINC) $(CDEBUG)

#---------------------------------------------------------------------------#
#	program files															#
#---------------------------------------------------------------------------#

SRC		=	init.c					\
			hooks.c					\
			display_managment.c		\
			movment_control_hooks.c	\
			program_control_hooks.c	\

OBJBN	=	$(notdir $(SRC:.c=.o))
OBJ		=	$(addprefix $(BINDIR),$(OBJBN))

DEPBN	=	$(notdir $(SRC:.c=.d))
DEP		=	$(addprefix $(BINDIR),$(DEPBN))

#---------------------------------------------------------------------------#
#	compilation																#
#---------------------------------------------------------------------------#

LIBS	=	$(LIBFT)
BNAME	=	interface.a
NAME	=	$(BINDIR)$(BNAME)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ) $(LIBS)

$(BINDIR)%.o: %.c Makefile
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

.PHONY: all

-include $(DEP)
