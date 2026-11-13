NAME = licenzio
SRC = main.c src/command.c src/utils.c src/license.c
CFLAGS = -Wall -Wextra -Werror
HEADERS = includes/licenzio.h includes/command.h includes/utils.h includes/license.h
TEMPLATE = $(wildcard templates/*.txt)
GENERATED = includes/templates.h

$(NAME): $(SRC) $(HEADERS) $(GENERATED)
	cc $(CFLAGS) $(SRC) -o $(NAME)

# for each template file transform into hex dump and set in $(GENERATED) file	
$(GENERATED): $(TEMPLATE)
	for template in $^; do \
	    xxd -i "$$template"; \
	done > $@