NAME	=	pathfinder

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic)

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/inc

INC		=	pathfinder.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC	= 	main.c\
		mx_atoi.c\
		mx_add_islands.c\
		mx_add_link.c\
		mx_add_path.c\
		mx_check_first_line.c\
		mx_check_is_shortest.c\
		mx_check_isl_count.c\
		mx_check_line.c\
		mx_create_island.c\
		mx_create_link.c\
		mx_create_main.c\
		mx_create_path.c\
		mx_find_all_path.c\
		mx_find_path.c\
		mx_get_island.c\
		mx_isvisited.c\
		mx_parse_file.c\
		mx_parse_line.c\
		mx_pop_back_link.c\
		mx_prepare_for_algorithm.c\
		mx_printerr_pf.c\
		mx_push_back_link.c\
		mx_set_link.c\
		mx_setdistances.c\
		mx_print_all_paths.c
SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install
	
install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@clang $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)
clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)

reinstall: uninstall install
