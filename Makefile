# Makefile para linux

CC=gcc
CFLAGS=-Wall -Wextra -g -O2
LDFLAGS=-lm

SRC_DIR=src
ALG_DIR=algoritmos
INC_DIR=includes
BUILD_DIR=build
TARGET=analisador

SRCS := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(ALG_DIR)/*.c)
OBJS := $(patsubst %.c,$(BUILD_DIR)/%.0,$(notdir $(SRCS)))

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CC) $(CFLAGS) -I$(INC_DIR) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(BUILD_DIR)
		$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: $(ALG_DIR)/%.c
		@mkdir -p $(BUILD_DIR)
		$(CC) $(CFLAGS) -I$(INC_DIR) -c $, -o $@

clean:
		rm -rf $(BUILD_DIR) $(TARGET) resultados/*.csv

run: all
		./$(TARGET)
