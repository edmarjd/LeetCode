# ===================================================================
# Makefile Definitivo para Projetos LeetCode
# Autor: Seu Assistente Gemini :)
# Data: 06/08/2025
# ===================================================================

# Define o compilador
CC = gcc

# Define as flags de compilação. -g é essencial para o GDB.
CFLAGS = -g -O0 -Wall -I.

# --- Nenhuma personalização é necessária abaixo desta linha ---

# Regra de Padrão "Mágica"
# Ensina o 'make' a criar um executável (ex: '538c') a partir
# de um arquivo fonte (ex: '538c.c').
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Alvo para depurar um arquivo específico com GDB
# Como usar: mingw32-make gdb FILE=nome_do_arquivo_sem_c
# Exemplo:  mingw32-make gdb FILE=538c
gdb:
	@echo "--- Garantindo que o arquivo '$(FILE)' esta compilado... ---"
	@$(MAKE) $(FILE)
	@echo "--- Iniciando GDB para o arquivo '$(FILE)'... ---"
	@gdb ./$(FILE)

# Alvo para Limpeza do Projeto
.PHONY: clean gdb
clean:
	@echo "Limpando arquivos gerados..."
	rm -f *.o *.exe
	@echo "Limpeza concluída."