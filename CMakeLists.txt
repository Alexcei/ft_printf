cmake_minimum_required(VERSION 3.14)
project(it_is_my_printf C)

file(GLOB LIBFT
        "*.c"
        "./libft/*.c"
        "./libft/libft.h")

set(CMAKE_C_STANDARD 99)

add_executable(it_is_my_printf ${LIBFT} ft_printf.c output_c_s.c)