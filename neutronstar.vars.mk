# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    neutronstar.vars.mk                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 19:00:26 by qloubier          #+#    #+#              #
#    Updated: 2019/07/25 19:25:54 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#------------------------------------------------------------------------------#
#                              Setup                                           #
#------------------------------------------------------------------------------#


# Public vraiable

DEFAULT_PUBLIC_VARS = 

ifndef INCDIRS
  INCDIRS				= include
  DEFAULT_PUBLIC_VARS	+= INCDIRS
endif

ifndef SRCDIRS
  SRCDIRS				= src
  DEFAULT_PUBLIC_VARS	+= SRCDIRS
endif

ifndef OUT_CFG
  OUT_CFG				= release
  DEFAULT_PUBLIC_VARS	+= OUT_CFG
endif

ifndef OUT_TYPE
  OUT_TYPE				= exe
  DEFAULT_PUBLIC_VARS	+= OUT_TYPE
endif

# Optional public vraiable
# PROJECT_NAME	=
# INCS			= 
# SRCS			= 
# LIBS			= 
# LIBDIRS		= 
# LIBSHEADERS	=
# OUT_NAME		= 

# Project private var
ifndef AUTO_SRCS
  AUTO_SRCS				= on
endif

ifndef AUTO_RECURSIVE
  AUTO_RECURSIVE		= on

# Optional private variable
# P_IINCDIRS	=
# P_INCS		= 
# SUBMAKES		= 
# NAME			= 

# Environnement var
BUILDIR			= build
TARGETDIR		= .
RENDERDIR		= $(BUILDIR)/render
PROJECTPATH		:= $(CURDIR)
OPSYS			:= $(shell uname -s)
SILENT			= @
CHRONOS_NAZI_MODE = on

ifeq ($(SILENT),@)
  FANCY_OUT		= on
else
  FANCY_OUT		= off
endif

ifndef LOGNAME
  LOGNAME		=$(USER)
endif

# Compilation var
ifndef CFLAGS
  CFLAGS		= -pthread 
endif

ifndef CC
  CC			= clang
endif

ifndef LC
  LC			= ar
endif

LINK_MODE		= static

ifeq ($(CHRONOS_NAZI_MODE)_$(CC),on_clang)
  CFLAGS		+= -Wextra -Werror -Weverything
else
  CFLAGS		+= -Wextra -Werror -Wall -Wpadded
endif

LFLAGS			= -rcs