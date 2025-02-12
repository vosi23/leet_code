#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isMatch(char *s, char *p)
{
  int s_len = strlen(s);
  int p_len = strlen(p);
  bool dp[s_len + 1][p_len + 1];

  /* Initialize table with false */
  memset(dp, false, sizeof(dp));
  
  /* Set the first element of the table to true */
  dp[0][0] = true;
  
  /* a. Handle patterns like "a*", ".*", "c*" at the start */
  for (int col= 1; col <= p_len; col++)
  {
    if (p[col - 1] == '*')
      dp[0][col] = dp[0][col - 2];
  }

  /* b. parse & compare */
  for (int row = 1; row <= s_len; row++)
  {
    for (int col = 1; col <= p_len; col++)
    {
      if (p[col - 1] == s[row - 1] || p[col - 1] == '.')
      {
        /* Direct match */
        dp[row][col] = dp[row - 1][col - 1];
      }
      else if (p[col - 1] == '*')
      {
        /* '*' removes previous char */
        dp[row][col] = dp[row][col - 2];

        if (p[col - 2] == s[row - 1] || p[col - 2] == '.')
        {
          /* '*' matches multiple occurrences */
          dp[row][col] |= dp[row - 1][col];
        }
      }
    }
  }

  /* Return result */
  return dp[s_len][p_len];
}

int main()
{
  char s[] = "aab";
  char p[] = "c*a*b";

  printf("%s\n", isMatch(s, p) == true ? "true" : "false");

  return 0;
}
