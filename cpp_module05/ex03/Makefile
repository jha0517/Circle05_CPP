SRCS			= main.cpp Bureaucrat.cpp printColor.cpp AForm.cpp \
					ShrubberyCreationForm.cpp \
					RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp \
					Intern.cpp
OBJS			= $(SRCS:.cpp=.o)
DEPS			= $(SRCS:.cpp=.d)

CXX				= c++
RM				= rm -f
CXXFLAGS		= -MMD -Wall -Wextra -Werror -std=c++98

NAME			= bureaucrat

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(DEPS)

fclean:			clean
				$(RM) $(NAME)

eval:			$(NAME)
				make clean
				reset
				valgrind ./$(NAME)


re:				fclean $(NAME)

.PHONY:			all clean fclean re test eval

-include ${DEPS}