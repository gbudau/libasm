NAME = libasm.a
AR = ar
ARFLAGS = -rcs
AS = nasm
ASFLAGS = -f elf64 -g -F dwarf
CFLAGS = -Wall -Werror -Wextra -g
CC = gcc

AS_OBJ = ft_strlen.o ft_strcmp.o ft_strcpy.o \
		 ft_strdup.o ft_write.o ft_read.o
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
