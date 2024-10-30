/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:55:20 by mdahani           #+#    #+#             */
/*   Updated: 2024/10/30 15:50:58 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_fix(int n, char *result, size_t i)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			result[0] = '-';
			result[1] = '2';
			n = 147483648;
		}
		else
		{
			result[0] = '-';
			n = -n;
		}
	}
	while (n > 0)
	{
		result[i--] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*result;

	i = count_len(n);
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[i] = '\0';
	if (n == 0)
		result[0] = '0';
	else
		ft_fix(n, result, i - 1);
	return (result);
}

/*
int main() {
    printf("%s\n", ft_itoa(123));
    return 0;
}
*/
