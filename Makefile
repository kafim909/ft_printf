DIRSRC		= ./srcs/

DIRINC		= ./includes/

DIROBJ		= ./objs/

DIRLIB		= ./libft/

SRC			= convert_char.c convert_HEX.c convert_int.c convert_modulo.c convert_ptr.c convert_str.c convert_unsigned.c \
				data_flag_convert.c ft_itoa_base.c ft_printf.c parse_flags.c prec_width.c type_convert.c \
				init.c parse_type.c unsigned_itoa.c utils.c width_minus_noprec.c width_minus_prec_str.c width_minus_prec.c \
				width_noflags_noprec.c width_noflags_prec.c width_prec_str.c width_zero_noprec.c width_zero_prec.c \
				prec_width_str.c

SRCS		= $(addprefix ${DIRSRC}, ${SRC})

HEAD		= ./includes/ 

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

NAMELFT		= libft.a

CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} -I${DIRLIB} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd ${DIRLIB} && ${MAKE} && cp -v ${NAMELFT} ../${NAME}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

main:		$(NAME)
			${CC} -I ${DIRINC} -I ${DIRLIB} ${NAME} main.c

all:		$(NAME)

clean:
			${RM} ${OBJS}
			cd ${DIRLIB} && ${MAKE} clean

fclean:		clean
			${RM} $(NAME) a.out
			cd ${DIRLIB} && ${MAKE} fclean

re:			fclean all

.PHONY:		all clean fclean re
