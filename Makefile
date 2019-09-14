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

include neutronstar.utils.mk

#------------------------------------------------------------------------------#
#                              Setup                                           #
#------------------------------------------------------------------------------#

# Project public var
PROJECT_NAME	= ft
INCDIRS			= include
SRCDIRS			= mem lst str format parse io wstr unicode printf math vmem
OUT_CFG			= release
OUT_TYPE		= lib

# Project private var
P_INCS			= vmem/intern_vmem.h
AUTO_SRCS		= on
AUTO_RECURSIVE	= on

# Compilation var
CHRONOS_NAZI_MODE	= on
LINK_MODE		= static


include neutronstar.vars.mk

include neutronstar.config.mk

# Default target
all: $(TARGETDIR)/$(NAME)

include neutronstar.rules.mk
