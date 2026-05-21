NAME = aform

SRCS = main.cpp AForm.cpp Bureaucrat.cpp \
PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
ShrubberyCreationForm.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = 	c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) *shrubbery

re: fclean all

.PHONY: all clean fclean re