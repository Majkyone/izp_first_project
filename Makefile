CC=gcc

all: keyfilter test_1_keyfilter test_2

keyfilter: keyfilter.c 
    $(CC) -std=c11 -Wall -Wextra -Werror -o keyfilter keyfilter.c

test_1_keyfilter: test_1_keyfilter.c
	$(CC) -std=c11 -Wall -Wextra -Werror -o test_1_keyfilter test_1_keyfilter.c

test_2: test_2.c 
    $(CC) -std=c11 -Wall -Wextra -Werror -o test_2 test_2.c