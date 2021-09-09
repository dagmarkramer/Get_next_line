/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/08 12:43:28 by dkramer       #+#    #+#                 */
/*   Updated: 2020/12/10 12:44:51 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		retisnull(char **np, int fd, char **line)
{
	if (np[fd])
	{
		*line = ft_strdup(np[fd]);
		if (*line == NULL)
			return (-1);
		free(np[fd]);
		np[fd] = NULL;
	}
	else
	{
		*line = ft_strdup("");
		if (*line == NULL)
			return (-1);
	}
	return (0);
}

char	*makenp(char **np, int fd, char *buf)
{
	char			*keep;

	if (np[fd] == NULL)
	{
		np[fd] = ft_strdup(buf);
		if (np[fd] == NULL)
			return (NULL);
	}
	else
	{
		keep = ft_strjoin(np[fd], buf);
		if (keep == NULL)
			return (NULL);
		free(np[fd]);
		np[fd] = keep;
	}
	return (np[fd]);
}

int		makeline(char **np, int fd, char **line)
{
	char			*keep;

	if (ft_intstrchr(np[fd], 1) == 0)
	{
		*line = ft_strdup("");
		if (*line == NULL)
			return (-1);
		keep = ft_strdup(&np[fd][1]);
		if (keep == NULL)
			return (-1);
		if (np[fd])
			free(np[fd]);
		np[fd] = keep;
		return (1);
	}
	*line = ft_substr(np[fd], 0, ft_intstrchr(np[fd], 1));
	if (*line == NULL)
		return (-1);
	keep = ft_strdup(&np[fd][ft_intstrchr(np[fd], 1) + 1]);
	if (keep == NULL)
		return (-1);
	if (np[fd])
		free(np[fd]);
	np[fd] = keep;
	return (1);
}

int		retloop(char **np, int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
		return (-1);
	if (ret == 0)
		return (retisnull(np, fd, line));
	buf[ret] = '\0';
	while (ret)
	{
		np[fd] = makenp(np, fd, buf);
		if (np[fd] == NULL)
			return (-1);
		if (ft_intstrchr(np[fd], 0))
			return (makeline(np, fd, line));
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0)
			return (retisnull(np, fd, line));
		buf[ret] = '\0';
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*np[FDMAX];

	if (BUFFER_SIZE == 0 || line == NULL || fd < 0 || fd > FDMAX)
		return (-1);
	if (np[fd] != NULL && ft_intstrchr(np[fd], 0))
		return (makeline(np, fd, line));
	else
		return (retloop(np, fd, line));
}
