/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_list_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:09:47 by aolen             #+#    #+#             */
/*   Updated: 2019/10/23 19:09:47 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define ELDER_BITS 261632
#define BUF_SIZE 1024

/*
** fill_chmod
** --------------
** 	summary: fills the empty string with file's permissions
**
**	n: file_stat.st_mode - number that represent file type and permissions
**	chmod: string in which permissions will be write
*/

static void	fill_chmod(int n, char *chmod)
{
	char	last3bits;
	int		bits_move;

	bits_move = 6;
	while (bits_move >= 0)
	{
		ft_strcat(chmod, "---");
		last3bits = (n >> bits_move) & 7;
		if (last3bits & 4)
			chmod[1 - (bits_move - 6)] = 'r';
		if (last3bits & 2)
			chmod[2 - (bits_move - 6)] = 'w';
		if (last3bits & 1)
			chmod[3 - (bits_move - 6)] = 'x';
		bits_move -= 3;
	}
	if (n & S_ISUID)
		chmod[3] = (chmod[3] == 'x') ? 's' : 'S';
	if (n & S_ISGID)
		chmod[6] = (chmod[6] == 'x') ? 's' : 'S';
	if (n & S_ISVTX)
		chmod[9] = (chmod[9] == 'x') ? 't' : 'T';
}

/*
** add_link_tail
** --------------
** 	summary: adds to link a "tail" like:
**		link -> linked_file
**
**	files: address of file (d_name) structure
**	d_name: name of file or directory from working directory
**	(i.e. "./directory")
*/

static void	add_link_tail(t_file *files, char *d_name, int f)
{
	char	s[BUF_SIZE];
	char	*temp;

	if (g_flags_ls->l || g_flags_ls->g)
	{
		temp = files->file_name;
		files->file_name = ft_strjoin((files->file_name), " -> ");
		if (f == 0)
			free(temp);
		ft_bzero(s, BUF_SIZE);
		readlink(d_name, s, BUF_SIZE);
		files->file_name = ft_strjoin_safe(&(files->file_name), s);
	}
}

/*
** add_chmod_files
** --------------
** 	summary: add chmod params to file structure chmod param, from
**	fileStat.st_mode
**
**	files: address of file (d_name) structure
**	d_name: name of file or directory
*/

void		add_chmod_files(t_file *files, char *d_name)
{
	struct stat		file_stat;

	lstat(d_name, &file_stat);
	files->chmod = ft_strnew(12);
	if (S_ISLNK(file_stat.st_mode))
	{
		files->chmod = ft_strcat(files->chmod, "l");
		add_link_tail(files, d_name, 1);
	}
	else if (S_ISREG(file_stat.st_mode))
		files->chmod = ft_strcat(files->chmod, "-");
	else if (S_ISDIR(file_stat.st_mode))
		files->chmod = ft_strcat(files->chmod, "d");
	else if (S_ISCHR(file_stat.st_mode))
		files->chmod = ft_strcat(files->chmod, "c");
	else if (S_ISBLK(file_stat.st_mode))
		files->chmod = ft_strcat(files->chmod, "b");
	else if (S_ISFIFO(file_stat.st_mode))
		files->chmod = ft_strcat(files->chmod, "p");
	else if (S_ISSOCK(file_stat.st_mode))
		files->chmod = ft_strcat(files->chmod, "s");
	fill_chmod(file_stat.st_mode, files->chmod);
}

/*
** add_chmod
** --------------
** 	summary: add chmod params to file structure chmod param, from
**	dir->d_type
**
**	files: address of file (d_name) structure
**	d_name: name of file or directory
**	dir: dirent struct of current directory
*/

void		add_chmod(t_file *files, char *d_name, struct dirent *dir)
{
	struct stat		file_stat;

	lstat(d_name, &file_stat);
	files->chmod = ft_strnew(12);
	if (dir->d_type == DT_LNK)
	{
		files->chmod = ft_strcat(files->chmod, "l");
		add_link_tail(files, d_name, 0);
	}
	else if (dir->d_type == DT_REG)
		files->chmod = ft_strcat(files->chmod, "-");
	else if (dir->d_type == DT_DIR)
		files->chmod = ft_strcat(files->chmod, "d");
	else if (dir->d_type == DT_CHR)
		files->chmod = ft_strcat(files->chmod, "c");
	else if (dir->d_type == DT_BLK)
		files->chmod = ft_strcat(files->chmod, "b");
	else if (dir->d_type == DT_FIFO)
		files->chmod = ft_strcat(files->chmod, "p");
	else if (dir->d_type == DT_SOCK)
		files->chmod = ft_strcat(files->chmod, "s");
	else
		files->chmod = ft_strcat(files->chmod, "d");
	fill_chmod(file_stat.st_mode, files->chmod);
}

/*
** add_major_minor
** --------------
** 	summary: if file is char-device or block-device calculate
**	major and minor for it
**
**	file_stat: stat structure returned by lstat() function
**	files: address of file (d_name) structure
*/

void		add_major_minor(struct stat file_stat, t_file *files)
{
	if (S_ISCHR(file_stat.st_mode) || S_ISBLK(file_stat.st_mode))
	{
		files->maj = major(file_stat.st_rdev);
		files->min = minor(file_stat.st_rdev);
	}
	else
	{
		files->maj = 0U;
		files->min = 0U;
	}
}
