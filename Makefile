# ===================================================================
# Makefile Flexível para Múltiplos Problemas (LeetCode)
# ===================================================================

# Define o compilador que será usado. 'gcc' é o padrão para C.
CC = gcc

# Define as flags (opções) do compilador.
# -g:   Adiciona informações de depuração (essencial para usar o GDB).
# -O0:  Desativa todas as otimizações. Facilita a depuração, pois o código
#       executado corresponde exatamente ao código que você escreveu.
# -Wall: Habilita "todos" os avisos (Warnings). Ajuda a encontrar possíveis erros.
# -I.:  Informa ao compilador para procurar arquivos de cabeçalho (.h) no diretório atual.
CFLAGS = -g -O0 -Wall -I.

# --- Nenhuma personalização é necessária abaixo desta linha ---

# Regra "Mágica" para compilar qualquer arquivo .c
# -----------------------------------------------------
# Esta é a parte mais importante. Ela ensina ao 'make' como criar um
# executável a partir de um arquivo .c de mesmo nome.
# Exemplo: Se você pedir "make 538c", ele usará esta regra para
#          compilar o arquivo "538c.c" e gerar o executável "538c".
#
# $@ representa o nome do alvo (ex: "538c").
# $< representa o primeiro pré-requisito (ex: "538c.c").
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Alvo para Limpeza do Projeto
# -----------------------------
# Um alvo "PHONY" é um alvo que não representa um arquivo real.
# Executar "make clean" irá apagar os arquivos gerados pela compilação.
.PHONY: clean
clean:
	@echo "Limpando arquivos gerados..."
	rm -f *.o
	rm -f *.exe
	@echo "Limpeza concluída."