/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:09:29 by rmoujan           #+#    #+#             */
/*   Updated: 2022/07/28 22:28:42 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"


// ///does not workinggggggggggggggggg !!!!!!
// //hena fash kayn errror !!!!!
// //had fct hiya li mnha moshkil makremovish dok dq and sq mzn like had example : echo "hallo "$USER    " jkokoko   "
// char *remove_dq(char *str)
// {
//     int i;
//     int start;
//     int quots;
//     char *str1;
//     char *str2;
        
//     str1 = ft_strdup("");
//     str2 = ft_strdup("");
//     i = 0;
//     quots = 0;
//     int c1 = 0;
//     int c2 = 0;
//     // printf("--- > %s\n", str);
//     while (str[i] !='\0')
//     {
//         if (str[i] =='"') 
//             c1++;
//         if (str[i] =='\'') 
//             c2++; 
//         i++;
//     }
//     // printf("%d and %d\n", c1, c2);
//     if (c1 == 0 && c2 == 0)
//         return str;
//     // printf("koko \n");
//     i = 0;
//     while (str[i] != '\0')
//     {  
//         // printf("while \n");
//         // start = i;
//         if(!quots && (str[i] == '\'' || str[i] == '"'))
//         {
//             // if (i != 0)
//             // {
//             //     str2 = ft_substr(str, start, (i - start - 1));
//             //     str1 = ft_strjoin(str1, str2);
//             //     printf("-->[%s]\n", str1);
//             // }
//             if (str[i + 1] != '\0')
//                 start = i + 1;
//             quots = str[i];
//         // printf("inside 1 if %d \n", i);
//         }
//         else if(quots && str[i] == quots)
//         {
//             //printf("inside 2 if  %d\n", i);
//             quots = 0;
//             str2 = ft_substr(str, start, (i - start));
//             str1 = ft_strjoin(str1, str2);
//             start =++i;
//             printf("**[%s]\n", str1);
//         }
//         else if (quots == 0)
//         {
//             while (str[i] != '\0' && (str[i] != '\'' || str[i] != '"'))
//                 i++;
            
//             str2 = ft_substr(str, start, (i - start));
//             str1 = ft_strjoin(str1, str2);
//             // printf("-->[%s]\n", str1);
//         }
//             i++;
//     }
//     return (str1);
// }
// // had case makhedmash : 
// // echo "hallo "$USER    " jkokoko   "



//NEW VERSION ::does not work !!!
// char *remove_dq(char *str)
// {
//     int i;
//     int start;
//     int quots;
//     char *str1;
//     char *str2;
        
//     str1 = ft_strdup("");
//     str2 = ft_strdup("");
//     i = 0;
//     quots = 0;
//     int c1 = 0;
//     int c2 = 0;
//     // printf("--- > %s\n", str);
//     while (str[i] !='\0')
//     {
//         if (str[i] =='"') 
//             c1++;
//         if (str[i] =='\'') 
//             c2++; 
//         i++;
//     }
//     if (c1 == 0 && c2 == 0)
//         return str;
//     i = 0;
//     while (str[i] != '\0')
//     {
        
//         if(!quots && (str[i] == '\'' || str[i] == '"'))
//         {

//             if (str[i + 1] != '\0')
//                 start = i + 1;
//             quots = str[i];
//         }
//         else if(quots && str[i] == quots)
//         {
//             quots = 0;
//             str2 = ft_substr(str, start, (i - start));
//             str1 = ft_strjoin(str1, str2);
//             start =++i;
//             printf("**[%s]\n", str1);
//         }
//         else if (quots == 0)
//         {
//             start = i;
//             while (str[i] != '\0' && (str[i] != '\'' || str[i] != '"'))
//                 i++;
            
//             str2 = ft_substr(str, start, (i - start));
//             str1 = ft_strjoin(str1, str2);
//             // i--;
//         }
//             // i++;
//     }
//     return (str1);
// }

// char *remove_dq(char *str)
// {
    
// }