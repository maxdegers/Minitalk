/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:49:56 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/06 11:37:02 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H
# define SLEEPTIME 100

# include "libft/libft.h"
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>

// client
void	ft_convert_client(int nbr, pid_t pid);
void	ft_fillzero(int nbr, pid_t pid);
// server
void	handler(int sig, siginfo_t *info, void *ucontext);
#endif