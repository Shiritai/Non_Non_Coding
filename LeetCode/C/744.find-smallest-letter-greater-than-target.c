/*
 * @lc app=leetcode id=744 lang=c
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/07/26
 * Time : beats 83.5 %
 * Space : beats 70 %
 */

char nextGreatestLetter(char * letters, int lettersSize, char target){
    char * charSet = (char *) malloc(sizeof(char) * lettersSize);
    int realSize = 0;
    for (int i = 0; i < lettersSize; ++i){
        charSet[i] = '\0'; // init
        if (letters[i] != charSet[(realSize) ? realSize - 1 : 0])
            charSet[realSize++] = letters[i];
    }
    int tmpInd = realSize >> 1, l = 0, r = realSize;
    while (1){
        if (charSet[tmpInd] > target){
            if (tmpInd && charSet[tmpInd - 1] > target){
                r = tmpInd;
                tmpInd = (l + r) >> 1;
            }
            else if ((tmpInd && charSet[tmpInd - 1] == target) || 
                (!tmpInd || target > charSet[tmpInd - 1]))
                break;
        }
        else if (charSet[tmpInd] < target){
            l = tmpInd + 1;
            if (l >= r){ // greater than the last character
                tmpInd = 0;
                break;
            }
            tmpInd = (l + r) >> 1;
        }
        else if (charSet[tmpInd] == target){
            tmpInd = (tmpInd == realSize - 1) ? 0 : tmpInd + 1;
            break;
        }
    }
    char res = charSet[tmpInd];
    free(charSet);
    return res;
}

// int main(void){
//     printf("%c\n", nextGreatestLetter("cccffffffjj", 11, 'k'));
// }
// @lc code=end

