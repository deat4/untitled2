#include <stdio.h>
#include <string.h>


char s[20];
int b[20];
int length;
int finda(int a){
    int i;
    for(i=0;i<length;i++){
        if(b[i]==a)
            return 1;
    }
    return 0;
}
int findflag(int a){
    int flag=1;
    while(a){//取出各个位置的数字 
        flag&=finda(a%10);
        a/=10;
    }
    return flag;
}
int main(){
    int i,j,k,m,n;
    int x,y,z;
    int flag;
    int count=0;
    int cnt =0;
    while (  scanf("%s",s)!=EOF)
    {

        printf("CASE #%d\n",cnt);
        length=strlen(s);
        for(i=0;i<length;i++)//字符串字母转换成数字
            b[i]=s[i]-'0';
        for(i=0;i<length;i++){//被乘数百位数
            if(b[i]!=0){//被乘数百位数不能为零
                for(j=0;j<length;j++){//被乘数十位数
                    for(k=0;k<length;k++){//被乘数个位数
                        for(m=0;m<length;m++){//乘数十位数
                            if(b[m]!=0){//乘数十位数不能为零
                                for(n=0;n<length;n++){//乘数个位数
                                    flag=1;
                                    x=(b[i]*100+b[j]*10+b[k])*b[n];
                                    y=(b[i]*100+b[j]*10+b[k])*b[m];
                                    z=(b[i]*100+b[j]*10+b[k])*(b[m]*10+b[n]);
                                    flag&=findflag(x)&findflag(y)&findflag(z);

                                    if(flag){
                                        count++;
                                        printf("<%d>\n",count);
                                        printf("%5d\n",(b[i]*100+b[j]*10+b[k]));
                                        printf("X%4d\n",(b[m]*10+b[n]));
                                        printf("-----\n");
                                        printf("%5d\n",x);
                                        printf("%4d\n",y);
                                        printf("-----\n");
                                        printf("%5d\n",z);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("The number of solutions = %d\n",count);
    }
    return 0;
}
