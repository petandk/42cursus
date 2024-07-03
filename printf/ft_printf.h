/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:19:10 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/03 19:16:35 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

void	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putfloat_fd(float num, int fd);
int		ft_puthex_fd(unsigned long long num, int fd, int uppercase);
int		ft_putpointer_fd(void *pointer, int fd);
int		ft_putunsignednbr_fd(unsigned int n, int fd);

#endif
