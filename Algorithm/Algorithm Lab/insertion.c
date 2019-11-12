#include<stdio.h>

int main(){
int ary[]={3,6,4,2,1,8,7,9,44,20,41};
int j,i,key;
int ary_size=sizeof(ary)/sizeof(int);
for(j=0;j<ary_size;j++){
    printf("%d ",ary[j]);
}



for(j=1;j<=ary_size;j++){
    key=ary[j];
    i=j-1;
    while(i>=0 && ary[i]>key){
        ary[i+1]=ary[i];
        i--;
        ary[i+1]=key;
    }
}
printf(" \n sorted: \n");
for(j=0;j<ary_size;j++){
    printf("%d ",ary[j]);
}



}
