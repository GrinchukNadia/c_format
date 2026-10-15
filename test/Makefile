NAME = printf.a

LIB_NAME = printf.a

LIB = ../src/$(LIB_NAME)

CFLAGS = -Wall -Wextra -Werror

FILES = test_printf.c

TESTS = $(FILES:.c=)

%: %.c test.c ../src/$(NAME)
	cc $(CFLAGS) -g -I ../src $<  test.c ../src/$(NAME) -o $@

../src/$(NAME):
	$(MAKE) -C ../src
	
asan:
	$(MAKE) -C ../src fclean
	$(MAKE) -C ../src all CFLAGS="$(CFLAGS) -g -fsanitize=address"
	$(MAKE) clean
	$(MAKE) $(TESTS) CFLAGS="$(CFLAGS) -g -fsanitize=address"
	for t in $(TESTS); do ./$$t > /dev/null; done

	
help:
	@echo "Available targets:"
	@echo " clean fclean"
	@echo " t"
	@echo " test"
	@echo " valgrin"
	@echo " asan"

test: 
	$(MAKE) -C ../src re
	$(MAKE) clean
	$(MAKE) $(TESTS)
	for t in $(TESTS); do ./$$t; done

clean:
	rm -f $(TESTS)

fclean:
	$(MAKE) -C ../src fclean
	$(MAKE) clean

valgrind:
	$(MAKE) -C ../src re
	$(MAKE) $(TESTS)
	for t in $(TESTS); do valgrind --leak-check=full --show-leak-kinds=all ./$$t > /dev/null; done
	
.PHONY: t test clean fclean valgrind asan help
