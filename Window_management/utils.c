/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:40:43 by mthea             #+#    #+#             */
/*   Updated: 2023/01/18 11:40:53 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

void	*ft_memset(void *str, int value, size_t n)
{
	size_t			i;
	char			*chaine;

	chaine = str;
	i = 0;
	while (i < n)
	{
		chaine[i] = value;
		i++;
	}
	return (chaine);
}