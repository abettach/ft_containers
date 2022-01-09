NAME = containers
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = clang++
RM = rm -rf

SRCS = mains/main.cpp \
		mains/main_vec.cpp \
		mains/main_map.cpp \
		mains/main_stack.cpp

OBJS = $(SRCS:.cpp=.o)

%.o:%.cpp *.hpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: clean all