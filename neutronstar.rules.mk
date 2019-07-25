# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    neutronstar.rules.mk                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 18:56:46 by qloubier          #+#    #+#              #
#    Updated: 2019/07/25 18:56:47 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#==============================================================================#
#                                 Rules                                        #
#==============================================================================#

.PHONY: lclean clean fclean re all render 

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

getname:
	@printf "$(NAME)"

getlib:
	@printf "$(I_LIB_FLAGS)"

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

$(I_BUILD_L_DIR): $(I_BUILD_DIR)
	$(SILENT)$(call generic_msg,\
		\e[33;1mLib directory \e[0;32mcreated !,\
		mkdir -p $@)

$(I_SUBUILD_DIR): $(I_BUILD_L_DIR)
	$(MAKE) I_BUILD_DIR=$@ TARGETDIR=$(I_BUILD_L_DIR)

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
