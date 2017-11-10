
#include "../includes/libft.h"

static	int		split(char c)
{
	if (c == '\n' || c == ' ' || c == '\t' 
		|| c == '\r' || c == '+' || c == '\f'
		|| c == '\v')
		return (1);
	return (0);
}

int				ft_atoi(const char *str1)
{
	unsigned char					*str;
	int						is_neg;
	unsigned long int		res;

	str = (unsigned char *)str1;
	res = 0;
	is_neg = 1;
	while (split(*str))
		str++;
	if (*str == '-'  && is_neg == 1)
	{
		is_neg = -1;
		str++;
	}
	while (*str <= '9' && *str >= '0' && *str)
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
		&& (*str - '0') > 7)) && is_neg == 1)
			return (-1);
	  	else if ((res > 922337203685477580 || (res == 922337203685477580
		&& (*str - '0') > 8)) && is_neg == -1)
			return (0);
		res = (*(str++) - '0') + res * 10;
	}
	return (is_neg * res);
}
