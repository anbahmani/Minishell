/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:56:20 by abahmani          #+#    #+#             */
/*   Updated: 2022/05/06 12:04:24 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "unistd.h"
# include "stdlib.h"
# include "stdbool.h"
# include "stdio.h"

typedef enum e_identifier{
	PIPE,
	COMMAND,
	LEFT_SIMPLE_REDIRECTION,
	RIGHT_SIMPLE_REDIRECTION,
	RIGHT_DOUBLE_REDIRECTION,
	LEFT_DOUBLE_REDIRECTION,
	SEMICOLON
}	t_identifier;

typedef struct s_token
{
	t_identifier	id;
	char			*option;
	char			**input;
	struct s_token	*next;
}	t_token;

#endif