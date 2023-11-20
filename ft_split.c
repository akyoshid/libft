/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:47:17 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/20 13:14:29 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Allocates and returns an array of strings
// obtained by splitting ’s’ using the character ’c’ as a delimiter.
// The array must end with a NULL pointer.

// === RETURN VALUE ===
// if (s == NULL) → Return NULL
// if (ft_wordcount == 0)

#include "libft.h"

static int	ft_countword(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**buff;

	if (s == NULL)
		return (NULL);
	buff = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (buff == NULL)
		return (NULL);
	
}





























// static void	*ft_freemem(char **buff, int last_index)
// {
// 	int	i;

// 	i = 0;
// 	while (i < last_index)
// 	{
// 		free(buff[i]);
// 		buff[i] = NULL;
// 		i++;
// 	}
// 	free(buff);
// 	buff = NULL;
// 	return (NULL);
// }

// static int	ft_countstr(char const *s, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*s != '\0')
// 	{
// 		while (*s != '\0' && *s == c)
// 			s++;
// 		if (*s != '\0')
// 			count++;
// 		while (*s != '\0' && *s != c)
// 			s++;
// 	}
// 	return (count);
// }

// static char	*ft_storeword(char const **s, char c)
// {
// 	int			count;
// 	const char	*start;
// 	char		*buff;

// 	while (**s == c)
// 		(*s)++;
// 	start = *s;
// 	count = 0;
// 	while (**s != '\0' && **s != c)
// 	{
// 		count++;
// 		(*s)++;
// 	}
// 	buff = malloc((count + 1) * sizeof(char));
// 	if (buff == NULL)
// 		return (NULL);
// 	ft_memcpy(buff, start, count);
// 	buff[count] = '\0';
// 	return (buff);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**buff;
// 	int		i;
// 	int		str_count;

// 	if (s == NULL)
// 		return (NULL);
// 	str_count = ft_countstr(s, c);
// 	buff = malloc((str_count + 1) * sizeof(char *));
// 	if (buff == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < str_count)
// 	{
// 		buff[i] = ft_storeword(&s, c);
// 		if (buff[i] == NULL)
// 			return (ft_freemem(buff, i));
// 		i++;
// 	}
// 	buff[str_count] = NULL;
// 	return (buff);
// }

// int	main(void)
// {
// 	char	str[] = "AAbbBBbbCC";
// 	char	c = 'b';
// 	char	**ptr;
// 	int		i;
// 	int		str_count;

// 	ptr = ft_split(str, c);
// 	i = 0;
// 	str_count = ft_countstr(str, c);
// 	while (i < str_count + 1)
// 	{
// 		printf("%s\n", ptr[i]);
// 		i++;
// 	}
// 	ft_freemem(ptr, str_count);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*str = NULL;
// 	char	c = 'b';
// 	char	**ptr;

// 	ptr = ft_split(str, c);
// 	if (ptr == NULL)
// 		printf("Success: ptr is NULL.\n");
// 	else
// 		printf("Failure: ptr is not NULL.\n");
// 	return (0);
// }
