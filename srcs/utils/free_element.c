/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:10:44 by abahmani          #+#    #+#             */
/*   Updated: 2022/05/22 03:46:05 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_char_tab(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static void	free_redir(void *v_redir)
{
	t_redir_data	*redir;
	
	redir = (t_redir_data *)v_redir;
	free(redir->file);
	free(redir);
}

void	free_token_lst(t_list **l_token)
{
	t_list			*prec;
	t_token			*tkn;
	t_redir_data	**redir_data;

	prec = *l_token;
	while (*l_token)
	{
		(*l_token) = (*l_token)->next;
		tkn = (t_token *)prec->content;
		if (tkn->l_redir && *(tkn->l_redir))
		{
			redir_data = (t_redir_data **)tkn->l_redir;
			ft_lstclear(redir_data, &free_redir);
		}
		free(tkn->cmd);
		free(tkn->args);
		prec = *l_token;
	}
}