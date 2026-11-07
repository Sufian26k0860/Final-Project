//file insertion system 
#include<stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
#include<time.h>
//errno a CHUD 
// 2 weeks later, might remove it
// toooujee fushigeeyo




//PLEASE CHANGE dIRECTORIES WHEN DOWNLOADING TO A NEW SYSTEM
#define sdir "C:/Users/DELL/Downloads/hangman_words_sorted.txt" //the GOAT //will be sent
#define tdir "C:/Users/DELL/Desktop/temporary_file.txt" //test file otherwise if ignored code SHOULDNT break // just initialize an empty txt file
#define pdir "C:/Users/DELL/Desktop/pointer.txt" // fodder file for now //update: it IS fodder //ignore this




void insertion(char inp[],int array[28]);
void pointer(char status,int array[28]);
int binarysearch(char inp[],int lower,int upper,char arr[][30],int *bub); // not exact bin searcg
void strain(char (*array)[30],int position,char letter,int blacklist[], int *num,int *start);
void read(char (*array)[30]);
void response(char (*array)[30],int blacklist[],int num);




/*TASKS -> 
            input
            RANDOM GEN can be postponed and is easy
            */
int main(){
    int blacklist[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int breaks[28]={215,1791,8368,22945,44395,66634,84526,
        97640,106446,111570,114491,116068,116767,117123,
        117262,117328,117349,117355,-1,117361,-1,-1,-1,-1,0,117362};
    int twooplus;
    int temp,i=0;
    char v[30];
    char (*therray)[30] = malloc(150000*sizeof(char[30]));
    int p = breaks[2];
    int q = breaks[1];
    read(therray);
    strain(therray,-1,'p',blacklist,&p,&q);
    printf("%d",p);
    FILE *f;
    f = fopen(sdir,"r");
    if(f==NULL){
        printf("Not work");
        return 0;
    }
    else
        printf("Work\n");
    
    

    fclose(f);
    free(therray);
    


}
void insertion(char inp[],int array[28]){ // five.hundred.functions
    int x,i=0,rg,j=0,k,dex=0;
    char v[30];
    char (*charray)[30] = malloc(150000*sizeof(char[30]));
    char (*charray2)[30] =malloc(150000*sizeof(char[30]));
    x = strlen(inp);
    FILE *f,*g;
    f = fopen(sdir,"r");
    while(fgets(charray[i],30,f)!=NULL){
        i+=1;
    }
    j=i;
    int lower=0,upper;
    if(strlen(inp)-3==-1){
        lower = 0;
        upper = array[strlen(inp)-2];
    }
    upper = array[strlen(inp)-2];    
    lower = array[strlen(inp)-3];    
    binarysearch(inp,lower,upper,charray,&dex);
    for(i=0;i<=dex;i++){
        strcpy(charray2[i],charray[i]);
    }
    
    sprintf(charray2[i],"%s\n",inp); 
    
    i++;
    for(;i<=j;i++){
       strcpy(charray2[i],charray[i]); 
    }
    g =fopen(tdir,"w");
    for(i=0;i<=j;i++){
        fprintf(g,"%s",charray2[i]);
    }
    pointer('r',array);
    printf("%d\n",dex);
    free(charray);
    free(charray2);
    fclose(f);
    fclose(g);

}
int binarysearch(char inp[],int lower,int upper,char arr[][30],int *bub){//perfect
    int mid;
    
    mid = lower + (upper-lower)/2;
    if((upper-lower)==1){
        *bub = lower;
        printf("Standard\n");
        return mid;
        
    }
    else if( upper-lower==-1){
        *bub = lower;
        printf("Inverted\n");
        return mid;
         
    }
    else if(upper==lower){
        *bub = lower;
        printf("Equal\n");
        return mid;
         
    }
    else if(strcmp(arr[mid],inp)>0){
            return binarysearch(inp,lower,mid-1,arr,bub);
        }
    else{
        return binarysearch(inp,mid+1,upper,arr,bub);
    }
    
}
void pointer(char status,int array[28]){
    char (*charray)[30] = malloc(150000*sizeof(char[30]));
    FILE *f;
    int i=0,j,prray[28],k=0;
    f = fopen(sdir,"r");
    if(status=='r'){
    while(fgets(charray[i],30,f)!=NULL){
        i++;
    }
    strcpy(charray[i+1],"");
    for(j=0;j<i;j++){
        if(strlen(charray[j])<strlen(charray[j+1])){
            printf("Met\n");
            k=strlen(charray[j])-3;
            array[k]=j;
            
            
        }
    }
    free(charray);
    fclose(f);
}

}
void strain(char (*array)[30], int position,char letter,int blacklist[],int *num,int *start){
    letter = toupper(letter);
    int al = letter;
    int i=0,j=0;
    char (*charray)[30] = malloc(100000 * sizeof(char[30]));
    char *res;
    char temp;
    
    if(position==-1){
        
        for(i=*start ;i<*num;i++){
            res = strchr(array[i],letter);
            if(res==NULL){
                array[i][strcspn(array[i],"\n")] = '\0';
                strcpy(charray[j],array[i]);
                j++;
            }

        }
        *num = j;
        for(i=0;i<j;i++){
            printf("%s\n",charray[i]);
            strcpy(array[i],charray[i]);
        }
    }
    else{
        blacklist[position-1]=-1;
        for(i=*start;i<*num;i++){
        temp = array[i][position-1];
        temp = toupper(temp);
        if(temp==letter){
            array[i][strcspn(array[i],"\n")] = '\0';
            strcpy(charray[j],array[i]);
            j++;
        }
    }
        *num = j;
        for(i=0;i<j;i++){
            printf("%s\n",charray[i]);
            strcpy(array[i],charray[i]);
        }
    }
    free(charray);
}
void read(char (*array)[30]){
    FILE *f; int i=0; char buffer[30];
    f = fopen(sdir,"r"); 
    while(fgets(buffer,30,f)!=NULL){
        
            strcpy(array[i],buffer);
            i++;
        
    }
    fclose(f);
}
char guesser(int blacklist_pos[30],int blacklist_letter[26],char (*array)[30],int num,int size){
    int score[26],i,j,k,ran;
    char t,q;
     for(i=0;i<26;i++){
        score[i]=0;
     }
     k=0;
    for(i=0;i<num;i++){
        t=array[i][j];
        t = toupper(t);
        for(j=0;j<size;j++){
        if(blacklist_pos[j]!=-1){
        
        if(t>='A' && t<='Z'){
        if(blacklist_letter[t-65]!=-1){
            score[t-65] += 1;
        }
        }
        }
        }
    }
    for(i=0;i<26;i++){
        if(i<10){
            score[i] *=2;
        }
        else if(i>10 && i<15)
        {
            score[i] *=1.5;
        }
    
        k += score[i];
    }
    srand(time(NULL));
    ran = rand()%k;
    for(i=0;i<26;i++){
        if(ran<score[i]){
            q = i+65;
            printf("%c",q);
            return q;
            break;
        }
        ran -= score[i];
    }
    return '.';
}
