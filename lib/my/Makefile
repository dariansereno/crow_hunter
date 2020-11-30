##
## EPITECH PROJECT, 2020
## Day10
## File description:
## Makefile
##

CC			= gcc
CFLAGS		=	-W -Wall -Wextra -Wno-incompatible-pointer-types \
				-Wno-unused-parameter -Wno-varargs -Wno-unused-variable \
				-Wno-unused-value -Wno-int-conversion

SRC			= $(wildcard *.c)
OBJ			= $(SRC:.c=.o)

LIBNAME		= my
TARGET		= lib$(LIBNAME).a

all			: $(TARGET)

$(TARGET)	: $(OBJ)
			$(AR) rsc $@ $^
			cp $(TARGET) ../../$(TARGET)
			mkdir -p ../../include

lib			:
			cp $(LIBNAME).h ../../include/$(LIBNAME).h


clean		:
			$(RM) $(OBJ)
			$(RM) $(TARGET)

fclean		:    clean
			$(RM) ../../$(TARGET)

re			:    fclean all
