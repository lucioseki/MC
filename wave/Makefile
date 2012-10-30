#
# Lucio Mitsuru Seki	379883
# 

CC = gcc
ARGS = 
OUTPUT = main
OBJS = wave_header.o
main: main.c wave_header.o
	$(CC) main.c $(ARGS) $(OBJS) -o $(OUTPUT)

wave_header.o: wave_header.h wave_header.c
	$(CC) wave_header.c -c

clean:
	rm main *~ *.o
