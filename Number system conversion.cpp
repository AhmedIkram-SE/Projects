#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<windows.h>

using namespace std;
int comp(int a, int b){
	
	int i=0,quotient,result;
	
	quotient=a;
	while(quotient!=0){
		
		quotient=quotient/10;
		i++;		
	}
	result=pow(b,i)-1-a;
	return result;
}
void BC(char string1[],char string2[], int b){
	int i=0;
	while(i<=b)
	{
	if(string1[i]=='1'){
		string2[i]='0';}
	if(string1[i]=='0'){
		string2[i]='1';}		
	i++;
	}
	cout<<"\n-->The complement of 1st binary number is:"<<string2<<"\n\n";
	
	
}
void compliment1(int a[],int size){
	int x,i;
	for(i=0;i<=size;i++){
		
		if(a[i]==1){
			a[i]=0;
		}
		if(a[i]==0){
			a[i]=1;
		}
	}
	
}
int power(int n, int b) {	/*Function created for power*/

	int power=1;
	int i;

	for(i=1; i<=b; i++) {
		power=power*n;
	}

	return power;
}

int main(){
		system("color b0");
		cout<<"\n\t\t\t\t\t***\t   ICT Project   \t***\n\n\t\t\t\t\t***\t     Group K\t\t***\n\n\t\t\t\t\t***\t  Group Members\t\t***\n\n\t\t\t\t\t->SP22-BSE-062 (M. AHMAD IKRAM)<-\n\t\t\t\t\t->SP22-BSE-066 (MUHAMMAD SAUD)<-\n\n";	
		cout<<"\n\t\t\t\t\t***\t   Number Systems:  \t***\n\n\t\t\t\t\t";
	
	
	int option,i;
	char array[500]="\n\n\t\t\t\t\tPress 1 for ANY base To Base: \n\t\t\t\t\tPress 2 for Shortcut Method: \n\t\t\t\t\tPress 3 for Addition of Binary Numbers: \n\t\t\t\t\tPress 4 for Subtraction of Two Binary Numbers Using Complimenteary Method: \n\t\t\t\t\tPress 5 Subtraction of Two numbers Using Complimentary Method: ";
	
	for(i=0;i<267;i++){
		printf("%c",array[i]);
		//usleep(2700);
	}
	cin>>option;
	
	switch(option){
		
		case 1 :{
		int opt,len=0;
		unsigned long long number,character;  /*Using unsigned long long data type, because the value of number input by the user can exceed the limit of int data type.*/
		int decimal=0; 			 /*Assigning value 0 to this variable, because its value is going to be increased in the loop .*/
		int LD,answer,i,j;   /*LD stands for last digit*/
		int base,base1;
		int remain,temp,rem;					/*Initilaize The variables*/
		char remainder[100];		/*This is the array size for remainder variable*/
		char hex[100];
		int checker[100];			/*This is the array size for characters of hexadecimal*/
	cout<<"\n\n-->Press 1 for Any Base [Except Hexa] to Any Base [Including Hexa] or 2 for Hexadecimal to Any Base : ";	/*If user presses 1 number will be converted from binary to decimal and if presses 0 number will be converted from decimal to any number.*/
	cin>>opt;

		
	
	switch(opt) {	/*Using Switch for decision.*/
		case 1: {	/*any number to decimal*/
			start:
			
			cout<<"\n-->Enter A Number of any Base Except of Base 16 : ";	/*Take the number from the user.*/
			cin>>number;	/*Store the number*/
			cout<<"\n-->Enter the base of the entered number [2 for binary, 10 for decimal and 8 for Octal] : ";	/*Get the base for the entered number.*/
			cin>>base1;	/*Store that base.*/
			temp=number;
			
			for(i=0;temp!=0;i++){//Storing the number in checker array//
				checker[i]=temp%10;
				temp=temp/10;
			}
			if(base1==2){//Checker For Binary number//
			for(j=0;j<i;j++){
				if(checker[j]> 1 && checker[j]> 0){
					cout<<"Invalid Number!";
					goto start;	
				}
				}	
		}
			if(base1==10){//Checker for Decimal Number//
			for(j=0;j<i;j++){
				if(checker[j]> 9){
					cout<<"Invalid Number!";
					goto start;	
				}
				}	
		}
			if(base1==8){//Checker For Octal Number//
			for(j=0;j<i;j++){
				if(checker[j]> 8){
					cout<<"Invalid Number!";
					goto start;	
				}
				}	
		}
			
			
			cout<<"\n-->Enter the base you want to convert in: ";
			cin>>base;	/*Store the base.*/
			
			for(i=0 ; number!=0; i++) { /*We will use for loop to calculate the decimal value.*/
				LD=number%10;   				/*It will give us the last digit of the number.*/
				answer=LD*power(base1,i);   /*Formula To calculate value.*/ /*(power) function is called here*/
				decimal=decimal+answer;    /*Decimal Value will be stored in this variable.*/
				number=number/10;   				/*This will reduce the value of number by 1 digit.*/
			}

			cout<<"\n-->The Number in decimal form is : "<<decimal<<" ";	 /*It will display the calculated value after the loop.*/
		
		
			for(i=0; decimal!=0; i++) {	/*We will use loop to calculate the remainder and the quotient.Loop will continue untill the value of decimal number becomes 0.*/
				remainder[i]=decimal%base; /*Here the value of first remainder will be stored in the i index of the array,which is 0 as stated in the loop statement.*/
				character='0'+remainder[i];
				if(character>'9')
				character+=7;
				remainder[i]=character;			/*As the lopp continues the value of index will be updated till number becomes 0.*/
				decimal=decimal/base;		/*This will give us the quotient whose value will be stored in the number variable.*/
			}

			cout<<"\n-->The number form base "<<base1<<" to base "<<base<<" is : ";

			for(j=i; j!=0; j--)	/*Here we will print the value of remainder in the correct order using loop.The value of the counter variable(j) is equals to i from the previous loop, which will be eqauls to total itterations.
							loop will continue until value of j becomes 0.*/
			{
				cout<<""<<remainder[j-1]<<"";	/*It will print the values stored on the array index, which are remainders.*/
			}
		break;
		}
		case 2:{	
	
		i=0;	
		cout<<"\n\n-->Enter any Hexadecimal Number: "; /*Get the hexadecimal number from the user.*/
	    cin>>hex; /*Store the hexadecimal number in a variable.*/
	    cout<<"\n\n-->Enter the base you want to convert in: ";
		cin>>base;	/*Store the base.*/
		while(hex[i]!='\0')	/*We will count length of character array hexnum[] (given hexadecimal number) using while loop.*/
		{
	        len++;
	        i++;
	    }
	    len--; /*Decrese the value of length varuable by 1 because it holds value (1), but array starts at 0.*/
	    i=0;	
		while(len>=0)
	    {
        remain = hex[len];
        if(remain>=48 && remain<=57)
            remain = remain-48;
        else if(remain>=65 && remain<=70)/*Using ASCII values to evaluate hexadecimal number*/
            remain = remain-55;
        else if(remain>=97 && remain<=102)
            remain = remain-87;
        else
        {
            cout<<"\n-->You've entered an invalid Hexadecimal digit";
            getchar();
            return 0;
        }
        decimal = decimal + (remain*power(16, i));	/*Formula to calculate decimal number.*/
        len--;
        i++;
   		 }
    cout<<"\n-->The Number in Decimal Value = "<<decimal<<" ";	/*Display the value of decimal number.*/
    
	for(i=0; decimal!=0; i++) {	/*We will use loop to calculate the remainder and the quotient.Loop will continue untill the value of decimal number becomes 0.*/
				remainder[i]=decimal%base; /*Here the value of first remainder will be stored in the i index of the array,which is 0 as stated in the loop statement.*/
				character='0'+remainder[i];
				if(character>'9')
				character+=7;
				remainder[i]=character;						//	As the lopp continues the value of index will be updated till number becomes 0.*/
				decimal=decimal/base;		/*This will give us the quotient whose value will be stored in the number variable.*/
			}

			cout<<"\n-->The number form base 16 to base "<<base<<" is : ";

			for(j=i; j!=0; j--)	/*Here we will print the value of remainder in the correct order using loop.The value of the counter variable(j) is equals to i from the previous loop, which will be eqauls to total itterations.
							loop will continue until value of j becomes 0.*/
			{
				cout<<""<<remainder[j-1]<<"";	/*It will print the values stored on the array index, which are remainders.*/
			}

	cout<<"\n";
	
	return 0;
	break;
}
}
}
	break;
	case 2:{
		int i,n,j,k,m,l,LTD,LD,TD,temp,rem,reverse=0,answer,base1,op,checker[20],temp1;	
	int sum=0;
	int answer1[100];	/*Intialize Variables*/
	int remainder[100];	/*Intialize arrays with their sizes.*/
	int answer2[3];
start2:
	cout<< "\n\n-->Enter a binary or a octal number: ";/*Get the input number from the user.*/
	cin>> n;
	temp1=n;			  /*Store it in a variable.*/
	cout<<"\n-->Enter the base of the number: ";/*Get the base of the number from the user.*/
	cin>>base1;/*Store the base in a variable.*/
			for(m=0;temp1!=0;m++){//Storing the number in checker array//
				checker[m]=temp1%10;
				temp1=temp1/10;
			}
			if(base1==2){//Checker For Binary number//
			for(l=0;l<m;l++){
				if(checker[l]> 1 && checker[l]> 0){
					cout<<"Invalid Number!";
					goto start2;	}	}}	
		
		
			if(base1==8){//Checker For Octal Number//
			for(l=0;l<m;l++){
				if(checker[l]> 8){
					cout<<"Invalid Number!";
					goto start2;	
				}
				}		
			}
	cout<<"\n-->Enter 1 for Binary to Octal and 0 for Octal to Binary..";/*Ask the user to press specific number for conversion of numbers.*/
	cin>>op;/*Store the choice in a variable, which will be used in the switch.*/

	switch(op) {
		case 1: {/*Binary to Octal using "Shortcut Method".*/

			for(i=0 ; n!=0 ; i++) {/*The outer for loop will divide the number into number of three bits.*/
				LTD=n%1000;/*This function wuill give us last three digits.*/
				for(j=0; LTD!=0; j++) {/*The inner loop will convert the three aquired numbers in octal form and add them.*/
					TD=LTD%10;
					answer=TD*power(base1,j);/*Power function is used here.*/
					sum=sum+answer;
					LTD=LTD/10;
				}
				answer1[i]=sum;/*The sum of numbers is stored in this array.*/
				n=n/1000;/*This will give us the remaining quotient of the number.*/
				sum=0;
			}
			cout<<"-->The Binary Number in Octal form is ";
			for(k=i; k!=0; k--)
				cout<< answer1[k-1];/*Disply the octal number.*/
		}
		break;

		case 0: {/*Octal to Binary using "Shortcut Method".*/
			cout<<"-->The Octal Number in Binary Form is ";
			while(n!=0) {/*This loop will reverse the enterd number.*/
				rem=n%10;
				reverse=reverse*10+rem;
				n/=10;
			}
			for(i=0; reverse!=0; i++) {/*This outer loop will give us the last digit of the octal number.*/
				LD=reverse%10;/*Last digit functin.*/

				for(j=0; LD!=0; j++) {/*This loop will calculate the binary number of the last digit obtained.*/
					remainder[j]=LD%2;/*Binary number (remiander) is stored in the this array.*/
					LD=LD/2;
				}
				if(j==3) {/*If the last digit causes the loop iterations to be 3, the binary number will obtain all the 3 bits size of array.*/
					for(k=0; k<3; k++) {/*This loop will store the binary number in the answer array, which size is 3 bits.*/
						answer2[k] = remainder[k];/*Binary number is being stored in answer array.*/
					}
					temp=answer2[0]; 
					answer2[0]=answer2[2];/*This is to swap the values inside the array.*/
					answer2[2]=temp;
				}

				if(j<3) {/*If the last digit causes the loop iterations to be less than 3,then we will get a 2 digit binary number while the the first bit place will be aqiured by zero.*/
					answer2[2] = remainder[0];
					answer2[1] = remainder[1];
					answer2[0] = 0;

					if(j<2) {/*If the last digit causes the loop iterations to be less than 2,then we will get a 1 digit binary number while the the first and secon bit place will be aqiured by zero.*/
						answer2[2] = remainder[0];
						answer2[1] = 0;
						answer2[0] = 0;
					}
				}
				for(i=0; i<3; i++) {/*Dsplay the binary numbers stored in the array till we get the entered octal number eqaul to zero.*/
					cout<< answer2[i];
				}

				reverse=reverse/10;/*This will give us the remaining numbers after ruling out the lst digit.*/
			}
		}
		break;
	}
		
		break;
	}
	case 3:{
		
		long int binary1, binary2;
    int i = 0, rem = 0, sum[20],checker[20],temp,j,k;
    start1:
    // Asking for Input
    cout<<"\n\n-->Enter first binary number: ";
    cin>>binary1;
    temp=binary1;
			for(k=0;temp!=0;k++){//Storing the number in checker array//
				checker[k]=temp%10;
				temp=temp/10;
			}					//Checker For Binary number//
			for(j=0;j<k;j++){
				if(checker[j]> 1 && checker[j]> 0){
					cout<<"Invalid Number!";
					goto start1;						}
				}
    cout<<"-->Enter second binary number: ";
    cin>>binary2;
    
    while (binary1 != 0 || binary2 != 0){
        sum[i++] = (binary1 %10 + binary2 % 10 + rem) % 2;//This Will give us value 0 or 1 and sum the last numbers of entered numbers//
        rem = (binary1 %10 + binary2 % 10 + rem) / 2;//This will store the remainder 1 or 0//
        binary1 = binary1 / 10;//Removing the last digits of number//
        binary2 = binary2 / 10;
    }
    if (rem != 0)//If remainder is not zero that remainder will be added in the last digit of the sum//
        sum[i++] = rem;
    --i;
    cout<<"-->Sum of two binary numbers is: ";
    while (i >= 0){
        cout<<" "<<sum[i--]<<" ";//Displaying the sum stored in the array in reverse//
    }
		break;
	}

	case 4:{
		
	char sb1[100];
	char sb2[100];
	int rem=0,e1,e2;
	int i,j,n,m,a,b,k=0,l=0,len,len2,len3,addition,temp2,temp3;
	int checker[20];
	start3:
	cout<<"\n\n-->Enter 1st Binary Number to be subtracted: ";	/*Take the number from the user.*/
	cin>>sb1;	/*Store the number*/
	temp2=atoi(sb1);
			for(n=0;temp2!=0;n++){//Storing the number in checker array//
				checker[n]=temp2%10;
				temp2=temp2/10;
			}
			//Checker For Binary number//
			for(m=0;m<n;m++){
				if(checker[m]> 1 && checker[m]> 0){
					cout<<"Invalid Number!";
					goto start3;	
				}
				}	
	
	cout<<"\n-->Enter 2nd Binary Number to be subtract from: ";
	cin>>sb2;
	temp3=atoi(sb2);
			for(a=0;temp3!=0;a++){//Storing the number in checker array//
				checker[a]=temp3%10;
				temp3=temp3/10;
			}
			//Checker For Binary number//
			for(b=0;b<a;b++){
				if(checker[b]> 1 && checker[b]> 0){
					cout<<"Invalid Number!";
					goto start3;	
				}
				}	
	len=strlen(sb1);
	len2=strlen(sb2);
	char cb1[len];
	//Compliment of first number//
	BC(sb1,cb1,len);
	
	
	//Binary Addition//
	len3=len2-1;
	int sum[len3];
	
	for(i=len3;i>=0;i--){
	if(cb1[i]=='0'){
		e1=0;
	}
	if(cb1[i]=='1'){
		e1=1;
	}
	if(sb2[i]=='0'){
		e2=0;
	}
	if(sb2[i]=='1'){
		e2=1;
	}
	addition=e1+e2+rem;//This will add the first 2 numbers from the right side//
	k=addition%2;//This will give us sum in 0 or 1//
	sum[i]=k;//answer of sum is stored in sum array//
	rem=addition/2;//This will give us the remainder.//
	
	}
	//for(i=0;i<=len3;i++){
	//cout<<"%d",sum[i]);}
	cout<<"\n";
	
	if(rem==0){//If the remainder is zero then we will again take compliment of the sum.//
	compliment1(sum,len3);
	cout<<"-";
	cout<<"-->The binary number after subtraction is: ";
	for(i=0;i<=len3;i++){//Printing The Sum//
		cout<<" "<<sum[i]<<" ";
	}
	}
	
	if(rem==1){//If remainder is 1, we will add that remainder in the sum again using binary adittion.//
		
		for(i=len3;i>=0;i--){
			e1=sum[i];
			addition=e1+rem;
			k=(addition%2);
			sum[i]=k;
			rem=addition/2;
		}
		cout<<"-->The Binary number after subtraction is: ";
		for(i=0;i<=len3;i++){
			cout<<" "<<sum[i]<<" ";
		}
		
	}	
		
		
		break;
	}

	case 5:{
		
		int n,n1,i=0,j=0,k,l,temp,temp1,temp2,temp4,temp5,base,answer,comp1,recomp,remainder;
	start4:
	cout<<"\n\n-->Enter a Two Digit Number to be subtracted[Only base 10]: ";
	cin>>n;
	temp4=n;
	for(k=0;temp4!=0;k++){//Checker for decimal number//
		temp4=temp4/10;
	}
	if(k>2){
		cout<<"Invalid Number";
		goto start4;
	}
	cout<<"\n-->Enter the second Two digit number from which first will be subtracted[Only Base 10]: ";
	cin>>n1;
	temp5=n1;
	for(l=0;temp5!=0;l++){//Checker For Decimal number//
		temp5=temp5/10;
	}
	if(l>2){
		cout<<"Invalid Number";
		goto start4;
	}
	cout<<"\n-->Enter the base of both numbers: ";
	cin>>base;
	if(base!=10){//Checker For Decimal base//
		cout<<"Invalid Base";
		goto start4;
	}
	
	//cout<<"The Compliment of number is %d",comp(n,base));
	temp1=n;
	comp1=comp(n,base);
	answer=comp1+n1;
	//cout<<" "<<answer<<" ";
	temp=answer;
	while(temp1!=0){
		temp1/=10;
		j++;
	}
	//cout<<"\n%d",j);
	while(temp!=0){
		temp/=10;
		i++;
	}
	//cout<<"\n%d",i);
	if(i>j){
		remainder=answer%100;
		remainder=remainder+1;
		cout<<"\n\t-->The answer for subtraction of "<<n<<" from "<<n1<<" is: "<<remainder<<"<--";
	}
	else{
		temp2=answer;
		recomp=comp(temp2,base);
		if(recomp<0)
		cout<<"\n\t-->The answer for subtraction of "<<n<<" from "<<n1<<" is:"<<recomp*-1<<" <--";
		else
		cout<<"\n\t-->The answer for subtraction of "<<n<<" from "<<n1<<" is:"<<recomp<<" <--";
	}					
		break;
	}
}

}
