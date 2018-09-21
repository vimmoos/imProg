/* JSON 
{
    'author':'massimilianoFalzari'
    'studentNumber':'S3459101'
    'date':'September2018'
    'gitRepo':'imperativeProgramming' 
} 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct FermatStruct {
    int base;
    int expo;
    int module;
    int temp;
}FermatStruct;

FermatStruct makeFS (int base,int expo){
    FermatStruct data;
    data.module = expo;
    data.base = base;
    data.expo = expo;
    data.temp = 1;
    return data;
}
//sqroot calculation
int sqroot(int k){
    int x=1;
    if(k==2 || k==3) return x;
    while (x*x<k) x++;
    return x;
}
//calculate whether a number is prime or not 
int prime (int num){
    int tValue = 1;
    int root = sqroot(num);
    // remove the edge case 1,2,3 because their root is 1 
    if( root==1 ) return ( num==1 ? 0 : tValue );
    // remove the even number 
    if(num%2!=0){
        //start from 3 and check all the odd number 
        //if one of them is a divisor of num 
        // change the tValue to 0 and break
        for(int j=3; j<=root ;j+=2){
                if(num%j==0 ) {
                    tValue = 0;
                    break;
                }
        }
    }else tValue=0;
    //return the tValue which could be only 0 or 1 
    return tValue;
}
int modularSpace (FermatStruct *data){
    if(data->expo!=1){
        int tValueA = data->expo%2==0 ? 1 : -1;
        int tValueB = data->base/data->module>=1 ? 1 : 0;
        int Truth = tValueA-tValueB;
        //printf("\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",data->module,data->temp,data->expo,data->base,tValueA,tValueB,Truth);
        switch (Truth){
            case 1: // this is the case when tValueA is true and tValueB is false
                data->expo/=2;
                data->base*=data->base;
                return modularSpace(data);
                break;
            case 0:// this is the case when tValueA is true and tValueB is true 
            case -2://this is the case when tValueA is false and tValueB is true
                data->base%=data->module;
                return modularSpace(data);
                break;
            case -1://this is the case when tValueA is false and tValueB is false
                data->temp*=data->base;
                data->temp%=data->module;
                data->expo-=1;
                return modularSpace(data);
                break;
            default:// this is not possible so if we enter in case,
                    // there must be an error
                printf("error");
                exit(EXIT_FAILURE);
                break;
        }
    }else{
        data->temp*=data->base;
        return data->temp;
    }
}

void runFermat(int num){
    if(prime(num)==1){
        printf("%d is prime.\n",num);
        return;
    }else{
        for (int i=2;i<num;i++){
            FermatStruct data = makeFS(i,num);
            if(modularSpace(&data)%num!=i){
                printf("%d is a witness for %d.\n",i,num);
                return; 
            }
        }
        printf("%d is a Carmichael number.\n",num);
        return;
    }
    
    return;
}

int main (int argc,char** argv){
    int num =0;
    scanf("%d",&num);
    runFermat(num);
    return 0;
}