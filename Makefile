# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 15:50:27 by qloubier          #+#    #+#              #
#    Updated: 2016/04/02 14:52:15 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra
NAME=libft.a
INCDIR=./
FANCY_OUT=on

MEMDIR=mem/
STRDIR=str/
LSTDIR=lst/
FORMATDIR=format/

MEMOBJ=${MEMDIR}ft_bzero.o\
	${MEMDIR}ft_memalloc.o\
	${MEMDIR}ft_memccpy.o\
	${MEMDIR}ft_memchr.o\
	${MEMDIR}ft_memcmp.o\
	${MEMDIR}ft_memcpy.o\
	${MEMDIR}ft_memdel.o\
	${MEMDIR}ft_memdup.o\
	${MEMDIR}ft_memmove.o\
	${MEMDIR}ft_memset.o

STROBJ=${STRDIR}ft_isalnum.o\
	${STRDIR}ft_isalpha.o\
	${STRDIR}ft_isascii.o\
	${STRDIR}ft_isdigit.o\
	${STRDIR}ft_isprint.o\
	${STRDIR}ft_strcat.o\
	${STRDIR}ft_strchr.o\
	${STRDIR}ft_strchrnot.o\
	${STRDIR}ft_strchrany.o\
	${STRDIR}ft_strclr.o\
	${STRDIR}ft_strcmp.o\
	${STRDIR}ft_strcpy.o\
	${STRDIR}ft_strdel.o\
	${STRDIR}ft_strdup.o\
	${STRDIR}ft_strequ.o\
	${STRDIR}ft_stridx.o\
	${STRDIR}ft_striter.o\
	${STRDIR}ft_striteri.o\
	${STRDIR}ft_strjoin.o\
	${STRDIR}ft_strlcat.o\
	${STRDIR}ft_strlen.o\
	${STRDIR}ft_strmap.o\
	${STRDIR}ft_strmapi.o\
	${STRDIR}ft_strncat.o\
	${STRDIR}ft_strncmp.o\
	${STRDIR}ft_strncpy.o\
	${STRDIR}ft_strnequ.o\
	${STRDIR}ft_strnew.o\
	${STRDIR}ft_strnstr.o\
	${STRDIR}ft_strrchr.o\
	${STRDIR}ft_strsplit.o\
	${STRDIR}ft_strstr.o\
	${STRDIR}ft_strsub.o\
	${STRDIR}ft_strtrim.o\
	${STRDIR}ft_tolower.o\
	${STRDIR}ft_toupper.o\
	${STRDIR}ft_ptabdel.o\
	${STRDIR}ft_wrdcount.o

LSTOBJ=${LSTDIR}ft_lstadd.o\
	${LSTDIR}ft_lstdel.o\
	${LSTDIR}ft_lstdelone.o\
	${LSTDIR}ft_lstiter.o\
	${LSTDIR}ft_lstlen.o\
	${LSTDIR}ft_lstmap.o\
	${LSTDIR}ft_lstnew.o\
	${LSTDIR}ft_lstlast.o\
	${LSTDIR}ft_lstpush.o\
	${LSTDIR}ft_lsttotab.o\
	${LSTDIR}ft_lstpushback.o

FORMATOBJ=${FORMATDIR}ft_printf.o

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
ALLOBJ=$(MEMOBJ) $(LSTOBJ) $(STROBJ) $(MIXOBJ) $(FORMATOBJ)

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
