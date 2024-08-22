NAME = convert
CXX = c++
CXXFLAGS = -std=c++98 -Wshadow -Wall -Werror -Wextra -g
SRC = main.cpp
OBJ = $(SRC:%.cpp=%.o)
	
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all