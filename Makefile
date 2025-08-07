# ===================================================================
# Makefile Final - Otimizado para VS Code e Linha de Comando
# ===================================================================

CC = gcc
CFLAGS = -g -O0 -Wall -mconsole

# Alvo para compilar um programa de teste. Só compila, não executa.
# Usado pelo VS Code antes de depurar.
# Ex: mingw32-make build FILE=739
build:
	@if [ -z "$(FILE)" ]; then echo "ERRO: Especifique o arquivo. Ex: make build FILE=739"; exit 1; fi
	@echo "--- Compilando 'teste_$(FILE).c' + '$(FILE).c' ---"
	$(CC) $(CFLAGS) -o $(FILE)_teste.exe teste_$(FILE).c

# Alvo para iniciar o GDB pela linha de comando (opcional)
# Ex: mingw32-make gdb FILE=739
gdb: build
	@echo "--- Iniciando GDB para o arquivo '$(FILE)_teste.exe'... ---"
	@gdb ./$(FILE)_teste.exe

# Alvo de limpeza
.PHONY: clean build gdb
clean:
	@echo "Limpando arquivos gerados..."
	rm -f *.o *_teste.exe
	@echo "Limpeza concluída."