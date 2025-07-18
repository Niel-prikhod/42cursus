/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niel <niel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:24:23 by niel              #+#    #+#             */
/*   Updated: 2025/07/18 01:42:33 by niel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char    *file = "[kernel_session]/gnl.txt"; 
    int fd = open(file, O_RDONLY);
    char    *str;
    str = "   ";
    while (str)
    {
        str = get_next_line(fd);
        printf("%s", str);
    }
    close(fd);
    return 0;
}
