#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

mpz_t s,q,p,r;
unsigned long  k,n;

int main()
{
printf("Enter number you want to test for primality :");
scanf("%lu",&n);

if(n==9)
{
printf("%lu is composite\n" , n);
}
else
{

mpz_init(p);
mpz_init(q);
mpz_init(s);
mpz_init(r);

mpz_set_ui(s,0);

mpz_ui_pow_ui(q,2,n);
mpz_sub_ui(q,q,1);

for(k = 1; k <= n-1; k++)
{
mpz_ui_pow_ui(p,2,k);
mpz_sub_ui(p,p,1);
mpz_powm_ui(r,p,n-1,q);
mpz_add(s,s,r);
}

mpz_mod(s,s,q);

mpz_clear(p);
mpz_clear(q);
mpz_clear(r);

if(mpz_cmp_ui(s,n)==0)
{
printf("%lu is prime\n" , n);
}
else
{
printf("%lu is composite\n" , n);
}
mpz_clear(s);
}

return 0;
}