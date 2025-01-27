/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:53:05 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/01/27 09:25:27 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int valid_format(char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len++;
    if (len > 4 && str[len - 4] == '.' && str[len - 3] == 'b' &&
        str[len - 2] == 'e' && str[len - 1] == 'r')
        return (1);
    return (0);
}