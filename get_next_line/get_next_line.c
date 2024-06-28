/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:13:18 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/11 12:51:45 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	rtn = malloc(sizeof(char) * (ft_strlen(save) - i));
	if (!rtn)
		return (NULL);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	// if (str[i] == '\n')
	// {
	// 	rtn[i] = str[i];
	// 	i++;
	// }
	rtn[i] = 0;
	return (rtn);
}

char	*read_loop(int fd, int reader, char *buff, char *save)
{
	while (reader != 0 && !has_nwl(save))
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
		buff[reader] = '\0';
		save = join_str(save, buff);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char			*buff;
	char			*line;
	static char		*save;
	int				reader;

	reader = 1;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = buff;
	if (!line || !buff)
		return (NULL);
	save = read_loop(fd, reader, buff, save);
	free (buff);
	if (save == NULL)
		return (NULL);
	line = get_line(save);
	save = get_save(save);
	if (!*line)
	{
		free (line);
		return (NULL);
	}
	return (line);
}
/*Don't forget to free after use*/

/*
int	main(int ac, char **av)
{
	int file;
	int i;
	char *line;

	if (ac != 2)
		return(1);

	file = open(av[1], O_RDONLY);
	if (file < 0)
	{
		printf("couldn't OPEN");
		return (1);
	}
	i = 1;
	line = get_next_line(file);
	while (line)
	{
		printf("line No%d:%s", i, line);
		line = get_next_line(file);
		i++;
	}
	close(file);
	return (0);
}*/