#include <stdio.h>
#include <cs50.h>
int main(void)
{
    float troco = get_float("Troco devido em moedas: ");
    float moedas = 0;
    while (troco > 0.95)
    {
        moedas++;
        troco--;
    }
    while ( 0.95  >= troco > 0.45 )
    {
        moedas++;
        troco = (troco-0.50);
    }
    while (  0.45 >= troco > 0.24 )
    {
        moedas++;
        troco = (troco-0.25);
    }
    while (  0.24 >= troco > 0.09 )
    {
        moedas++;
        troco = (troco-0.10);
    }
    while (  0.09 >= troco >= 0.05 )
    {
        moedas++;
        troco = (troco-0.05);
    }

        printf ("%f\n", moedas);



}