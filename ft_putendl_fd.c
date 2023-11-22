/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:41:50 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/22 19:45:38 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === ERROR HANDLING ===
// if (s == NULL) → End the function.

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	ft_putendl_fd("abcdefg", 1);
// 	return (0);
// }
