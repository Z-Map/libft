#---*===========================================*----|                       |-#
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

# Messages

LINE_LEN=80
MSG_COMPILE_LIB=Creating :
MSG_COMPILE_EXE=Compiling :
MSG_COMPILE_OBJ=Compiling :
MSG_COMPILE_DONE=is done !

#===============================================================================
# intern var
ifeq ($(FANCY_OUT),on)
	SILENT=@
else
	SILENT=
endif
ifeq ($(shell printf "$(NAME)" | tail -c2),.a)
	I_MSG_COMPILE=$(MSG_COMPILE_LIB)
	BUILDTYPE=lib
else
	I_MSG_COMPILE=$(MSG_COMPILE_EXE)
	BUILDTYPE=exe
endif
I_NAME_LEN=$(shell printf "$(NAME)" | wc -c)
I_MSGC_LEN=$(shell printf "$(I_MSG_COMPILE)" | wc -c)
I_MSGO_LEN=$(shell printf "$(MSG_COMPILE_OBJ)" | wc -c)
I_WIP_LEN=$(shell echo "$(LINE_LEN) - 13" | bc)
I_OK_LEN=$(shell echo "$(LINE_LEN) - 6" | bc)
OBBUDIR=$(BUILDIR)/$(OBJDIR)
OBBUWC=$(shell echo "$(OBBUDIR)/" | wc -c)
OBBUDIRS=$(BUILDIR) $(OBBUDIR) $(shell for dir in $(SOURCES); do printf "$(OBBUDIR)/$$dir "; done)
ALLINC=$(HEADERS) $(LIBSHEADERS)
INCFLAGS=$(shell echo "-I$(ALLINC)" | sed "s/ \(.\)/ -I\1/g")
ALLHEADER=$(shell find *.h -printf "%f "; for dir in $(HEADERS); do find $$dir/*.h -type f; done)
ALLSRC=$(shell find *.c -printf "%f "; for dir in $(SOURCES); do find $$dir/*.c -type f; done)
ALLOBJ=$(shell for oname in $(ALLSRC:.c=.o); do printf "$(OBBUDIR)/$$oname "; done)
ALLLIBSDIRS=$(shell for lib in $(MKLIBS); do dirname "$(LIBSDIR)$$lib"; done) $(LIBSDIRS)
ALLLIBS=$(shell for lib in $(MKLIBS); do basename "$$lib" | head -c-3 | tail -c+4; printf " "; done)$(LIBS)
LIBSFLAGS=$(shell echo "-L$(ALLLIBSDIRS)" | sed "s/ \(.\)/ -L\1/g") $(shell echo "-l$(ALLLIBS)" | sed "s/ \(.\)/ -l\1/g")
# ALLDEP=$(ALLOBJ:.o=.d)
ALLCFLAGS=$(CFLAGS) $(INCFLAGS)

#------------------------------------------------------------------------------#
#                             Compile Rules                                    #
#------------------------------------------------------------------------------#

# PHONY rules
.PHONY: all clean fclean re \
		norme render

# Generic rules
all: $(NAME)

install:

clean:
	$(SILENT)rm -rf $(OBBUDIR)

fclean: clean
	$(SILENT)rm -rf $(NAME)

re: fclean all

# Compilation rules
$(NAME): $(OBBUDIRS) $(ALLOBJ)
ifeq ($(FANCY_OUT),on)
	@printf "%-$(I_WIP_LEN).$(I_WIP_LEN)b    \e[m[\e[33min progress\e[m]\e[$(LINE_LEN)D" "\e[33m$(I_MSG_COMPILE) \e[1m\e[35m$(NAME)"
endif
ifeq ($(BUILDTYPE),lib)
	$(SILENT)$(LC) $(LFLAGS) $(NAME) $(ALLOBJ)
else
	$(SILENT)$(CC) $(ALLOBJ) -o $@ $(ALLCFLAGS) $(LIBSFLAGS)
endif
ifeq ($(FANCY_OUT),on)
	@printf "%-$(I_OK_LEN).$(I_OK_LEN)b    \e[m[\e[32mok\e[m]\n" "\e[1m\e[36m$(NAME)\e[m $(MSG_COMPILE_DONE)"
endif

$(ALLOBJ): $(OBBUDIR)/%.o: %.c
ifeq ($(FANCY_OUT),on)
	@printf "%-$(I_WIP_LEN).$(I_WIP_LEN)b\e[m[\e[33min progress\e[m]\e[$(LINE_LEN)D" "\e[33m$(MSG_COMPILE_OBJ) \e[35m$<"
endif
	$(SILENT)$(CC) -o $@ -c $< $(ALLCFLAGS)
ifeq ($(FANCY_OUT),on)
	@printf "%-$(I_OK_LEN).$(I_OK_LEN)b\e[m[\e[32mok\e[m]\n" "\e[36m$< \e[m$(MSG_COMPILE_DONE)"
endif

$(OBBUDIRS):
	$(SILENT)mkdir -p $@

# 42 target

ifeq ($(FANCY_OUT),on)

norme:
ifeq ($(OPSYS),Darwin)
	@printf "\e[33mChecking 42 Norme :\e[m\n"
	@norminette $(ALLHEADER) $(ALLSRC)
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

render:
