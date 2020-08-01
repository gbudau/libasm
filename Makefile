NAME = libasm.a
AS = nasm
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = -rcs
ASFLAGS = -f elf64
CC = gcc

AS_OBJ = ft__strlen.o
C_SRC = main.c

all: $(NAME)

$(NAME): $(AS_OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(AS_OBJ)

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	$(RM) $(AS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: $(NAME) $(C_SRC)
	$(CC) $(C_SRC) -L. -lasm -o $@ $(NAME)
	./$@
	$(RM) $@
