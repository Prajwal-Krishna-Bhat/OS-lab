#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
void main(){
    int k=0,a=0,b=0,instance[5],availability[5],allocated[10][5],need[10][5],max[10][5],process,P[10],resources,cnt=0,i,j,op[10];
    printf("\nenter no of resources:");
    scanf("%d",&resources);
    printf("Enter the max instances in each resources:");
    for(i=0;i<resources;i++){
        availability[i]=0;
        printf("%c=",(i+97));
        scanf("%d",&instance[i]);
    }
    printf("Enter the no of processes:");
    scanf("%d",&process);
    printf("\n Enter the allocation matrix\n");
    for(i=0;i<resources;i++){
        printf("%c",(i+97));
        printf("\n");
    }
    for(i=0;i<process;i++){
        P[i]=i;
        printf("P[%d]",P[i]);
        for(j=0;j<resources;j++){
            scanf("%d",&allocated[i][j]);
            availability[j]+=allocated[i][j];
        }
    }
    printf("\nEnter the MAX matrix\n");
    for(i=0;i<resources;i++){
        printf("%c",(i+97));
        availability[i]=instance[i]-availability[i];
    }
    printf("\n");
    for (int i = 0; i < process; i++)
    {
        printf("P[%d] ",i);
        for (int j = 0; j < resources; j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("\n");
    A:a=-1;
    for(i=0;i<process;i++){
        cnt=0;
        b=P[i];
        for(j=0;j<resources;j++){
            need[b][j]=max[b][j]-allocated[b][j];
            if(need[b][j]<=availability[j]){
                cnt++;
            }
        }
        if(cnt==resources){
            op[k++]=P[i];
            for(j=0;j<resources;j++){
                availability[j]+=allocated[b][j];
            }
        }
        else{
            P[++a]=P[i];
        }
    }
    if(a!=-1){
        process=a+1;
        goto A;
    }
    printf("<");
    for(i=0;i<k;i++){
        printf("P[%d]",op[i]);
        printf(">");
    }
    getchar();
}
/*enter no of resources:3
Enter the max instances in each resources:a=10
b=5
c=7
Enter the no of processes:5

 Enter the allocation matrix
a
b
c
P[0]0 1 0
P[1]2 0 0
P[2]3 0 2
P[3]2 1 1
P[4]0 0 2

Enter the MAX matrix
abc
P[0] 7 5 3
P[1] 3 2 2
P[2] 9 0 2
P[3] 2 2 2
P[4] 4 3 3

        <P[1]>P[3]>P[4]>P[0]>P[2]>*/