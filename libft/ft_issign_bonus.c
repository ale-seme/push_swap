/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_issign_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 18:40:39 by asemerar      #+#    #+#                 */
/*   Updated: 2024/01/18 18:41:11 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}
