/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcolors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:06:22 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/26 16:45:02 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCOLORS_H
# define LIBCOLORS_H

// Definindo cores ANSI como macros
# define RESET "\033[0m"

// STYLES
# define BOLD "\033[1m"
# define ITALIC "\033[3m"
# define UNDERLINE "\033[4m"
# define BLINK "\033[5m"
# define REVERSE "\033[7m"
# define HIDE "\033[8m"

// COLORS
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

// COLORS
# define BLACK_B "\033[1;30m"
# define RED_B "\033[1;31m"
# define GREEN_B "\033[1;32m"
# define YELLOW_B "\033[1;33m"
# define BLUE_B "\033[1;34m"
# define MAGENTA_B "\033[1;35m"
# define CYAN_B "\033[1;36m"
# define WHITE_B "\033[1;37m"

// COLORS
# define BLACK_I "\033[3;30m"
# define RED_I "\033[3;31m"
# define GREEN_I "\033[3;32m"
# define YELLOW_I "\033[3;33m"
# define BLUE_I "\033[3;34m"
# define MAGENTA_I "\033[3;35m"
# define CYAN_I "\033[3;36m"
# define WHITE_I "\033[3;37m"

// COLORS
# define BLACK_U "\033[4;30m"
# define RED_U "\033[4;31m"
# define GREEN_U "\033[4;32m"
# define YELLOW_U "\033[4;33m"
# define BLUE_U "\033[4;34m"
# define MAGENTA_U "\033[4;35m"
# define CYAN_U "\033[4;36m"
# define WHITE_U "\033[4;37m"


// Cores de fundo
# define BG_BLACK "\033[1;40m"
# define BG_RED "\033[1;41m"
# define BG_GREEN "\033[1;42m"
# define BG_YELLOW "\033[1;43m"
# define BG_BLUE "\033[1;44m"
# define BG_MAGENTA "\033[1;45m"
# define BG_CYAN "\033[1;46m"
# define BG_WHITE "\033[1;47m"

#endif // !LIBCOLORS_H
