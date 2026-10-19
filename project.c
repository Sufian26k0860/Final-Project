//file insertion system 
#include<stdio.h>
#include<errno.h>
#include<string.h>

//PLEASE CHANGE dIRECTORIES WHEN DOWNLOADING TO A NEW SYSTEM
#define sdir "C:/Users/DELL/Downloads/hangman_words_sorted.txt"
#define pdir "C:/Users/DELL/Desktop/temporary_file.txt" //pointer file not temp
void insertion(char inp[],int array[27]);
void pointer(char status,int array[27]);

/*TASKS -> 
            LETTER INSERTION
            RANDOM GEN can be postponed
            */
int main(){

    int breaks[27]={215,1791,8368,22945,44395,66634,84526,
        97640,106446,111570,114491,116068,116767,117123,
        17262,117328,117349,117355,-1,117361,-1,-1,-1,-1,-1,117362};
    int twooplus;
    int temp,i=0;
    char v[30];
    FILE *f;
    f = fopen(sdir,"r");
    if(f==NULL){
        printf("Not work");
        return 0;
    }
    else
        printf("Work\n");
    while(fgets(v,sizeof(v),f)!= NULL){
        if(strlen(v)>temp){
            printf("%d,",i);
            
        }
        i+=1;
        temp = strlen(v);
    insertion("apple",breaks);
        
        
    }
    fclose(f);
    
    


}
void insertion(char inp[],int array[27]){
    int x,i,rg,j=0,k;
    char v[30];
    x = strlen(inp);
    FILE *f,*g;
    f = fopen(sdir,"r");

    }
    



