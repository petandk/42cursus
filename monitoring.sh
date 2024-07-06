#!/bin/sh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    monitoring.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 14:17:20 by rmanzana          #+#    #+#              #
#    Updated: 2024/07/06 14:17:47 by rmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo "#Architecture: $(uname -a)"
echo "#CPU physical : $(grep -c ^processor /proc/cpuinfo)"
echo "#vCPU : $(grep -c ^processor /proc/cpuinfo)"
echo "#Memory Usage: $(free -m | awk 'NR==2{printf "%s/%sMB (%.2f%%)", $3,$2,$3*100/$2 }')"
echo "#Disk Usage: $(df -h | awk '$NF=="/"{printf "%d/%dGB (%s)", $3,$2,$5}')"
echo "#CPU load: $(top -bn1 | grep load | awk '{printf "%.1f%%", $(NF-2)}')"
echo "#Last boot: $(who -b | awk '{print $3" "$4}')"
echo "#LVM use: $(if [ $(lsblk | grep lvm | wc -l) -gt 0 ]; then echo yes; else echo no; fi)"
echo "#TCP Connections : $(ss -t | grep ESTAB | wc -l) ESTABLISHED"
echo "#User log: $(who | wc -l)"
echo "#Network: IP $(hostname -I | awk '{print $1}') ($(ip link | awk '/ether/ {print $2}'))"
echo "#Sudo : $(journalctl _COMM=sudo | grep COMMAND | wc -l) cmd"
