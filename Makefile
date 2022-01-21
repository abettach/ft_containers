NAME = ft_containers
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
CC  = clang++

SRCS = mains/main.cpp \
		mains/main_vec.cpp \
		mains/main_map.cpp \
		mains/main_stack.cpp \
		mains/main_original.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[1;33mMake \033[1;32m\t    [OK]"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "\033[1;32m| \033[1;33m" $(NAME) : Created ! "\033[1;32m|"
	@echo "\033[1;32m~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "\033[1;33mMake clean \033[1;32m [OK]"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;33mMake fclean \033[1;32m[OK]"

re: fclean $(NAME)