#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void){

    string s= get_string("Texto: ");
    int letters = 0;
    int words = 0;
    int setences = 0;
    double L, S;

      for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]) != 0)
        {
           ++letters;

        }
        if (s[i] == ' ' )
        {
           ++words;

        }
        if (s[i] == '.' || s[i] == '!' || s[i] == '?'  )
        {
            ++setences;

        }
    }
//printf("%i\n", words);
//printf("%i\n", letters);
//printf("%i\n", setences);
 L = letters/(float)words * 100;
 S =  setences/(float)words * 100;

int index = round(0.0588 * L - 0.296 * S - 15.8);

if (index > 16)
{
    printf("Grade: 16+\n");

}
else if(index < 1)
{
    printf("Before Grade 1\n");

}
else
{
    printf("Grade: %i\n", index);

}


}