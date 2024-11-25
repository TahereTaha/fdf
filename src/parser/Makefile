# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 18:25:14 by tatahere          #+#    #+#              #
#    Updated: 2024/10/25 13:31:25 by tatahere         ###   ########.fr        #
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

CINC			= -I$(LIBFTDIR) -I$(INCDIR)
CDEBUG			= -g -fsanitize=address
CFLAGS			= -Wall -Wextra -Werror $(CINC) $(CDEBUG)

#---------------------------------------------------------------------------#
#	program files															#
#---------------------------------------------------------------------------#

SRC		=	read_file.c		\
			utils.c			\
			parse_point.c	\
			parse_map.c		\
			parse_file.c	\

OBJBN	=	$(notdir $(SRC:.c=.o))
OBJ		=	$(addprefix $(BINDIR),$(OBJBN))

DEPBN	=	$(notdir $(SRC:.c=.d))
DEP		=	$(addprefix $(BINDIR),$(DEPBN))

#---------------------------------------------------------------------------#
#	compilation																#
#---------------------------------------------------------------------------#

LIBS	=	$(LIBFT)
NAME	=	$(BINDIR)parser.a

all:		$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ) 

$(BINDIR)%.o: %.c Makefile
	$(CC) $(CFLAGS) -MMD -c $< -o $@

.PHONY: all test

-include $(DEP)
