// #include <unistd.h>
// #include "../libft/ft_printf/ft_printf.h"

// void ft_gets(char *buffer, int max_len, int *stream)
// {
//     int ret = read(STDIN_FILENO, buffer, max_len - 1);

//     if (ret > 0)
//     {
//         buffer[ret] = '\0';
//         ft_printf("IN: %s\n", buffer);
//     }
// }

// int main(int ac, char **av)
// {

//     ft_printf("ac : %d\n", ac);

//     // printf("%d", ft_atoi("45"));

//     // while (*++av)
//     // {
//     //     ft_printf("av : %s\n", *av);
//     // }

//     // // --- get stdin
//     // char buffer[100];

//     // ft_gets(buffer, sizeof(buffer), stdin);

//     return (0);
// }
#include "../libft/ft_printf/ft_printf.h"

int main() {
    ft_printf("Hello World");
    return (0);
}