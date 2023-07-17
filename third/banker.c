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
    for ( i = 0; i < process; i++)
    {
        cnt=0;
        b=P[i];
        for ( j = 0; j < resources; j++)
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
    printf("\t<");
    for(i=0;i<k;i++){
        printf("P[%d]",op[i]);
        printf(">");
    }
    getchar();
}