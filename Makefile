##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## make
##

SRC	=	$(shell cat make.txt | tr '\n' ' ')	\

TEST_SRC	=	$(shell cat tests.txt | tr '\n' ' ')	\

CC	=	g++ -std=c++20

BUILDDIR =	build

TESTDIR	=	tests

OBJ = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o:	%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

EXEC_NAME	=	bootstrap_plazza

TEST_NAME	=	unit_tests

DEBUG	=	-g3

CPPFLAGS	+=	-I ./includes

CFLAGS	+=	-W -Wextra -Wall -fext-numeric-literals

LDFLAGS	=	-lpthread

TESTFLAGS	=	--coverage -lcriterion

all:	$(EXEC_NAME)

$(EXEC_NAME):	$(OBJ)
	$(CC) -o $(EXEC_NAME) $(OBJ) $(LDFLAGS)

debug:	$(OBJ)
	$(CC) -o $(EXEC_NAME) $(OBJ) $(LDFLAGS) $(DEBUG)
	valgrind --tool=helgrind ./$(EXEC_NAME)

tests_run:
	$(CC) -o $(TEST_NAME) $(TEST_SRC) $(TESTFLAGS) $(CPPFLAGS) $(LDFLAGS)
	./$(TEST_NAME)
	gcovr --exclude tests/

clean:
	$(RM) $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno

fclean: clean
	$(RM) $(EXEC_NAME)
	$(RM) $(TEST_NAME)
	rm -rf $(BUILDDIR)

re:	fclean all

.PHONY: all debug fclean clean re
