NAME = serialize
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra -g
SRC = Serializer.cpp main.cpp
OBJ = $(SRC:%.cpp=%.o)
DEPS = Serializer.hpp
	
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all