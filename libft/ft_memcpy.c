/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:58:41 by ruijia            #+#    #+#             */
/*   Updated: 2025/03/02 21:45:26 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*a;
	unsigned char		*b;

	if (!dest && !src)
		return (NULL);
	i = 0;
	a = (const unsigned char *)src;
	b = (unsigned char *)dest;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (dest);
}

/*int main(void)
{
    char buffer[20] = "Hola, mundo!"; 
	char buffer2[10] = "wqewe";
    printf("Antes: %s\n", buffer2);
    
    ft_memcpy(buffer2, buffer, 6);
    printf("Después: %s\n", buffer2);
    
    return 0;
}*/