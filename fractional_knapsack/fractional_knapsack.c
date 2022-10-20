#include <stdio.h>
void swap(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void knapsack(int num,float weight[],float profit[],float capacity)
{
    int i;
    float cap=capacity;
    float x[num];
    float mp=0.0;
    for( i=0;i<num;i++)
        x[i]=0.0;

    for( i=0;i<num;i++)
    {
        if(weight[i]>cap)
            break;
        else
        {
            x[i]=1.0;
            mp=mp+profit[i];
            cap=cap-weight[i];
        }
    }
    if(i<num)
    {
        x[i]=cap/weight[i];
    }
    mp=mp+(x[i] * profit[i]);
    printf("\nfraction vector for objects:\n");
    for(i=0;i<num;i++)
        printf("%f\n",x[i]);
    printf("\nmaximum profit: %f ",mp);

}

int main()
{
    int num;
    printf("enter the number of objects:");
    scanf("%d",&num);
    float weight[num];
    float profit[num];
    float ratio[num];
    float capacity;
    printf("\nenter weights and profits of each object:\n");
    for(int i=0;i<num;i++)
    {
        scanf("%f %f",&weight[i],&profit[i]);
    }
    printf("\nenter the capacity of knapsack:");
    scanf("%f",&capacity);
    for(int i=0;i<num;i++)
    {
        ratio[i]=profit[i]/weight[i];
    }

    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(ratio[j]>ratio[i])
            {
                swap(&ratio[i],&ratio[j]);
                swap(&weight[i],&weight[j]);
                swap(&profit[i],&profit[j]);
            }
        }
    }
    knapsack(num,weight,profit,capacity);
return 0;
}