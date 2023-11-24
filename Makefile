SRC_DIR=src
INC_DIR=inc
LIB_DIR=lib
BIN_DIR=bin

SRC_FILES=	$(SRC_DIR)/main.c \
			$(SRC_DIR)/core/*.c \
			$(SRC_DIR)/graphics/*.c

WIN_FLAGS=	-I$(INC_DIR) -L$(LIB_DIR) -o $(BIN_DIR)/prg.exe \
			-lglfw3 -lopengl32 -lgdi32

LINUX_FLAGS=-I$(INC_DIR) -o $(BIN_DIR)/prg \
			-lglfw -lGL -lX11 -lpthread -ldl -lm

compile_win:
	gcc $(SRC_FILES) $(WIN_FLAGS)

compile_linux:
	gcc $(SRC_FILES) $(LINUX_FLAGS)