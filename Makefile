# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 18:38:45 by qloubier          #+#    #+#              #
#    Updated: 2019/05/29 13:44:47 by qloubier         ###   ########.fr        #
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
LIBS		= 
LIBSDIR		= 
LIBSHEADERS	=
OUT_CFG		= release
OUT_TYPE	= lib

# Project private var
P_IINCDIRS	=
P_INCS		= vmem/intern_vmem.h
SUBMAKES	= 
AUTO_SRCS	= on
AUTO_RECURSIVE = on

# Environnement var
BUILDIR		= build
TARGETDIR	= .
PROJECTPATH	= $(CURDIR)
OPSYS		= $(shell uname -s)
FANCY_OUT	= on
SILENT		= @
CHRONOS_NAZI_MODE = on

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
	CFLAGS+=-Wextra -Werror -Weverything
else
	CFLAGS+=-Wextra -Werror -Wall -Wpadded
endif

LFLAGS		= -rcs

#------------------------------------------------------------------------------#
#                             Pre-build                                        #
#------------------------------------------------------------------------------#

ifeq ($(AUTO_RECURSIVE),on)
	FILESEARCH = $(shell find $(0) -name "*.c")
else
	FILESEARCH = $(shell find $(0) -depth 1 -name "*.c")
endif

ifeq ($(AUTO_SRCS),on)
	AUTO_SRCS = $(foreach v,list,text)
endif

I_SOURCE_FILES = $(SRCS) $(AUTO_SRCS)

ifeq ($(OUT_CFG),release)
	CFLAGS	+= -Ofast
endif

ifeq ($(OUT_CFG),debug)
	CFLAGS	+= -O1 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

ifeq ($(OUT_CFG),opti)
	CFLAGS	+= -Ofast
endif

I_BUILD_DIR		= $(BUILDIR)/$(OUT_CFG)
I_BUILD_O_DIR	= $(I_BUILD_DIR)

all:
	$(SILENT)echo "$(I_SOURCE_FILES)"
