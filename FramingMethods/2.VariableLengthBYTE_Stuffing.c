//2.VariableLengthBYTE_Stuffing.c
// Byte oriented Variable Size framing

#include <stdio.h>
#include <string.h>

void main()
{
	int i,j,k,n,m;
    char StuffedData[50][50], OriginalData[50][50], DeStuffedData[50][50];
    
    char flag[10],esc[10];
    printf("Enter the FLAG and ESC value: ");
    scanf("%s%s",flag,esc);
    
    printf("Enter Data length in the Payload : ");
    scanf("%d", &n);
    
    printf("\nEnter the Data in the Payload\n");
    for (i = 0; i <n; i++) {
        scanf("%s",OriginalData[i]);
    }
    
    printf("\nData entered by the sender is : ");
    for (i = 0; i <n; i++){
        printf("'%s' ",OriginalData[i]);
    }
   
   	i=0; //	'i' is used to navigate the index for OriginalData
    j=0; // 'j' is used to navigate the index for StuffedData
    
    strcpy(StuffedData[j++],flag); // Adding the FLAG in the begining of Frame
    
    for (i = 0; i < n; i++){	
        if (strcmp(OriginalData[i], flag) != 0 && strcmp(OriginalData[i], esc) != 0){
            strcpy(StuffedData[j++], OriginalData[i]);
        }
        else{
            strcpy(StuffedData[j++], esc); // Adding ESC sequence before FLAG and ESC value in DATA
            strcpy(StuffedData[j++], OriginalData[i]);
        }
    }
    strcpy(StuffedData[j++], flag); // Adding the FLAG in the End of Frame
    m=j;  // Storing the size of StuffedData in 'm' 
    
    
    printf("\n\nData sent from the sender's side:  ");
    
    for (i = 0; i < m; i++)
    {
        printf("%s  ", StuffedData[i]);
    }
    
    
    // destuffing
    
    j=1; // 'j' is used to navigate the index for StuffedData
    k=0; // 'k' is used to navigate the index for DeStuffedData
    
    for(j=1;j<(m-1);j++){
    	if(strcmp(StuffedData[j],esc)==0){
    		j++;
		}	
		strcpy(DeStuffedData[k++], StuffedData[j]);
	}
	
    printf("\n\nData recieved on the reciever's side:  ");
    
    for (i = 0; i < k; i++){
        printf("'%s' ", DeStuffedData[i]);
    }  
}




