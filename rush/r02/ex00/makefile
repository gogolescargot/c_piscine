FUNCTIONS = ft_check_dict1 ft_check_dict2 ft_atoa ft_init_arrays ft_read_file ft_trim1 ft_trim2 main ft_number_parsing ft_number_transformation ft_itoa ft_print
SOURCES = $(addsuffix .c,$(addprefix srcs/,$(FUNCTIONS)))

COMP = gcc -Wall -Wextra -Werror

all:
	$(COMP) $(SOURCES)

fclean:
	rm -rf a.out