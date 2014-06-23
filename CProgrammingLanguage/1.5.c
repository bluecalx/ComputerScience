#include <stdio.h>

/*A program using a for loop to 
  print a conversion chart 
  between fahrenheit and celsius */

int main(void)
{
  int fahr;

  printf("Fahr\tCelsius\n");
  for(fahr = 300; fahr > 0; fahr = fahr - 20)
    {
      printf("%3d\t%.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
  return 0;
}
