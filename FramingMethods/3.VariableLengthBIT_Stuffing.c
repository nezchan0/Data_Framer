//3.VariableLengthBIT_Stuffing.c
// bit stuffing and destuffing

#include<stdio.h>
#include<string.h>

int main(){
	char OriginalData[100],StuffedData[100],DeStuffedData[100],flag[9]="01111110";
	int i,j,k,count,ODlen,SDlen,len;
	
	printf("Enter the data to be stuffed: ");
	gets(OriginalData);
	ODlen=strlen(OriginalData); 
	
	strcpy(StuffedData,flag);   // ADD flag in the beginning of the stuffed Data
	//i=0;  'i' is used to navigate the index of OriginalData.
	//j=8;  'j' is used to navigate the index of StuffedData.
	// 		the value of j starts from 8 because 8 bit flag is added in it at the beginning.   
	count=0; // 'count' is used to count the number of consecutive 1's.              
	for(i=0,j=8;i<ODlen;i++){
		if(OriginalData[i]=='1'){
			count++;
		}
		else{
			count = 0;
		}
		StuffedData[j++]=OriginalData[i];
		if(count == 5){
			StuffedData[j++] = '0';
			count = 0;
		}
	}
	StuffedData[j] = '\0';
	strcat( StuffedData, flag); // ADD flag in the end of the stuffed Data 
	
	printf("\nThe data Entered by the user is : %s\n\n",OriginalData);                 
	printf("The data sent by the sender is : %s \n",StuffedData);
	
	
	//DeStuffing
	
	SDlen=strlen(StuffedData);
	
	len=(SDlen-8);
	count=0;
	
	//j=8; and j<(SDlen-8)  'j' is used to navigate the index of StuffedData.
	//						the value of j starts from 8 and ends 8 charaters before as to discard the flag bits.
	//k=0; 	'k' is used to navigate the index of DeStuffedData.			
	for(k=0,j=8;j<(SDlen-8);j++){
		if(StuffedData[j]=='1'){
			count++;
		}
		else{
			count=0;
		}
		DeStuffedData[k++]=StuffedData[j];
		if(count == 5){
			DeStuffedData[k]=StuffedData[j++];
			count=0;
		}
	}
	DeStuffedData[k]='\0';
	
	printf("\nThe data received by the receiver is : %s \n",DeStuffedData);

	return 0;
}
