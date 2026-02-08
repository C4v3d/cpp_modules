CXX = c++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra

BUILD_PATH = build

SRC = main.cpp\
      Base.cpp \
      A.cpp \
      B.cpp \
      C.cpp

OBJ = $(SRC:%.cpp=$(BUILD_PATH)/%.o)

NAME = downcast

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(BUILD_PATH)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(BUILD_PATH)/*.o

fclean: clean
	@echo "Fully cleaning project..."
	@rm -f $(NAME)
	@rm -rf $(BUILD_PATH)

re: fclean all

.PHONY: all clean fclean re
