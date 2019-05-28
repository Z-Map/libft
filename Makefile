# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 18:38:45 by qloubier          #+#    #+#              #
#    Updated: 2019/05/28 18:38:45 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                              Setup                                           #
#------------------------------------------------------------------------------#

# Project public var
NAME		= ft
INCDIRS		= include
INCS		= 
SRCDIRS		= mem lst str format parse io wstr unicode printf math vmem
SRCS		= 


# Environnement var
LIBS		= 
LIBSDIR		= 
LIBSHEADERS	=
OPSYS		= $(shell uname -s)
FANCY_OUT	= on
CHRONOS_NAZI_MODE = on

ifndef config
	config=release
endif

ifndef LOGNAME
	LOGNAME=$(USER)
endif

# Compilation var
ifndef CC
	CC=clang
endif

ifndef LC
	LC=ar
endif
ifeq ($(CHRONOS_NAZI_MODE)_$(CC),on_clang)
	CFLAGS=-Wextra -Werror -Weverything
else
	CFLAGS=-Wextra -Werror -Wall -Wpadded
endif

LFLAGS		= -rcs

ifeq ($(config),release)
	CFLAGS	+= -Ofast
	OBJDIR	= release
endif

ifeq ($(config),debug)
	CFLAGS	+= -O1 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
	OBJDIR	= debug
endif

ifeq ($(config),opti)
	CFLAGS	+= -Ofast
	OBJDIR	= opti
endif

BUILDIR		= build/$(OBJDIR)
TARGETDIR	= .
PROJECTPATH	= $(CURDIR)