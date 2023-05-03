/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:31:54 by jeolim            #+#    #+#             */
/*   Updated: 2023/05/03 18:32:26 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

int	create_heredoc(t_lexer *heredoc, int quotes,
	t_data *data, char *file_name);
int	ft_heredoc(t_data *data, t_lexer *heredoc, char *file_name);
char	*generate_heredoc_filename(void);
int	send_heredoc(t_data *data, t_cmds *cmd);

int	create_heredoc(t_lexer *heredoc, int quotes,
	t_data *data, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	line = readline(HEREDOC_MSG);
	
	while (line && !g_mini.stop_heredoc && ft_strncmp(heredoc->str, line, ft_strlen(heredoc->str) + 1))
	{
		if (quotes == False)
			line = expander_str(data, line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline(HEREDOC_MSG);
	}
	free(line);
	if (g_mini.stop_heredoc || !line)
		return (1);
	close(fd);
	return (0);
}

int	ft_heredoc(t_data *data, t_lexer *heredoc, char *file_name)
{
	int	quotes;
	int	sl;

	sl = 0;
	if ((heredoc->str[0] == '\"'
			&& heredoc->str[ft_strlen(heredoc->str) - 1] == '\"')
		|| (heredoc->str[0] == '\''
			&& heredoc->str[ft_strlen(heredoc->str) - 1] == '\''))
		quotes = True;
	else
		quotes = False;
	delete_quotes(heredoc->str, '\"');
	delete_quotes(heredoc->str, '\'');
	g_mini.stop_heredoc = 0;
	g_mini.in_heredoc = 1;
	sl = create_heredoc(heredoc, quotes, data, file_name);
	g_mini.in_heredoc = 0;
	data->heredoc = True;
	return (sl);
}

char	*generate_heredoc_filename(void)
{
	static int	i = 0;
	char		*num;
	char		*file_name;

	num = ft_itoa(i++);
	file_name = ft_strjoin("build/.tmp_heredoc_file_", num);
	free(num);
	return (file_name);
}

int	send_heredoc(t_data *data, t_cmds *cmd)
{
	t_lexer	*start;
	int		sl;

	start = cmd->redi;
	sl = 0;
	while (cmd->redi)
	{	
		if (cmd->redi->token == DLESS)
		{
			if (cmd->file_name)
				free(cmd->file_name);
			cmd->file_name = generate_heredoc_filename();
			sl = ft_heredoc(data, cmd->redi, cmd->file_name);
			if (sl)
			{
				g_mini.error_num = 1;
				return (data_reset(data));
			}
		}
		cmd->redi = cmd->redi->next;
	}
	cmd->redi = start;
	return (0);
}
