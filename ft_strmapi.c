/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:09:51 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/21 19:57:44 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Applies the function ’f’ to each character of the string ’s’,
// and passing its index as first argument
// to create a new string resulting from successive applications of ’f’

// === RETURN VALUE ===
// if (s == NULL || f == NULL) → Return NULL.

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buff;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	buff = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		buff[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

// char	ft_addindex(unsigned int i, char c)
// {
// 	return ((char)i + c);
// }

// int	main(void)
// {
// 	char	str[] = "00000";
// 	// char	*str = NULL;
// 	char	*ptr;

// 	ptr = ft_strmapi(str, ft_addindex);
// 	printf("Before ft_strmapi: %s\n", str);
// 	printf("Before ft_strmapi: %s\n", ptr);
// 	free(ptr);
// 	return (0);
// }
