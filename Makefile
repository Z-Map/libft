#               [ MakeNeutronStar ]                   _______________________  #
#---*==========={=================}=============*----|                       |-#
#   |            AAA         KKKK    KKKK       |    |  By : _Map_           | #
#   |           AAAAA        KEEE   KKKK        |    |                       | #
#   |          AAA AAA       KEKK  KKKK         |    |  License : LGPL       | #
#   |         AAA   AAA      KEKKOKKKK          |    \_______________________| #
#   |        AAAAAAAAAAA     KEEO OMK           |                              #
#   |       AAAAAAAAAAAAA    KEKKOKKKK          |                              #
#   |      AAAAA     AAAAA   KEKK  KKKK         |                              #
#   |     AAAAA       AAAAA  KEEE   KKKK        |                              #
#   |    AAAAA   LIB   AAAAA KKKK    KKKK       |                              #
#   *===========================================*                              #

#------------------------------------------------------------------------------#
#                              Setup                                           #
#------------------------------------------------------------------------------#

# Project var
NAME=libft.a
HEADERS=include
SOURCES=mem lst str format
MKLIBS=libft/libft.a libdraw/libdraw.a minilibx/libmlx.a
LIBSHEADERS=
LIBS=m bsd
LIBSDIRS=

# Environnement var
LIBSDIR=libs/
OPSYS=$(shell uname -s)
FANCY_OUT=on
CHRONOS_NAZI_MODE=off
ifndef config
	config=release
endif

# Compilation var
CC=clang
LC=ar
ifeq ($(CHRONOS_NAZI_MODE),on)
	CFLAGS=-Wextra -Werror -Weverything
else
	CFLAGS=-Wextra -Werror -Wall
endif
LFLAGS= -rcs
BUILDIR=build
ifeq ($(config),release)
	OBJDIR=Release
endif

ifeq ($(config),debug)
	CFLAGS+=-g
	OBJDIR=Debug
endif

ifeq ($(config),opti)
	CFLAGS+=-Ofast
	OBJDIR=Opti
endif

# Render var
RENDERDIR=
RENDER_BY=qloubier
RENDER_EMAIL=marvin@student.42.fr

# Messages

LINE_LEN=80
MSG_COMPILE_LIB=Creating :
MSG_COMPILE_EXE=Compiling :
MSG_COMPILE_OBJ=Compiling :
MSG_COMPILE_DONE=is done !
MSG_CLEAN_OBJECTS=Clean Objects files
MSG_CLEAN_LIB=Clean Library file
MSG_CLEAN_EXE=Clean Executable

#===============================================================================
# intern var
ifeq ($(FANCY_OUT),on)
	SILENT=@
else
	SILENT=
endif
ifeq ($(shell printf "$(NAME)" | tail -c2),.a)
	I_MSG_COMPILE=$(MSG_COMPILE_LIB)
	I_MSG_CLEAN=$(MSG_COMPILE_LIB)
	BUILDTYPE=lib
	I_REAL_NAME=$(shell printf "$(NAME)" | tail -c-2)
else
	I_MSG_COMPILE=$(MSG_COMPILE_EXE)
	I_MSG_CLEAN=$(MSG_COMPILE_EXE)
	BUILDTYPE=exe
	I_REAL_NAME=$(NAME)
endif
ifeq (RENDERDIR,)
	RENDERDIR=$(BUILDIR)/$(I_REAL_NAME)
endif
I_DATE=$(shell date "+%Y/%m/%d")
I_TIME=$(shell date "+%H:%M:%S")
I_NAME_LEN=$(shell printf "$(NAME)" | wc -c)
I_MSGC_LEN=$(shell printf "$(I_MSG_COMPILE)" | wc -c)
I_MSGO_LEN=$(shell printf "$(MSG_COMPILE_OBJ)" | wc -c)
I_WIP_LEN=$(shell echo "$(LINE_LEN) - 13" | bc)
I_OK_LEN=$(shell echo "$(LINE_LEN) - 6" | bc)
I_MSG_START_WIP=\\e[$(LINE_LEN)D%-$(I_WIP_LEN).$(I_WIP_LEN)b
I_MSG_END_WIP=\\e[m[\\e[33min progress\\e[m]\\e[$(LINE_LEN)D
I_MSG_START_OK=\\e[$(LINE_LEN)D%-$(I_OK_LEN).$(I_OK_LEN)b
I_MSG_END_OK=\\e[m[\\e[32mok\\e[m]\\n
OBBUDIR=$(BUILDIR)/$(OBJDIR)
OBBUWC=$(shell echo "$(OBBUDIR)/" | wc -c)
OBBUDIRS=$(BUILDIR) $(OBBUDIR) $(shell for dir in $(SOURCES); do printf "$(OBBUDIR)/$$dir "; done)
ALLINC=$(HEADERS) $(LIBSHEADERS)
INCFLAGS=$(shell echo "-I$(ALLINC)" | sed "s/ \(.\)/ -I\1/g")
ALLHEADER=$(shell find *.h -type f 2> /dev/null; for dir in $(HEADERS); do find $$dir/*.h -type f 2> /dev/null; done)
ALLSRC=$(shell find *.c -type f 2> /dev/null; for dir in $(SOURCES); do find $$dir/*.c -type f 2> /dev/null; done)
ALLOBJ=$(shell for oname in $(ALLSRC:.c=.o); do printf "$(OBBUDIR)/$$oname "; done)
ALLLIBSDIRS=$(shell for lib in $(MKLIBS); do dirname "$(LIBSDIR)$$lib"; done) $(LIBSDIRS)
ALLLIBS=$(shell for lib in $(MKLIBS); do basename "$$lib" | head -c-3 | tail -c+4; printf " "; done)$(LIBS)
LIBSFLAGS=$(shell echo "-L$(ALLLIBSDIRS)" | sed "s/ \(.\)/ -L\1/g") $(shell echo "-l$(ALLLIBS)" | sed "s/ \(.\)/ -l\1/g")
ALLCFLAGS=$(CFLAGS) $(INCFLAGS)
I_MKFLIB=$(shell for lib in $(MKLIBS); do dirname "$(LIBSDIR)$$lib" | xargs -0 printf "%s/ "; done)
I_MKNSLIB=
# ALLDEP=$(ALLOBJ:.o=.d)

RENDER_SUBDIRS=$(shell for dir in $(OBBUDIRS); do printf "$(RENDERDIR)/$$dir "; done)
RENDER_SRC=$(shell for cname in $(ALLSRC); do printf "$(RENDERDIR)/$$cname "; done)
RENDER_HEADERS=$(shell for hname in $(ALLHEADER); do printf "$(RENDERDIR)/$$hname "; done)

#------------------------------------------------------------------------------#
#                             Compile Rules                                    #
#------------------------------------------------------------------------------#

# PHONY rules
.PHONY: neutronstar all clean fclean re \
		norme render

# Generic rules
all: $(NAME)

install:

clean:
ifeq ($(FANCY_OUT),on)
	@printf "$(I_MSG_START_WIP)       $(I_MSG_END_WIP)" "\e[33m$(MSG_CLEAN_OBJECTS) \e[mfor \e[1m\e[35m$(NAME)"
endif
	$(SILENT)rm -rf $(OBBUDIR)
ifeq ($(FANCY_OUT),on)
	@printf "$(I_MSG_START_OK)         $(I_MSG_END_OK)" "\e[31m$(MSG_CLEAN_OBJECTS) \e[mfor \e[1m\e[35m$(NAME)"
endif

fclean: clean
ifeq ($(FANCY_OUT),on)
	@printf "$(I_MSG_START_WIP)       $(I_MSG_END_WIP)" "\e[33m$(I_MSG_CLEAN) \e[mfor \e[1m\e[35m$(NAME)"
endif
	$(SILENT)rm -rf $(NAME)
ifeq ($(FANCY_OUT),on)
	@printf "$(I_MSG_START_OK)         $(I_MSG_END_OK)" "\e[31m$(MSG_CLEAN_OBJECTS) \e[mfor \e[1m\e[35m$(NAME)"
endif

re: fclean all

neutronstar:
	@sh -c 'printf "\t[Creating Neutron Star]\n\n\t   \e[1;30m[\e[mo\e[1;30m}         {\e[mo\e[1;30m]\e[m"; sleep 1; \
	printf "\e[15D\e[1;30m[\e[m\e[1mo\e[1;30m}         {\e[m\e[1mo\e[1;30m]\e[m"; sleep 0.8; \
	printf "\e[15D\e[1;30m[\e[m\e[1;33mo\e[1;30m}         {\e[1;33mo\e[1;30m]\e[m"; sleep 0.5; \
	printf "\e[15D\e[1;30m[\e[m\e[1;31mo\e[1;30m}         {\e[1;31mo\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[31mo\e[1;30m}         {\e[0;31mo\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[1;31mo\e[1;30m}         {\e[1;31mo\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[31mo\e[1;30m}         {\e[0;31mo\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[1;31mo\e[1;30m}         {\e[1;31mo\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[31mo\e[1;30m}         {\e[0;31mo\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[1;31mo\e[1;30m}         {\e[1;31mo\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[31mo\e[1;30m}         {\e[0;31mo\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36mo\e[1;30m}         {\e[1;36mo\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36mO\e[1;30m}         {\e[1;36mO\e[1;30m]\e[m"; sleep 0.1; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36mO\e[m\e[33m}~-  ~  -~\e[33m{\e[1;36mO\e[1;30m]\e[m"; sleep 0.1; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36mO\e[m\e[33m}-~-~-~-~-\e[33m{\e[1;36mO\e[1;30m]\e[m"; sleep 0.1; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36mO\e[m\e[33m}--~~+~~--\e[33m{\e[1;36mO\e[1;30m]\e[m"; sleep 0.1; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36mO\e[m\e[33m}--~~\e[36m=\e[33m~~--\e[33m{\e[1;36mO\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36mO\e[m\e[33m}~-~\e[36m=o=\e[33m~-~\e[33m{\e[1;36mO\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36mO\e[m\e[33m}--\e[36m~<@>~\e[33m--\e[33m{\e[1;36mO\e[1;30m]\e[m"; sleep 0.1; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36m@\e[0;33m}\e[36m--~:*:~--\e[33m{\e[1;36m@\e[1;30m]\e[m"; sleep 0.1; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36m*\e[0;33m}\e[36m-~-~\e[m\e[1m*\e[0;36m~-~-\e[33m{\e[1;36m*\e[1;30m]\e[m"; sleep 0.1; \
	printf "\e[15D\e[1;30m[\e[m\e[36m*\e[0;33m}\e[36m~---\e[m\e[m*\e[0;36m---~\e[33m{\e[36m*\e[1;30m]\e[m"; sleep 0.1; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36m*\e[0;33m}\e[36m--~<\e[m\e[1m*\e[0;36m>~--\e[33m{\e[1;36m*\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[36m*\e[0;33m}\e[36m-~--\e[m\e[m*\e[0;36m--~-\e[33m{\e[36m*\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36m*\e[0;33m}\e[36m~---\e[m\e[1m*\e[0;36m---~\e[33m{\e[1;36m*\e[1;30m]\e[m"; sleep 0.4; \
	printf "\e[15D\e[1;30m[\e[m\e[36m*\e[0;33m}\e[36m----\e[m\e[m*\e[0;36m----\e[33m{\e[36m*\e[1;30m]\e[m"; sleep 0.4; \
	c=0; while [ $$c -le $(LINE_LEN) ]; do \
	printf "\e[15D\e[1;30m[\e[m\e[1;36m*\e[0;33m}\e[36m--~<\e[m\e[1m@\e[0;36m>~--\e[33m{\e[1;36m*\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[36m*\e[0;33m}\e[36m-~-{\e[m\e[m@\e[0m\e[36m}-~-\e[33m{\e[36m*\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[36m*\e[0;33m}\e[36m~--+\e[m\e[m@\e[0m\e[36m+--~\e[33m{\e[36m*\e[1;30m]\e[m"; sleep 0.2; \
	printf "\e[15D\e[1;30m[\e[m\e[1;36m*\e[0;33m}\e[36m---=\e[m\e[1m*\e[0m\e[36m=---\e[33m{\e[1;36m*\e[1;30m]\e[m"; sleep 0.1; \
	printf "\e[15D\e[1;30m[\e[m\e[36m*\e[0;33m}\e[36m----\e[m*\e[0;36m----\e[33m{\e[36m*\e[1;30m]\e[m"; sleep 0.1; \
	c=$$(echo "$$c + 1" | bc);\
	done'

# Compilation rules
$(NAME): $(OBBUDIRS) $(ALLOBJ)
ifeq ($(FANCY_OUT),on)
	@printf "$(I_MSG_START_WIP)    $(I_MSG_END_WIP)" "\e[33m$(I_MSG_COMPILE) \e[1m\e[35m$(NAME)"
endif
ifeq ($(BUILDTYPE),lib)
	$(SILENT)$(LC) $(LFLAGS) $(NAME) $(ALLOBJ)
else
	$(SILENT)$(CC) $(ALLOBJ) -o $@ $(ALLCFLAGS) $(LIBSFLAGS)
endif
ifeq ($(FANCY_OUT),on)
	@printf "$(I_MSG_START_OK)    $(I_MSG_END_OK)" "\e[1m\e[36m$(NAME)\e[m $(MSG_COMPILE_DONE)"
endif

$(ALLOBJ): $(OBBUDIR)/%.o: %.c
ifeq ($(FANCY_OUT),on)
	@printf "$(I_MSG_START_WIP)$(I_MSG_END_WIP)" "\e[33m$(MSG_COMPILE_OBJ) \e[35m$<"
endif
	$(SILENT)$(CC) -o $@ -c $< $(ALLCFLAGS)
ifeq ($(FANCY_OUT),on)
	@printf "$(I_MSG_START_OK)$(I_MSG_END_OK)" "\e[36m$< \e[m$(MSG_COMPILE_DONE)"
endif

$(OBBUDIRS):
	$(SILENT)mkdir -p $@

# 42 target

$(RENDER_SUBDIRS):
	$(SILENT)mkdir -p $@

ifeq ($(FANCY_OUT),on)

norme:
ifeq ($(OPSYS),Darwin)
	@printf "\e[33mChecking 42 Norme :\e[m\n"
	@norminette $(ALLHEADER) $(ALLSRC) | awk 'BEGIN { FS=":"; filename="" }\
	 	$$1 == "Norme" { filename=$$2; }\
		$$1 ~ /Error .+/ { \
			if (filename != "") {\
				print "\n\033[1;31mErrors on :\033[0;36m"filename;\
				filename=""\
			} \
			sub("Error ","",$$1);\
			if ($$2 == " C++ comment") { print "\033[0;33m"$$1"\033[32m"$$2 }\
			else { print "\033[0;33m"$$1"\033[0m"$$2 }\
		}'
else
	@printf "\e[33mNo Norminette here\e[m\n"
endif

else

norme:
ifeq ($(OPSYS),Darwin)
	@norminette $(ALLHEADER) $(ALLSRC)
else
	@echo "No Norminette here"
endif

endif

render: $(RENDERDIR)/Makefile

$(RENDERDIR)/Makefile: $(RENDER_SUBDIRS) $(RENDER_HEADERS) $(RENDER_SRC)
	@printf "# **************************************************************************** #\n\
#                                                                              #\n\
#                                                         :::      ::::::::    #\n\
#    Makefile                                           :+:      :+:    :+:    #\n\
#                                                     +:+ +:+         +:+      #\n\
#    By: %-43.43s+#+  +:+       +#+         #\n\
#                                                 +#+#+#+#+#+   +#+            #\n\
#    Created: %-41.41s#+#    #+#              #\n\
#    Updated: %-40.40s###   ########.fr        #\n\
#                                                                              #\n\
# **************************************************************************** #\n\n"\
"$(RENDER_BY) <$(RENDER_EMAIL)>" "$(I_DATE) $(I_TIME) by $(RENDER_BY)" \
"$(I_DATE) $(I_TIME) by $(RENDER_BY)" > $(RENDERDIR)/Makefile


$(RENDER_SRC): $(RENDERDIR)/%.c: %.c
	$(SILENT)cp $< $@

$(RENDER_HEADERS): $(RENDERDIR)/%.h: %.h
	$(SILENT)cp $< $@
