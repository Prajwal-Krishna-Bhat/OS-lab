#include<stdio.h>
#include<stdlib.h>
void main(){
    int i,n,req[50],mov=0,cp;
    printf("Enter the current position:");
    scanf("%d",&cp);
    printf("Enter the no of requests:");
    scanf("%d",&n);
    printf("Enter the request order:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    mov+=abs(cp-req[0]);
    printf("%d->%d",cp,req[0]);
    for(i=1;i<n;i++){
        mov+=abs(req[i]-req[i-1]);
        printf("->%d",req[i]);
    }
    printf("\n");
    printf("total head movement=%d\n",mov);
}
/*Enter the current position:45
Enter the no of requests:5
Enter the request order:
30
66
24
75
50
45->30->66->24->75->50
total head movement=169*/