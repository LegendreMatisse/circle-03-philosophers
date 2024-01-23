/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:35:18 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/23 20:35:46 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main() {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        j = i + 1;
        k = j + 1;
        printf("Philosopher %d is thinking\n", i);
        printf("Philosopher %d is eating\n", j);
        printf("Philosopher %d is eating\n", k);
    }
    return 0;
}
