cmake_minimum_required(VERSION 3.14)
project(it_is_my_printf C)

file(GLOB LIBFT
        "*.c"
        "./libft/*.c"
        "./libft/libft.h")

set(CMAKE_C_STANDARD 99)
#add_definitions(-Wall -Werror -Wextra)
add_executable(it_is_my_printf ${LIBFT} output_u.c output_i_d.c output_p.c output_persent.c)