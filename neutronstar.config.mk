# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    neutronstar.config.mk                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 18:53:57 by qloubier          #+#    #+#              #
#    Updated: 2019/07/25 19:00:19 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#------------------------------------------------------------------------------#
#                             Configuration                                    #
#------------------------------------------------------------------------------#

# Message display functions
ifeq ($(FANCY_OUT),on)
  generic_msg	= $(2); printf "\e[m%-80.80b\e[m\n" "$(1)"
  g_tmp_msg		= printf "\e[m%-80.80b\e[m\e[80D" "$(1)"; $(2)
  compile_msg	= printf "\e[33m%-74.74b\e[m[\e[33mwait\e[m]\e[80D\e[31m" \
  					"Compiling \e[0;1m$(1) \e[0;33m..."; $(2) && printf \
					"\e[32m%-74.74b\e[m[\e[32mdone\e[m]\n" \
					"\e[0;1m$(1) \e[0;32mCompiled !"
  cleaning_msg	= printf "\e[31mCleaning %.71b\e[m\e[80D" \
  					"\e[0;1m$(1) \e[0;31m..."; $(2) && printf \
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

I_LIB_FLAGS		:= $(sort $(addprefix -L,$(LIBDIRS)) $(addprefix -l,$(LIBS)) \
				$(foreach submake,$(SUBMAKES),$(shell cd $(submake) && make getlib)))
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
I_INCLUDE_FILES	:= $(INCS) $(foreach module,$(SRCDIRS)\
	$(INCDIRS),$(call filesearch,$(module),*.h))

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
I_BUILD_L_DIR	:= $(I_BUILD_DIR)/lib

I_SUBUILD_DIR	:= $(addprefix $(I_BUILD_DIR)/,$(SUBMAKES))

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