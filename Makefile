# ===================================================================
# Makefile Definitivo e Automatizado para Múltiplos Testes
# ===================================================================
# Como usar:
# 1. Para compilar e depurar 'XYZ.c', crie um arquivo 'teste_XYZ.c' com uma main().
# 2. Compile e execute o GDB com um único comando:
#    mingw32-make debug FILE=XYZ
# ===================================================================

# Configurações Gerais
CC = gcc
CFLAGS = -g -O0 -Wall -mconsole

# --- Nenhuma personalização é necessária abaixo desta linha ---

# Alvo principal para depuração. Este é o comando que você vai usar!
# Ele espera que você passe o nome do arquivo base. Ex: FILE=739
debug:
	@# Verifica se a variável FILE foi passada
	@if [ -z "$(FILE)" ]; then \
		echo "ERRO: Especifique o arquivo a ser depurado. Exemplo: mingw32-make debug FILE=739"; \
		exit 1; \
	fi
	@echo "--- Compilando o programa de teste para $(FILE).c ---"
	$(CC) $(CFLAGS) -o $(FILE)_teste teste_$(FILE).c
	@echo "--- Compilação concluída. Iniciando GDB... ---"
	gdb ./$(FILE)_teste

# Alvo para Limpeza do Projeto
# Apaga todos os executáveis de teste e arquivos objeto
.PHONY: clean debug
clean:
	@echo "Limpando arquivos gerados..."
	rm -f *.o *_teste.exe *_teste
	@echo "Limpeza concluída."