# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 15:50:27 by qloubier          #+#    #+#              #
#    Updated: 2016/03/19 22:42:02 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra
NAME=libft.a
INCDIR=./
FANCY_OUT=on

MEMOBJ=mem/ft_bzero.o\
	mem/ft_memalloc.o\
	mem/ft_memccpy.o\
	mem/ft_memchr.o\
	mem/ft_memcmp.o\
	mem/ft_memcpy.o\
	mem/ft_memdel.o\
	mem/ft_memdup.o\
	mem/ft_memmove.o\
	mem/ft_memset.o

STROBJ=str/ft_isalnum.o\
	str/ft_isalpha.o\
	str/ft_isascii.o\
	str/ft_isdigit.o\
	str/ft_isprint.o\
	str/ft_strcat.o\
	str/ft_strchr.o\
	str/ft_strchrnot.o\
	str/ft_strchrany.o\
	str/ft_strclr.o\
	str/ft_strcmp.o\
	str/ft_strcpy.o\
	str/ft_strdel.o\
	str/ft_strdup.o\
	str/ft_strequ.o\
	str/ft_stridx.o\
	str/ft_striter.o\
	str/ft_striteri.o\
	str/ft_strjoin.o\
	str/ft_strlcat.o\
	str/ft_strlen.o\
	str/ft_strmap.o\
	str/ft_strmapi.o\
	str/ft_strncat.o\
	str/ft_strncmp.o\
	str/ft_strncpy.o\
	str/ft_strnequ.o\
	str/ft_strnew.o\
	str/ft_strnstr.o\
	str/ft_strrchr.o\
	str/ft_strsplit.o\
	str/ft_strstr.o\
	str/ft_strsub.o\
	str/ft_strtrim.o\
	str/ft_tolower.o\
	str/ft_toupper.o\
	str/ft_ptabdel.o\
	str/ft_wrdcount.o

LSTOBJ=lst/ft_lstadd.o\
	lst/ft_lstdel.o\
	lst/ft_lstdelone.o\
	lst/ft_lstiter.o\
	lst/ft_lstlen.o\
	lst/ft_lstmap.o\
	lst/ft_lstnew.o\
	lst/ft_lstlast.o\
	lst/ft_lstpush.o\
	lst/ft_lsttotab.o\
	lst/ft_lstpushback.o

MIXOBJ=ft_atoi.o\
	ft_itoa.o\
	ft_get_line.o\
	ft_putchar.o\
	ft_putchar_fd.o\
	ft_putendl.o\
	ft_putendl_fd.o\
	ft_putnbr.o\
	ft_putnbr_fd.o\
	ft_putstr.o\
	ft_putstr_fd.o

OBJ=
ALLOBJ=$(MEMOBJ) $(LSTOBJ) $(STROBJ) $(MIXOBJ)

.PHONY: all clean fclean re\
	mem lst str mix\
	fancy_msg fancy_mem fancy_lst fancy_str fancy_mix\

all: fancy_msg  mem str lst mix
	@make --no-print-directory $(NAME)

mem: fancy_mem $(MEMOBJ)
	$(eval $OBJ += $(MEMOBJ))
ifeq ($(FANCY_OUT),on)
	@printf "\e[34m]\e[32m>>\e(B\e[m\n"
endif

lst: fancy_lst $(LSTOBJ)
	$(eval $OBJ += $(LSTOBJ))
ifeq ($(FANCY_OUT),on)
	@printf "\e[34m]\e[32m>>\e(B\e[m\n"
endif

str: fancy_str $(STROBJ)
	$(eval $OBJ += $(STROBJ))
ifeq ($(FANCY_OUT),on)
	@printf "\e[34m]\e[32m>>\e(B\e[m\n"
endif

mix: fancy_mix $(MIXOBJ)
	$(eval $OBJ += $(MIXOBJ))
ifeq ($(FANCY_OUT),on)
	@printf "\e[34m]\e[32m>>\e(B\e[m\n"
endif

ifeq ($(FANCY_OUT),on)

fancy_msg:
	@printf "\e[1m\e[32m<<\e[34m[\e[33m__{\e[36m Libft \e[33m}__\e[34m]\e[32m>>\e(B\e[m\n"

$(NAME): $(ALLOBJ)
	@printf "\e[1m\e[32m<<\e[34m[\e[33m__{\e[36m Create $(NAME) \e[33m}__\e[34m]\e[32m>>\e(B\e[m\n"
	@ar -rcs $(NAME) $(ALLOBJ)
	@printf "\e[1m\e[32m<<\e[34m[\e[33m__{\e[36m $(NAME) succefully created \e[33m}__\e[34m]\e[32m>>\e(B\e[m\n"

fancy_mem:
	@printf "\e[1m\e[32m<<\e[34m[\e[33m__{\e[36m Memory Function \e[33m}__\e[34m]\e[32m>>\n\e[1m\e[32m<<\e[34m[\e[33m"
	@printf "¤¤¤¤¤¤¤¤¤¤\e[34m]\e[32m>>\e[13D"

fancy_lst:
	@printf "\e[1m\e[32m<<\e[34m[\e[33m__{\e[36m List Function \e[33m}__\e[34m]\e[32m>>\n\e[1m\e[32m<<\e[34m[\e[33m"
	@printf "¤¤¤¤¤¤¤¤¤¤¤\e[34m]\e[32m>>\e[14D"

fancy_str:
	@printf "\e[1m\e[32m<<\e[34m[\e[33m__{\e[36m String Function \e[33m}__\e[34m]\e[32m>>\n\e[1m\e[32m<<\e[34m[\e[33m"
	@printf "¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\e[34m]\e[32m>>\e[41D"

fancy_mix:
	@printf "\e[1m\e[32m<<\e[34m[\e[33m__{\e[36m Other Function \e[33m}__\e[34m]\e[32m>>\n\e[1m\e[32m<<\e[34m[\e[33m"
	@printf "¤¤¤¤¤¤¤¤¤¤¤\e[34m]\e[32m>>\e[14D"

%.o: %.c
	@printf "¤"
	@$(CC) -o $@ -c $< $(CFLAGS) -I$(INCDIR)
	@printf "\e[1D#"

else

fancy_msg:

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCDIR)

fancy_mem:

fancy_lst:

fancy_str:

fancy_mix:

endif

clean: fancy_msg
	@printf "\e[1m\e[32m<<\e[34m[\e[31m__{\e[36m Clean object files \e[31m}__\e[34m]\e[32m>>\e(B\e[m\n"
	@rm -rf $(ALLOBJ)

fclean: clean
	@printf "\e[1m\e[32m<<\e[34m[\e[31m__{\e[36m Clean $(NAME) file \e[31m}__\e[34m]\e[32m>>\e(B\e[m\n"
	@rm -rf $(NAME)

re: fclean all
