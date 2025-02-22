#include <stdio.h>
#include <string.h>

typedef unsigned short int uint16;

int romanToInt(char* s)
{
  uint16 result= 0u;
  /* Get the length of s */
  const uint16 s_len= strlen(s);

  if(s_len < 1 || s_len > 15)
    /* Constraints regarding s_len are not respected */
    return 0;

  for(int i=0; i<s_len; i++)
  {
    switch(s[i])
    {
      case 'I': /* 1 */
        if(i < s_len-1)
        {
          /* Verify if the following element is X or V */
          if(s[i+1] == 'X')
          {
            result+= 9u;
            i++;
            break;
          }
          if(s[i+1] == 'V')
          {
            result+= 4u;
            i++;
            break; 
          }
        }
        result+= 1u;
        break;
      case 'V': /* 5 */
        result+= 5u;
        break;
      case 'X': /* 10 */
        if(i < s_len-1)
        {
          /* Verify if the following element is C or L */
          if(s[i+1] == 'C')
          {
            result+= 90u;
            i++;
            break;
          }
          if(s[i+1] == 'L')
          {
            result+= 40u;
            i++;
            break; 
          }
        }
        result+= 10u;
        break;
      case 'L': /* 50 */
        result+= 50;
        break;
      case 'C': /* 100 */
        if(i < s_len-1)
        {
          /* Verify if the following element is M or D */
          if(s[i+1] == 'M')
          {
            result+= 900u;
            i++;
            break;
          }
          if(s[i+1] == 'D')
          {
            result+= 400u;
            i++;
            break; 
          }
        }
        result+= 100u;
        break;
      case 'D': /* 500 */
        result+= 500u;
        break;
      case 'M': /* 1000 */
        result+= 1000u;
        break;
      default: /* Should never reach here, bad input string */
        return 0;
    }
  }

  return (int)result;
}

int main()
{
  char s[]= "MCMXCIV";

  const int res= romanToInt(s);

  printf("%d\n", res);
  return 0;
}
