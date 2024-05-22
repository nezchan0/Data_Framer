// Byte Stuffing With Fixed Length of the Frame

#include<stdio.h>
#include<string.h>

int main(){
	char OriginalData[50],StuffedData[50],DeStuffedData[50];
	int i,j,k,count,FrameSize,DataSize,DataPerFrame,NumberOfFrames,TotalSize,check=0;
	char flag='x';
	
	printf("Enter data: ");
	scanf("%s",OriginalData);
	
	DataSize=strlen(OriginalData);
	
	printf("Enter frame size: ");
	scanf("%d",&FrameSize);
	
	DataPerFrame=FrameSize-2; //each frame contains 2 flag bits
	
	NumberOfFrames=(DataSize / DataPerFrame)+(DataSize % DataPerFrame != 0); // to get division ceil
	// z = x / y + ( x % y != 0 ); z equals ceiling of (x/y)
	
	TotalSize=DataSize+(NumberOfFrames*2); 
	
	count=1; // 'count' is used to count the no. of frames added
	j=0; 	 // 'j' is used to navigate the index of Original Data
	i=0; 	 // 'i' is used to navigate the index of Stuffed Data
	
	for(i=0;i<TotalSize-1;i++){
		if(i%FrameSize==0){ // To add the flag at start of every Frame
			StuffedData[i]=flag;
		}
		else if(i==(FrameSize*count)-1){ // To add the flag at the end of every Frame
			StuffedData[i]=flag;
			count++;
		}
		else{
			StuffedData[i]=OriginalData[j];
			j++;
		}
	}
	StuffedData[TotalSize-1]=flag; // Adding flag to the last position of last frame
	StuffedData[TotalSize]='\0';
	
	//Displaying the StuffedData as Sent by the Sender
	printf("\nThe stuffed data is: %s \n",StuffedData);
	printf("\n|Per Frame View|\n");
	for(i=0;i<TotalSize;i++){
		printf("%c ",StuffedData[i]);
		if((i+1)%FrameSize==0){
			printf("\n");
		}
	}
	
	// Destuffing
	
	k=0; // 'k' is used to navigate the index of DeStuffed Data
	for(i=0;i<TotalSize;i++){
		if(StuffedData[i]!='x'){
			DeStuffedData[k]=StuffedData[i];
			k++;
		}
	}
	DeStuffedData[k]='\0';
	
	//Displaying the DeStuffedData as Received by the Reciever
	printf("\n\nDestuffed data is : %s",DeStuffedData);
	
	return 0;
}
