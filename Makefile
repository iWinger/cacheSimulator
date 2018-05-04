cachesim: cachesim.c
	gcc -g -lm -Wall -Werror -fsanitize=address -o cachesim cachesim.c
clean:
	rm -f cachesim
