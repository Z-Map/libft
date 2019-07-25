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
PROJECT_NAME	= ft
INCDIRS			= include
INCS			= 
SRCDIRS			= mem lst str format parse io wstr unicode printf math vmem
SRCS			= 
LIBS			= 
LIBDIRS			= 
LIBSHEADERS		=
OUT_CFG			= release
OUT_TYPE		= lib
OUT_NAME		= 

# Project private var
P_INCDIRS		=
P_INCS			= vmem/intern_vmem.h
SUBMAKES		= 
AUTO_SRCS		= on
AUTO_RECURSIVE	= on
NAME			= 

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
  CFLAGS		=
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

#------------------------------------------------------------------------------#
#                             Configuration                                    #
#------------------------------------------------------------------------------#

# Message display functions
ifeq ($(FANCY_OUT),on)
  generic_msg	= $(2); printf "\e[m%-80.80b\e[m\n" "$(1)"
  g_tmp_msg		= printf "\e[m%-80.80b\e[m\e[80D" "$(1)"; $(2)
  compile_msg	= printf "\e[33m%-74.74b\e[m[\e[33mwait\e[m]\e[80D\e[31m" \
  					"Compiling \e[0;1m$(1) \e[0;33m..."; $(2); printf \
					"\e[32m%-74.74b\e[m[\e[32mdone\e[m]\n" \
					"\e[0;1m$(1) \e[0;32mCompiled !"
  cleaning_msg	= printf "\e[31mCleaning %.71b\e[m\e[80D" \
  					"\e[0;1m$(1) \e[0;31m..."; $(2); printf \
					"\e[33;1m%.70b\e[0;31m cleaned !\e[m\n" "$(1)"
else
  generic_msg	= $(2)
  g_tmp_msg		= $(2)
  compile_msg	= $(2)
  cleaning_msg	= $(2)
endif

# Name processing
ifndef NAME_PREFIX
  ifeq ($(OUT_TYPE),lib)
    NAME_PREFIX	:= lib
  else
    NAME_PREFIX	:=
  endif
endif

ifndef NAME_SUFIX
  ifeq ($(OUT_TYPE)_$(LINK_MODE),lib_static)
    NAME_SUFIX	:= .a
  else ifeq ($(OUT_TYPE)_$(LINK_MODE),lib_shared)
    NAME_SUFIX	:= .so
  endif
endif

ifeq ($(OUT_NAME),)
	OUT_NAME	:= $(NAME_PREFIX)$(PROJECT_NAME)$(NAME_SUFIX)
endif

ifeq ($(NAME),)
	NAME		:= $(OUT_NAME)
endif

# Compile flag configuration
ifeq ($(OUT_CFG),release)
  CFLAGS		+= -Ofast
endif

ifeq ($(OUT_CFG),debug)
  CFLAGS		+= -O1 -g3 -fsanitize=address -fno-omit-frame-pointer \
  				-fno-optimize-sibling-calls
endif

ifeq ($(OUT_CFG),opti)
  CFLAGS		+= -Ofast
endif

I_LIB_FLAGS		:= $(addprefix -L,$(LIBDIRS)) $(addprefix -l,$(LIBS))
I_INC_FLAGS		:= $(addprefix -I,$(INCDIRS)) $(addprefix -i,$(INCS))

ifeq ($(OUT_TYPE)_$(LINK_MODE),lib_shared)
  I_OBJ_FLAGS	:= $(CFLAGS) -fPIC $(I_INC_FLAGS)
  I_OUT_FLAG	:= $(CFLAGS) -shared $(I_INC_FLAGS) $(I_LIB_FLAGS)
else
  I_OBJ_FLAGS	:= $(CFLAGS) $(I_INC_FLAGS)
  I_OUT_FLAG	:= $(CFLAGS) $(I_INC_FLAGS) $(I_LIB_FLAGS)
endif


# Compile files configuration

# Source search function definition
ifeq ($(AUTO_RECURSIVE),on)
  filesearch	= $(shell find $(1) -name "$(2)")
else
  filesearch	= $(shell find $(1) -depth 1 -name "$(2)")
endif

# Auto-search from source directories
ifeq ($(AUTO_SRCS),on)
  AUTO_SRCS		:= $(foreach module,$(SRCDIRS),$(call filesearch,$(module),*.c))
endif

# All sources file definition
I_SOURCE_FILES	:= $(SRCS) $(AUTO_SRCS)
# All headers file definition
I_INCLUDE_FILES	:= $(INCS) $(P_INCS) $(foreach module,$(SRCDIRS)\
	$(INCDIRS) $(P_INCDIRS),$(call filesearch,$(module),*.h))

# Render configuration

# Render sub directories definition
I_RENDER_DIRS	:= $(addprefix $(RENDERDIR)/,$(sort $(dir $(I_SOURCE_FILES)\
	$(I_INCLUDE_FILES))))

# Render source file list definition
I_RENDER_SRCS	:= $(addprefix $(RENDERDIR)/,$(I_SOURCE_FILES))

# Render header file list definition
I_RENDER_INCS	:= $(addprefix $(RENDERDIR)/,$(I_INCLUDE_FILES))

#------------------------------------------------------------------------------#
#                             Pre-build                                        #
#------------------------------------------------------------------------------#

# Build dir definition
ifneq ($(OUT_CFG),)
  I_BUILD_DIR	:= $(BUILDIR)/$(OUT_CFG)
else
  I_BUILD_DIR	:= $(BUILDIR)
endif

# Build sub dir definition
I_BUILD_O_DIR	:= $(I_BUILD_DIR)/obj
I_BUILD_D_DIR	:= $(I_BUILD_DIR)/d

# Object file list definition
I_OBJ_FILES		:= $(foreach ansrcfile,$(I_SOURCE_FILES:%.c=%),\
	$(I_BUILD_O_DIR)/$(subst /,+,$(ansrcfile)).o)

# Dependency file list definition
I_DEP_FILES		:= $(I_OBJ_FILES:$(I_BUILD_O_DIR)/%.o=$(I_BUILD_D_DIR)/%.d)

# Compiling functions

# Object compiling function definition
ifeq ($(CC),clang)
  compile_obj	= $(call compile_msg,$(notdir $(3)),$(CC) $(I_OBJ_FLAGS) \
					-MMD -MP -MT"$(1)" -MF $(2)\
					-c $(3) -o $(1))
else
  compile_obj	= $(call compile_msg,$(notdir $(3)),echo "$(1): $(3)" > $(2);\
  					$(CC) $(I_OBJ_FLAGS) -c $(3) -o $(1))
endif

# Target compiling function definition
ifeq ($(OUT_TYPE)_$(LINK_MODE),lib_static)
  compile_out	= $(call compile_msg,$(1),$(LC) $(LFLAGS) $(1) $(2))
else
  compile_out	= $(call compile_msg,$(1),$(CC) $(I_OUT_FLAG) -o $(1) $(2))
endif

#==============================================================================#
#                                 Rules                                        #
#==============================================================================#


.PHONY: lclean clean fclean re all render 

# Default target
all: $(TARGETDIR)/$(NAME)

# Light clean, just clean object files 
lclean:
	$(SILENT)$(call cleaning_msg,object files,rm -rf $(I_BUILD_O_DIR))

# Normal clean, clean object and dependency files 
clean: lclean
	$(SILENT)$(call cleaning_msg,dependency files,rm -rf $(I_BUILD_D_DIR))

# Full clean, clean object, dependency, and output files 
fclean: clean
	$(SILENT)$(call cleaning_msg,$(OUT_NAME),rm -f $(TARGETDIR)/$(OUT_NAME))

# Full clean then make all which effectively remake the target
re: fclean all

#------------------------------------------------------------------------------#
#                             Build Rules                                      #
#------------------------------------------------------------------------------#

# Create the build directories
$(I_BUILD_DIR):
	$(SILENT)$(call generic_msg,\e[33;1mBuild directory \e[0;32mcreated !,\
		mkdir -p $@)

$(I_BUILD_O_DIR): $(I_BUILD_DIR)
	$(SILENT)$(call generic_msg,\e[33;1mObject directory \e[0;32mcreated !,\
		mkdir -p $@)

$(I_BUILD_D_DIR): $(I_BUILD_DIR)
	$(SILENT)$(call generic_msg,\
		\e[33;1mDependency directory \e[0;32mcreated !,\
		mkdir -p $@)

# Make .o from the .c 
$(I_OBJ_FILES): | $(I_BUILD_O_DIR) $(I_BUILD_D_DIR)
	$(SILENT)$(call compile_obj,$@,\
		$(@:$(I_BUILD_O_DIR)/%.o=$(I_BUILD_D_DIR)/%.d),\
		$(subst +,/,$(@:$(I_BUILD_O_DIR)/%.o=%.c)))

# Include empty target with the dependencies for each .o files
-include $(I_DEP_FILES)

# Compile the target 
$(NAME): $(I_OBJ_FILES)
	$(SILENT)$(call compile_out,$@,$(I_OBJ_FILES))

# Create it and compile the target in the target directory if it is defined
ifneq ($(TARGETDIR),.)
  $(TARGETDIR):
  	$(SILENT)$(call generic_msg,\e[33;1mTarget directory \e[0;32mcreated !,\
  	mkdir -p $@)

  $(TARGETDIR)/$(NAME): $(I_OBJ_FILES) | $(TARGETDIR)
  	$(SILENT)$(call compile_out,$@,$(I_OBJ_FILES))
endif

# Compile the target with the default name in target directory
ifneq ($(NAME),$(OUT_NAME))
  $(TARGETDIR)/$(OUT_NAME): $(I_OBJ_FILES) | $(TARGETDIR)
  	$(SILENT)$(call compile_out,$@,$(I_OBJ_FILES))
endif

#------------------------------------------------------------------------------#
#                             Render Rules                                     #
#------------------------------------------------------------------------------#

# Create render directory
$(RENDERDIR):
	$(SILENT)$(call generic_msg,\e[35;1mRender directory \e[0;32mcreated !,\
		mkdir -p $@)

# Create sources directories in render directory
$(I_RENDER_DIRS): | $(RENDERDIR)
	$(SILENT)$(call g_tmp_msg,\e[33mCreating \e[35;1m$@\e[0;33m ...,\
		mkdir -p $@)

# Copy sources
$(I_RENDER_SRCS): $(RENDERDIR)/%.c: %.c | $(I_RENDER_DIRS)
	$(SILENT)$(call g_tmp_msg,\e[33mCopying \e[36;1m$@\e[0;33m ...,\
		cp $< $@)

# Copy headers
$(I_RENDER_INCS): $(RENDERDIR)/%.h: %.h | $(I_RENDER_DIRS)
	$(SILENT)$(call g_tmp_msg,\e[33mCopying \e[34;1m$@\e[0;33m ...,\
		cp $< $@)

# Generate Makefile in render directory
$(RENDERDIR)/Makefile: Makefile \
	$(I_RENDER_SRCS) $(I_RENDER_INCS) | $(RENDERDIR)
	$(SILENT)$(call g_tmp_msg,\e[33mCreating the makefile ...,head -n \
			$(shell awk '/AUTO_SRCS/{ print NR-1; exit }' Makefile) \
			Makefile > $(RENDERDIR)/Makefile)
	$(SILENT)echo "AUTO_SRCS = $(AUTO_SRCS)" >> $(RENDERDIR)/Makefile
	$(SILENT)$(call generic_msg,\e[35mMakefile \e[32m Created !, tail -n\
		+$(shell awk '/AUTO_SRCS/{ print NR+1; exit }' Makefile)\
		Makefile >> $(RENDERDIR)/Makefile)

# Render target
render: $(RENDERDIR)/Makefile

#------------------------------------------------------------------------------#
#                              Norme Rules                                     #
#------------------------------------------------------------------------------#

ifeq ($(FANCY_OUT),on)

# Fancy Out - Norminette
# Filter the stdout of the norminette throught a awk program, don't try to 
# understand it unless you really want to learn how awk works, even I don't 
# remember how I made it. 
norme:
# Check if we are on OSX
ifeq ($(OPSYS),Darwin)
	@printf "\e[33mChecking 42 Norme :\e[m\e[20D"
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
		}' > $(I_BUILD_DIR)/tmp_norme.txt
	@if [[ -s $(I_BUILD_DIR)/tmp_norme.txt ]];\
		then cat $(I_BUILD_DIR)/tmp_norme.txt;
		else printf "\\e[1;32mNo norme error on rt sources\\e[m\\n"; fi;
	@rm tmp_norme.txt
else
	@printf "\e[33mNo Norminette here\e[32m ... for now ;)\e[m\n"
endif

else

# Raw Out - Norminette
norme:
# Check if we are on OSX
ifeq ($(OPSYS),Darwin)
	@norminette $(ALLHEADER) $(ALLSRC)
else
	@echo "No Norminette here ... for now ;)"
endif

endif
