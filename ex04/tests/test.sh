#/bin/zsh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 21:34:16 by pszleper          #+#    #+#              #
#    Updated: 2023/05/18 12:35:24 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOCOLOR='\033[0m'
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
WHITE='\033[1;37m'

#This variable is set to 1 upon error in a test
TEST_ERROR=0

#Checking if the script is ran inside the tests/ directory
LAST_DIR_IN_PATH=$(echo $PWD | rev | cut -d/ -f1 | rev)
if [ $LAST_DIR_IN_PATH != 'tests' ]
then
	echo "${WHITE}Please cd into the tests directory${NOCOLOR}"
	exit 42
fi

echo "\n${YELLOW}Testing ./SedIsForLosers to_replace replacement${NOCOLOR}"
echo "${WHITE}Running make..."
make -C ..; cp ../SedIsForLosers .
echo "\n"

echo "${WHITE}Test #1: too few arguments: ${NOCOLOR}./SedIsForLosers test1.txt MISSINGARG "
./SedIsForLosers test1.txt MISSINGARG
if [ ! -f "test1.txt.replace" ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

echo "${WHITE}Test #2: too many arguments: ${NOCOLOR}./SedIsForLosers test2.txt brian "REPLACED BRIAN" EXTRAARG "
./SedIsForLosers test2.txt brian "REPLACED BRIAN" EXTRAARG
if [ ! -f "test2.txt.replace" ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

echo "${WHITE}Test #3: non-existent input file: ${NOCOLOR}./SedIsForLosers doesntexisttest3.txt brian "REPLACED BRIAN" "
./SedIsForLosers doesntexisttest3.txt brian "REPLACED BRIAN"
if [ ! -f "test3.txt.replace" -a ! -f "doesntexisttest3.txt" -a ! -f "doesntexisttest3.txt.replace" ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

echo "${WHITE}Test #4: input file without read permission: ${NOCOLOR}./SedIsForLosers test4.txt brian "REPLACED BRIAN" "
chmod -r test4.txt
./SedIsForLosers test4.txt brian "REPLACED BRIAN"
chmod +r test4.txt
if [ ! -f "test4.txt.replace" ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

echo "${WHITE}Test #5 the case where bye = to_replace = replacement: ${NOCOLOR}./SedIsForLosers test5.txt bye bye "
./SedIsForLosers test5.txt bye bye
REPLACE_CONTENTS=$(diff test5_expected.txt test5.txt.replace | wc -c)
if [ $? -eq 0 -a -f "test5.txt.replace" -a $REPLACE_CONTENTS -eq 0 ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

echo "${WHITE}Test #6 the preservation of beginning newlines: ${NOCOLOR}./SedIsForLosers test6.txt brian "BETTER BRIAN" "
./SedIsForLosers test6.txt brian "BETTER BRIAN"
REPLACE_CONTENTS=$(diff test6_expected.txt test6.txt.replace | wc -c)
if [ $? -eq 0 -a -f "test6.txt.replace" -a $REPLACE_CONTENTS -eq 0 ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

echo "${WHITE}Test #7: the preservation of ending newlines: ${NOCOLOR}./SedIsForLosers test7.txt brian "BETTER BRIAN" "
./SedIsForLosers test7.txt brian "BETTER BRIAN"
REPLACE_CONTENTS=$(diff test7_expected.txt test7.txt.replace | wc -c)
if [ $? -eq 0 -a -f "test7.txt.replace" -a $REPLACE_CONTENTS -eq 0 ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

echo "${WHITE}Test #8: the preservation of the lack of ending newline: ${NOCOLOR}./SedIsForLosers test8.txt brian "BETTER BRIAN" "
./SedIsForLosers test8.txt brian "BETTER BRIAN"
REPLACE_CONTENTS=$(diff test8_expected.txt test8.txt.replace | wc -c)
if [ $? -eq 0 -a -f "test8.txt.replace" -a $REPLACE_CONTENTS -eq 0 ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

echo "${WHITE}Test #9: Equal length to_replace and replacement: ${NOCOLOR} ./SedIsForLosers test9.txt bye hey"
./SedIsForLosers test9.txt bye hey
REPLACE_CONTENTS=$(diff test9_expected.txt test9.txt.replace | wc -c)
if [ $? -eq 0 -a -f "test9.txt.replace" -a $REPLACE_CONTENTS -eq 0 ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

echo "${WHITE}Test #10: to_replace shorter than replacement: ${NOCOLOR} ./SedIsForLosers test10.txt h lol"
./SedIsForLosers test10.txt h lol
REPLACE_CONTENTS=$(diff test10_expected.txt test10.txt.replace | wc -c)
if [ $? -eq 0 -a -f "test10.txt.replace" -a $REPLACE_CONTENTS -eq 0 ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

echo "${WHITE}Test #11: with to_replace longer than replacement = GG: ${NOCOLOR} ./SedIsForLosers test11.txt bye GG"
./SedIsForLosers test11.txt bye GG
REPLACE_CONTENTS=$(diff test11_expected.txt test11.txt.replace | wc -c)
if [ $? -eq 0 -a -f "test11.txt.replace" -a $REPLACE_CONTENTS -eq 0 ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

echo "${WHITE}Test #12: non-existent to_replace: ${NOCOLOR} ./SedIsForLosers test12.txt thisdontexistintheinputfilebro REPLACEDITBRO"
./SedIsForLosers test12.txt thisdontexistintheinputfilebro REPLACEDITBRO
REPLACE_CONTENTS=$(diff test12_expected.txt test12.txt.replace | wc -c)
if [ $? -eq 0 -a -f "test12.txt.replace" -a $REPLACE_CONTENTS -eq 0 ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

echo "${WHITE}Test #13: whitespace in to_replace = ' ' (single space) and replacement = '    ' (4 spaces): ${NOCOLOR} ./SedIsForLosers test13.txt ' ' '    '"
./SedIsForLosers test13.txt ' ' '    '
REPLACE_CONTENTS=$(diff test13_expected.txt test13.txt.replace | wc -c)
if [ $? -eq 0 -a -f "test13.txt.replace" -a $REPLACE_CONTENTS -eq 0 ]
then
	echo "${GREEN}OK${NOCOLOR}\n"
else
	echo "${RED}KO${NOCOLOR}\n"
	TEST_ERROR=$((TEST_ERROR+1))
fi

if [ ${TEST_ERROR} -eq 0 ]
then
	echo "\n${GREEN}The tests passed! Nice! ${NOCOLOR}\n"
else
	echo "\n${RED}${TEST_ERROR} test(s) failed!${NOCOLOR}\n"
fi
