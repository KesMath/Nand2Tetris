util:
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 utility/util.cc -o util

parse:
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 parser/parser.cc -o parse

asm:
	c++ -std=gnu++2a -Wall -Wshadow -g -O3 -o util.o -c utility/util.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o assembler.o -c driver/assembler.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o assembler assembler.o util.o

run:
	./assembler ../add/Add_WhiteSpace.asm

clean:
	rm assembler.o
	rm util.o