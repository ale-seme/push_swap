/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 11:30:49 by asemerar      #+#    #+#                 */
/*   Updated: 2023/10/20 18:52:02 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write (fd, s, len);
}

// int main(void)
// {
// 	char s[] = "123tuttigliangeliincolonna";
// 	ft_putstr_fd(s, 1);
// 	return (0);
// }