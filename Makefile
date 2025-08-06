# Makefile para compilar um programa de teste com seu código LeetCode

# --- PERSONALIZE AQUI ---
# O nome do programa de teste que vamos gerar
TARGET = programa_teste

# Os arquivos fonte que formam o programa: o seu teste + o seu código LeetCode
SRCS = teste_739.c 739.c
# ------------------------

CC = gcc
CFLAGS = -g -O0 -Wall -mconsole
OBJS = $(SRCS:.c=.o)

# Regra principal: para criar o programa, precisa dos arquivos objeto
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar cada .c em um .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Alvo para limpeza
.PHONY: clean
clean:
	rm -f *.o *.exe $(TARGET)