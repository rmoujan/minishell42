/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:01:38 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/12 12:30:37 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//test for linked list .. they are working !!!
typedef struct data d;
struct data{
    int num;
    d *next;
};

int main()
{
    int i;
    i = 0;
    d *head;
    d *p; 

    
    head = NULL;
    while (i < 5)
    {
        if (head == NULL)
        {
            head = (d*) malloc(sizeof(d));
            head->num = (i + 1) * 100;
            p = head;
        }
        else 
        {
            p->next = (d*) malloc(sizeof(d));
            p = p->next;
            p->num = (i + 1) * 100;
        }
        i++;
    }
    p->next = NULL;
    while (head)
    {
        printf("%d\n", head->num);
        head = head->next;
    }
    return (0);
}