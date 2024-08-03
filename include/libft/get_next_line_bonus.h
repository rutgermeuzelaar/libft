/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 13:05:33 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/03 15:30:35 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef FILE_DESCRIPTOR_MAX
#  define FILE_DESCRIPTOR_MAX 100000
# endif
# if FILE_DESCRIPTOR_MAX <= 0
#  error "FILE_DESCRIPTIOR_MAX needs to be greater than 0."
# endif
#endif