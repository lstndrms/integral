
GCC = gcc -m32
NASM = nasm -f elf32

.PHONY: all clean

all: prjct

prjct: main.o f1.o f2.o f3.o root.o integral.o test.o
	$(GCC) $^ -o prjct -lm

main.o: main.c
	$(GCC) $^ -c

root.o: root.c
	$(GCC) $^ -c

integral.o: integral.c
	$(GCC) $^ -c

test.o: test.c
	$(GCC) $^ -c

f1.o: f1.asm
	$(NASM) $^

f2.o: f2.asm
	$(NASM) $^

f3.o: f3.asm
	$(NASM) $^


clean: 
	rm -rf *.o
