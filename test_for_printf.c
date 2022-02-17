#include <stdio.h>
#include "ft_printf.h"

void ft_float(float myfloat)
{
  //double myfloat;
  signed long int decipart;
  signed long int intpart;

  //myfloat = va_arg(*ap, double);
  if (myfloat < 0)
  {
      ft_putchar('-');
      myfloat *= -1;
  }
  intpart = (signed long int)myfloat;
  ft_putnbr(intpart);
  ft_putchar('.');
  myfloat -= intpart;
  myfloat *= 1000000;  //upto 6 decimal points
  decipart = (signed long int)(myfloat + 0.5); //+0.5 to round of the value
  ft_putnbr(decipart);
}

int main(void)
{
	ft_float(11.0);
	printf("\n%.0f\n", 11.0);
}