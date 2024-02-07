/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:49:56 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/07 14:57:41 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_BONUS_H
# define PROJECT_BONUS_H
# define SLEEPTIME 100

# include "libft/libft.h"
# include <signal.h>
# include <sys/types.h>

// client
void	ft_convert_client(int nbr, pid_t pid);
void	ft_fillzero(int nbr, pid_t pid);
// server
void	handler(int sig, siginfo_t *info, void *ucontext);

#endif