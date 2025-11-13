#include<stdio.h>
#include <conio.h>
#include <math.h>
int sum(int,int);
double area_of_Circle(int);
int Odd_even_checker(int);
int fact(int);
int combination(int,int);
int max_of_four(int,int,int,int);
int Prime(int);
void printPrime(int,int);
int nextPrime(int);
int sum_Array(int,int[]);
int greatest_Index(int,int[]);
void rotate_arr(int size,int a[],int shift);
void Updated_rotate(int,int[]);
void Number_of_rotate(int,int[],int);
void Insertion_sort(int,int[]);
void insertion_sort(int,int[]);
void calculate_freq_of_distinct_element(int,int[]);
int length_string(char[]);
void reverse_string(int,char[]);
void upperCase(char[]);
void swap(int*,int*);
int Binary_search(int,int[],int);

struct Employee
{
    //Learning
    int empid,salary;
    char name[20];
};


int main(){ 
     int a,b;
     printf("Enter the two number:");
     scanf("%d %d",&a,&b);
     printf("a:%d, b:%d",a,b);
     swap(&a,&b);
     printf("\na:%d, b:%d",a,b);
}

int Binary_search(int size,int arr[],int tar){
    int st=0,end=size-1,mid;

    while(st<=end){
         mid=st+(end-st)/2;

         if(tar>arr[mid]){
             st=mid+1;
         }else if(tar<arr[mid]){
            end=mid-1;
         }else 
         { 
            return mid;
         }  
    }
    return -1;
}

void swap(int *a,int *b){
   int temp;
   temp=*a;
   *a=*b;
   *b=temp;
}

void upperCase(char str[]){
    for(int i=0;str[i];i++){
         if(str[i]>=97){
             str[i]=str[i]-32;
         }
    }
}

void reverse_string(int size,char str[]){
     char temp[size];
     for(int i=size-1,j=0;i>=0;i--,j++)
         temp[j]=str[i];

     for(int i=0;i<size;i++)
         str[i]=temp[i];
}

int length_string(char str[]){
     int i;
     for(i=0;str[i];i++);
     return i;
}

void calculate_freq_of_distinct_element(int size,int a[]){
     int uniq[10]={0};
     int i,j,sum,k,lock; 
     int count=0; 

     for(i=0;i<size;i++){ 
          lock=0;
          for(k=0;k<count;k++){
              if(uniq[k]==a[i]){
                 lock=1;
              }
          }
          if(lock){
            continue;
          }
          sum=1;

          for(j=i+1;j<size;j++){
              if(a[i]==a[j]){
                sum++;
              }
          } 
          printf("%d=%d\n",a[i],sum);
          uniq[count++]=a[i];
     }

}

void insertion_sort(int size,int a[]){
     int i,j,temp;
     for(i=1;i<size;i++){
         temp=a[i];

         for(j=i-1;j>=0;j--){
              if(a[j]>temp)
                 a[j+1]=a[j];
              else
                break;
         }
         a[j+1]=temp;
     }
}

void Insertion_sort(int size,int a[]){
     int temp;
     for(int i=0;i<=size-2;i++){
          
          if(a[i]>a[i+1]){
              temp=a[i+1];
              a[i+1]=a[i];
              a[i]=temp;
                
           for(int j=i;j;j--){
               if(a[j]<a[j-1]){
                temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
               }
           }
         } 
   }
}

void Number_of_rotate(int size,int a[],int shift){

    while (shift--)
        Updated_rotate(size,a);
}
void Updated_rotate(int size,int a[]){
    int spare=a[size-1];
    for(int i=size-1;i>0;i--)
       a[i]=a[i-1];

    a[0]=spare;
    
}
void rotate_arr(int size,int a[],int shift){
    int spare[shift],spi=0,j;
    int i=size-shift;
    
    //Allocate the elment that to be shifted
    for(;i<size;i++,spi++){
         spare[spi]=a[i];
    }
    
    //loop to handle number of shift 
    for(int l=1;l<=shift;l++){
        //loop to shift the element
        for(j=size-1;j>0;j--){
            a[j]=a[j-1];
        }
    }
   
    //Adding the removed element
    for(j=0,i=0;j<shift;j++){
        a[j]=spare[j];
    }
    
    //Print the array
    for(int k=0;k<size;k++){
         printf("%d ",a[k]);
    }

}

int greatest_Index(int size,int a[]){
    int max=0,index;
    for(int i=0;i<size;i++){
         if(max<a[i]){
            index=i;
            max=a[i];
         }
    } 
    return index;
}

int sum_Array(int size,int a[]){
     int sum=0;
     for(int i=0;i<=size-1;i++){
        sum=sum+a[i];
     }
     return sum;
}

int Prime(int x){
     int s;
     s=sqrt(x); 
     for(int i=2;i<=s;i++){
         if(x%i==0){
            return 0;
         }
     }
     
    return 1;
}

void printPrime(int a,int b){
    for(int i=a;i<=b;i++)
        if(Prime(i))
           printf("%d ",i);
}

int nextPrime(int x){  

  while(!Prime(++x));
  return x;
}
int max_of_four(int a,int b,int c,int d){
      if(a>b){
         if(a>c){
             if(a>d){
                 return a;
             }else{
                return d;
             }
         }
      }else{
          if(b>c){
              if(b>d){
                return b;
              }else{
                return d;
              }
          }
      }
       if(c>d){
            return c;
         }else{
            return d;
         }
}

int combination(int n,int r){
   return fact(n)/fact(n-r)/fact(r);
}

int fact(int a){
    int sum=1;
    for(;a;a--){
         sum=sum*a;
    }

    return sum;
}

int Odd_even_checker(int x){

    return x%2==0?1:0;
}
double area_of_Circle(int r){
    float PI=3.14,area;
    area=PI*r*r;
    return area;
}

int sum(int a,int b){
    return a+b;
}