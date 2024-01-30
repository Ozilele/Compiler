Kompilator 2023/2024
Autor: Bartłomiej Puchała
Nr indeksu: 268501
Pliki:
main.cpp - Uruchamia cały program kompilatora, wywołuje funkcję z parsera, która rozpoczyna parsing
lexer.l - Analiza leksykalna tokenów
parser.y - Plik parsera
conditioner.cpp - Funkcje implementujące =,!=,>,<,>=,<=
assembler_generator.cpp - Funkcje implementujące +,-,*,/,%
compiler.cpp - Funkcje pomocnicze dla parsera i operacji arytmetycznych/porównania, wstawiające liczbę do rejestru, sprawdzające wartość rejestru, sprawdzające deklarację zmiennych, inicjalizację itp.
 
