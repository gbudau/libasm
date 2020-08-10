NAME = libasm.a
AR = ar
ARFLAGS = -rcs
AS = nasm
ASFLAGS = -f elf64
CFLAGS = -Wall -Werror -Wextra
CC = gcc

AS_OBJ = ft__strlen.o ft__strcmp.o
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
	$(CC) $(CFLAGS) $(C_SRC) -L. -lasm -o $@ $(NAME)
	./$@
	$(RM) $@
