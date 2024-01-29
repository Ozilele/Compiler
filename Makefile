main: parser.y lexer.l
		bison -d -o parser.cpp parser.y
		flex -o lexer.cpp lexer.l
		g++ -o kompilator -std=c++17 -O3 main.cpp parser.cpp lexer.cpp compiler.cpp assembler_generator.cpp conditioner.cpp

clean:
	rm -f parser.cpp parser.hpp lexer.cpp kompilator