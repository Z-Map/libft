# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    neutronstar.vars.mk                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: map <map@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 19:00:26 by qloubier          #+#    #+#              #
#    Updated: 2019/08/10 23:23:00 by map              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#------------------------------------------------------------------------------#
#                              Setup                                           #
#------------------------------------------------------------------------------#


# Public vraiable

DEFAULT_PUBLIC_VARS		= 

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

# Required public variable
# PROJECT_NAME	=

ifndef PROJECT_NAME
  $(error Missing PROJECT_NAME variable)
endif

# Optional public vraiable
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
endif

# Optional private variable
# P_IINCDIRS	=
# P_INCS		= 
# SUBMAKES		= 
# NAME			= 

# Compile environnement var
BUILDIR			?= build
TARGETDIR		?= .
RENDERDIR		?= $(BUILDIR)/render
LOGNAME			?= $(USER)
CHRONOS_NAZI_MODE ?= on


# Compilation var
CFLAGS			?=
CC				?= clang
LC				?= ar
LFLAGS			?= -rcs

LINK_MODE		?= static

ifeq ($(CHRONOS_NAZI_MODE)_$(CC),on_clang)
  REQUIERED_CFLAGS		+= $(filter-out $(REQUIERED_CFLAGS), -Wextra -Werror -Weverything)
else
  REQUIERED_CFLAGS		+= $(filter-out $(REQUIERED_CFLAGS), -Wextra -Werror -Wall -Wpadded)
endif
