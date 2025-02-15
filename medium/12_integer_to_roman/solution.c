#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertIntegerToRoman(char* output, int char_index, int current_num, char char1, char char2, char char3)
{
  if(current_num < 4)
  {
    for(int j=current_num; j!=0; j--)
    {
      output[char_index]= char1;
      char_index++;
    }
  }
  else if(current_num == 4)
  {
    output[char_index]= char1;
    char_index++;
    output[char_index]= char2;
    char_index++;
  }
  else if(current_num >= 5 && current_num < 9)
  {
    output[char_index]= char2;
    char_index++;
    for(int j=current_num; j!=5; j--)
    {
      output[char_index]= char1;
      char_index++;
    }
  }
  else
  {
    output[char_index]= char1;
    char_index++;
    output[char_index]= char3;
    char_index++;
  }

  return char_index;
}

char* intToRoman(int num)
{
  static char output[20];
  /* Clear the array, being static the string value will be stored even after the function ended */
  memset(output, '\0', sizeof(output));
  /* Array used to store the number in this way we also calculate the length of the number */
  int num_arr[5]= {};
  int numLen= 0;
  /* Index of the output char */
  int char_index= 0;

  /* Check if num respect constraints */
  if((num < 1) || (num > 3999))
    return "";

  /* Store the num in the array and calculate the length of it */
  while(num!=0)
  {
    num_arr[numLen]= (num%10);
    num/=10;
    numLen++;
  }

  /* Start filling the output string with roman characters */
  for(int i=numLen-1; i!=-1; i--)
  {
    switch(i)
    {
      case 3:
        for(int j=num_arr[i]; j!=0; j--)
        {
          output[char_index]= 'M';
          char_index++;
        }
        break;
      case 2:
        char_index= convertIntegerToRoman(output, char_index, num_arr[i], 'C', 'D', 'M');
        break;
      case 1:
        char_index= convertIntegerToRoman(output, char_index, num_arr[i], 'X', 'L', 'C');
        break;
      case 0:
        char_index= convertIntegerToRoman(output, char_index, num_arr[i], 'I', 'V', 'X');
        break;
    }
  }

  return output;
}

int main()
{
  int num= 1492;

  printf("%s\n", intToRoman(num));

  return 0;
}
