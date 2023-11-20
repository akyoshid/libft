/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:22:56 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/20 12:19:09 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Allocates and returns a copy of ’s1’ 
// with the characters specified in ’set’ removed
// from the beginning and the end of the string

// setがempty stringの時、s1のコピーを返す
// 全部setだった場合は、空の文字列を返す

#include "libft.h"

static size_t	ft_isset(const char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buff;
	size_t	s1_len;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	start = 0;
	while (ft_isset(s1[start], set) && start < s1_len)
		start++;
	if (start == s1_len)
		return (ft_calloc(1, 1));
	end = s1_len - 1;
	while (ft_isset(s1[end], set))
		end--;
	buff = malloc((end - start + 2) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	ft_strlcpy(buff, s1 + start, end - start + 2);
	return (buff);
}

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	const char	*start;
// 	const char	*end;
// 	char		*buff;

// 	if (s1 == NULL)
// 		return (NULL);
// 	if (set == NULL)
// 		return (ft_strdup(s1));
// 	start = s1;
// 	end = s1 + ft_strlen(s1) - 1;
// 	while (*start != '\0' && ft_findchar(set, *start))
// 		start++;
// 	while (start < end && ft_findchar(set, *end))
// 		end--;
// 	buff = malloc(end - start + 2);
// 	if (buff == NULL)
// 		return (NULL);
// 	ft_memcpy(buff, start, end - start + 1);
// 	buff[end - start + 1] = '\0';
// 	return (buff);
// }

// int	main(void)
// {
// 	char	str[] = "  \t \t \n   \n\n\n\t";
// 	// char	set[] = " \n\t";
// 	char	*set = NULL;
// 	char	*ptr;

// 	ptr = ft_strtrim(str, set);
// 	printf("%s\n", ptr);
// 	return (0);
// }
