#include <stdio.h>
#include<math.h>
int main(){
    int k,l;
    printf("enter the no. bits of the binary no.");
    scanf("%d%d",&k,&l);
    int bin1[k];
    int bin2[l];
    int no1=0,no2=0;
    int power=k;
    printf("enter the bits:\n");
    for(int i=0;i<k+1;i++){
        scanf("%d",&bin1[i]);
        no1+=(bin1[i]*(pow(2,power)));
        power--;
    }
printf("no1 is:-%d\n",no1);
power=l;
    for(int i=0;i<l+1;i++){
        scanf("%d",&bin2[i]);
          no2+=(bin2[i]*(pow(2,power)));
        power--;
    }
    printf("no2 is:-%d\n",no2);
    printf("sum is:-%d",no1+no2);
    return 0;
}
