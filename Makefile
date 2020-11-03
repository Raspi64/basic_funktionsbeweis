OBJS=cbmbasic.o runtime.o plugin.o console.o
CFLAGS=-Wall -O3

all: cbmbasic

cbmbasic: $(OBJS)
	$(CC) -o cbmbasic $(OBJS)

func: func.o cbmbasic.o
	gcc -o func fun.o cbmbasic.o


clean:
	rm -f $(OBJS) cbmbasic




