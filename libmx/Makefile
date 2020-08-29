NAME	=	libmx.a

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic)

SRCD	=	src
INCD	=	inc
OBJD	=	obj

INC		=	libmx.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC	= 	mx_binary_search.c \
	./mx_print_unicode.c \
	./mx_quicksort.c \
	./mx_bubble_sort.c \
	./mx_bzero.c \
	./mx_count_substr.c \
	./mx_count_words.c \
	./mx_del_extra_spaces.c \
	./mx_del_strarr.c \
	./mx_foreach.c \
	./mx_get_char_index.c \
	./mx_get_substr_index.c \
	./mx_itoa.c \
	./mx_memccpy.c \
	./mx_memcpy.c \
	./mx_memset.c \
	./mx_hex_to_nbr.c \
	./mx_pow.c \
	./mx_print_strarr.c \
	./mx_printchar.c \
	./mx_printint.c \
	./mx_printstr.c \
	./mx_sqrt.c \
	./mx_str_reverse.c \
	./mx_strcat.c \
	./mx_strcmp.c \
	./mx_strcpy.c \
	./mx_strdel.c \
	./mx_strdup.c \
	./mx_strlen.c \
	./mx_strncpy.c \
	./mx_strncmp.c \
	./mx_strndup.c \
	./mx_strnew.c \
	./mx_strsplit.c \
	./mx_strstr.c \
	./mx_strtrim.c \
	./mx_strjoin.c \
	./mx_swap_char.c \
	./mx_strchr.c \
	./mx_isspace.c \
	./mx_count_ch.c \
	./mx_create_node.c \
	./mx_file_to_str.c \
	./mx_list_size.c \
	./mx_memchr.c \
	./mx_memcmp.c \
	./mx_memmem.c \
	./mx_memmove.c \
	./mx_memrchr.c \
	./mx_memset.c \
	./mx_nbr_to_hex.c \
	./mx_pop_back.c \
	./mx_pop_front.c \
	./mx_push_back.c \
	./mx_push_front.c \
	./mx_realloc.c \
	./mx_replace_substr.c \
	./mx_sort_list.c \
	./mx_swap_data.c \
	./mx_isdigit.c \
	./mx_isletter.c \
	./mx_isnumber.c \
	./mx_printerr.c \
	./mx_printerror.c \
	./mx_isupper.c \
	./mx_isalpha.c \
	./mx_memalloc.c \
	./mx_tolower.c \
	./mx_toupper.c \
	./mx_read_line.c

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install
	
install: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

clean:
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t   \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@rm -rf $(NAME)
	@printf "$(NAME)\t   \033[31;1muninstalled\033[0m\n"

reinstall: uninstall install
