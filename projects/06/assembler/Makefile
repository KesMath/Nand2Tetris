util:
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 utility/util.cc -o util

parse:
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o util.o -c utility/util.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o parser.o -c parser/parser.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o parse parser.o util.o

code:
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 binary/codegen.cc -o codegen

table:
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o parser.o -c parser/parser.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o symboltable.o -c symbol_table/symboltable.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o symboltable parser.o symboltable.o


asm: 
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o util.o -c utility/util.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o parser.o -c parser/parser.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o codegen.o -c binary/codegen.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o symboltable.o -c symbol_table/symboltable.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o assembler.o -c driver/assembler.cc
	c++ -std=gnu++2a -Wall -Werror -Wshadow -g -O3 -o assembler assembler.o util.o codegen.o parser.o symboltable.o

run-add:
	./assembler ../add/Add.asm

run-max:
	./assembler ../max/Max.asm
	./assembler ../max/MaxL.asm

run-pong:
	./assembler ../pong/Pong.asm
	./assembler ../pong/PongL.asm

run-rect:
	./assembler ../rect/Rect.asm
	./assembler ../rect/RectL.asm

run-all:
	make run-add
	make run-max
	make run-pong
	make run-rect

clean-asm:
	rm assembler.o
	rm util.o
	rm parser.o
	rm codegen.o
	rm symboltable.o

clean-parse:
	rm parser.o
	rm util.o
	rm parse

clean-table:
	rm parser.o
	rm symboltable.o