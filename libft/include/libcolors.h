/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcolors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:06:22 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/23 23:09:10 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCOLORS_H
# define LIBCOLORS_H

// Definindo cores ANSI como macros
# define RESET "\033[0m"

// STYLES
# define BOLD "\033[1m"
# define ITALIC "\033[3m"
# define UNDERLINE "\0334[m"
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

// Cores de fundo
# define BG_BLACK "\033[1;40m"
# define BG_RED "\033[1;41m"
# define BG_GREEN "\033[1;42m"
# define BG_YELLOW "\033[1;43m"
# define BG_BLUE "\033[1;44m"
# define BG_MAGENTA "\033[1;45m"
# define BG_CYAN "\033[1;46m"
# define BG_WHITE "\033[1;47m"

// FUNCTION
# define ANSI_COLOR(style, color) style color
# define ANSI_COMBO(style, color, bg_color) style color

#endif // !LIBCOLORS_H
