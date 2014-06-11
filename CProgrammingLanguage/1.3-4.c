#include <stdio.h>

/*A program that first displays Fahrenheit 
  converted to Celsius then Celsius to 
  Fahrenheit*/

int main()
{
  printf("Exercise 1.3\n");
  
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  
  printf("Fahr\tCelsius\n");
  while(fahr <= upper)
    {
      celsius = 5 * (fahr-32) / 9;
      printf("%3d\t%3d\n", fahr, celsius);
      fahr = fahr + step;
    }

  printf("Exercise 1.4\n");
  
  celsius = lower;

  printf("Celsius\tFahr\n");
  while(celsius <= upper)
    {
      fahr = celsius * 9.0 / 5.0 + 32;
      printf("%3d\t%3d\n", celsius, fahr);
      celsius = celsius + step;
    }

  return 0;
}
