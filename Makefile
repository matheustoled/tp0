CC = gcc
CFLAGS = -Wall -Wextra -std=c11
# -Wall: mostra todos os avisos comuns.
# -Wextra: mostra avisos adicionais.
# -std=c11: força o padrão C11.
SRC = src/main.c src/figuras.c src/quadro.c
OUT = output

all: $(OUT)

$(OUT):
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
