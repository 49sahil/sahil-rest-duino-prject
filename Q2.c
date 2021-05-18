#include <stdio.h>
#include <string.h>

void printline(FILE *fromfp,FILE * tofp){
	char c;
	fscanf(fromfp,"%c",&c);
	while(c!='\n'){
		fprintf(tofp,"%c",c);
		fscanf(fromfp,"%c",&c);
	}
}

int main()
{
	char st[50];
	printf("Enter a search string: ");
	scanf("%s",st);

	FILE * fp1;
	fp1=fopen("courses.txt","r");
	fseek(fp1,0,SEEK_SET);                              //sometimes the cursor misbehaves(it did with me atleast)
	char v;

	int matches=0,clr=0;   //Characters of Line Read(clr) 
	while (!feof(fp1)){
		fscanf(fp1,"%c",&v);
		clr+=1;
		if (v=='\n') clr=0;                                  // '/n' means new line so clr=0
		
		if (v==st[0]){
			int flag=1,i=1;
			fscanf(fp1,"%c",&v);clr+=1;
			while (v!=' ' && v!='\n' ){
				if (st[i]!=v){
					flag=0;break;
				}
				i+=1;
				fscanf(fp1,"%c",&v);
				if (v=='\n') clr+=2;
				else clr+=1;
			}
			if(flag==1 && i==strlen(st)){         //here I have done it to avoid cases where given word is a subword of word in courses.txt
				fseek(fp1,(-1)*clr,SEEK_CUR);     //going to begining of file
				printline(fp1,stdout);           
				printf("\n");
				matches+=1;                      //counting number of matches
				clr=0;
			}
			if (v=='\n') clr=0;
		}
	}
	printf("Number of matches: %d",matches);
	fclose(fp1);
	return 0;
}
