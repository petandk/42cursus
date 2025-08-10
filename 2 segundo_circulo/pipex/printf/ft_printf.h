/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:19:10 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/01 19:36:30 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_singlechar_fd(char c, int fd);
int		ft_putstring_fd(char *str, int fd);
int		ft_putnum_fd(int n, int fd);
int		ft_putfloat_fd(float num, int fd);
int		ft_puthex_fd(unsigned long long num, int fd, int uppercase);
int		ft_putpointer_fd(void *pointer, int fd);
int		ft_putunsignednbr_fd(unsigned int n, int fd);
int		ft_printf(char const *str, ...);

#endif
