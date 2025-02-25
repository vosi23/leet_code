#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
  static char output[200];

  bool mismatch= false;
  int holder;
  int minLen= strlen(strs[0]);

  /* Output is static so needs to be overwirtten in order to not hold old data */
  memset(output, '\0', 200);

  /* Find the min length from strs arrays */
  for(int i=1; i<strsSize; i++) /* i=1 because the first element is already stored in minLen*/
  {
    holder= strlen(strs[i]);
    if(holder < minLen)
      minLen= holder;
  }

  for(int i=0; i<minLen; i++)
  {
    holder= 0;
    for(int j=0; j<strsSize; j++)
    {
      if(holder == 0)
      {
        holder= strs[j][i];
      }
      if(strs[j][i] != holder)
        mismatch= true;
    }
    /* If the characters are the same then will append the char in the output */
    if(mismatch)
      break;
    else
      output[i]= holder;
  }

  return output;
}

int main()
{
  char *strs[]= {"flower", "flow", "for"};
  const int strsSize= sizeof(strs) / sizeof(strs[0]);

  printf("%s\n", longestCommonPrefix(strs, strsSize));

  return 0;
}
