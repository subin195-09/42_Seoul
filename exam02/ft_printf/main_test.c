#include <stdio.h>


int ft_printf(char *format, ...);

int main(void)
{
	printf("10.0s |%10.0s\n", "Hello");
printf("10.s  |%10.s\n", "Hello");
printf("10s   |%10s\n", "Hello");
printf("10.4s |%10.4s\n", "HEllo");
printf("10.7s |%10.7s\n", "HEllo");
printf(".7s   |%.7s\n", "HEllo");
printf(".3s   |%.3s\n", "HEllo");
printf("\n\n");
ft_printf("10.0s |%10.0s\n", "Hello");
ft_printf("10.s  |%10.s\n", "Hello");
ft_printf("10s   |%10s\n", "Hello");
ft_printf("10.4s |%10.4s\n", "HEllo");
ft_printf("10.7s |%10.7s\n", "HEllo");
ft_printf(".7s   |%.7s\n", "HEllo");
ft_printf(".3s   |%.3s\n", "HEllo");

printf("===================\n");
printf("d    |%d\n", 1234);
printf("3d   |%3d\n", 1234);
printf("7d   |%7d\n", 1234);
printf(".d   |%.d\n", 1234);
printf(".3d  |%.3d\n", 1234);
printf(".6d  |%.6d\n", 1234);
printf(".6d  |%.6d\n", -1234);
printf("3.3d |%3.3d\n", 1234);
printf("3.3d |%3.3d\n", -1234);
printf("6.3d |%6.3d\n", 1234);
printf("6.3d |%6.3d\n", -1234);
printf("3.7d |%3.7d\n", 1234);
printf("3.7d |%3.7d\n", -1234);
printf("9.7d |%9.7d\n", 1234);
printf("9.7d |%9.7d\n", -1234);
printf("\n\n");
ft_printf("d    |%d\n", 1234);
ft_printf("3d   |%3d\n", 1234);
ft_printf("7d   |%7d\n", 1234);
ft_printf(".d   |%.d\n", 1234);
ft_printf(".3d  |%.3d\n", 1234);
ft_printf(".6d  |%.6d\n", 1234);
ft_printf(".6d  |%.6d\n", -1234);
ft_printf("3.3d |%3.3d\n", 1234);
ft_printf("3.3d |%3.3d\n", -1234);
ft_printf("6.3d |%6.3d\n", 1234);
ft_printf("6.3d |%6.3d\n", -1234);
ft_printf("3.7d |%3.7d\n", 1234);
ft_printf("3.7d |%3.7d\n", -1234);
ft_printf("9.7d |%9.7d\n", 1234);
ft_printf("9.7d |%9.7d\n", -1234);

}
