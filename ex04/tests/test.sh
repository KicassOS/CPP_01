# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 21:34:16 by pszleper          #+#    #+#              #
#    Updated: 2023/05/17 21:49:56 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOCOLOR='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
WHITE='\033[1;37m'

echo "${YELLOW}Testing ./SedIsForLosers to_replace replacement executable${NOCOLOR}\n"
echo ""
echo "${WHITE}Testing too few arguments${NOCOLOR}"
echo ""
echo "${WHITE}Testing too many arguments${NOCOLOR}"
echo ""
echo "${WHITE}Testing non-existent input file${NOCOLOR}"
echo ""
echo "${WHITE}Testing file without read permission${NOCOLOR}"
echo ""
echo "${WHITE}Testing the case where bye == to_replace == replacement${NOCOLOR}"
echo ""
echo "${WHITE}Testing the preservation of beginning newlines${NOCOLOR}"
echo ""
echo "${WHITE}Testing the preservation of ending newlines${NOCOLOR}"
echo ""
echo "${WHITE}Testing the preservation of the lack of ending newline${NOCOLOR}"
echo ""
echo "${WHITE}Normal test with to_replace = bye and replacement = hey${NOCOLOR}"
echo ""
echo "${WHITE}Testing with to_replace = h, shorter than replacement = lol${NOCOLOR}"
echo ""
echo "${WHITE}Testing with to_replace = bye, longer than replacement = GG${NOCOLOR}"
echo ""
echo "${WHITE}Testing non-existent to_replace = thisdontexistbro${NOCOLOR}"
echo ""
echo "${WHITE}Testing whitespace to_replace = ' ' (single space) and replacement = '    ' (4 spaces)${NOCOLOR}"
echo ""

echo "${GREEN}The tests passed! Nice! ${NOCOLOR}\n"