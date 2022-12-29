util:
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 utility/util.cc -o util

parse:
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o util.o -c utility/util.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o parser.o -c parser/parser.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o parse parser.o util.o

code:
	c++ -std=gnu++2a -Wall -Wshadow -g -O3 binary/codegen.cc -o codegen

asm:
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o util.o -c utility/util.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o assembler.o -c driver/assembler.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o assembler assembler.o util.o

run:
	./assembler ../add/Add_WhiteSpace.asm

clean-asm:
	rm assembler.o
	rm util.o

clean-parse:
	rm parser.o
	rm util.o
	rm parse