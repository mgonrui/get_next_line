CFILES =get_next_line.c

NAME = get_next_line.a
CC = gcc 
CFLAGS = -Wall -Werror -Wextra - D BUFFER_SIZE=42
OBJECTS = $(CFILES:.c=.o) 

# create library
$(NAME) : $(OBJECTS)
	@ ar crs $(NAME) $(OBJECTS) 

# create objects
$(OBJECTS) : $(CFILES)
	@ $(CC) $(CFLAGS) -c -o $@ $< 

# build library
all: $(NAME)

# clean objects
clean:
	@ rm -rf $(OBJECTS)

# clean objects and library
fclean: clean
	@ rm -f $(NAME)

# clean objects and library and build all 
re: fclean all 

.PHONY: all clean fclean re