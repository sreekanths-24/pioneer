#include<stdio.h>
#include<string.h>
void main()
{
FILE *f1,*f2,*f3,*f4;
char s[100],lab[30],opcode[30],opa[30],opcode1[30],opa1[30];
int locctr,x=0;
f1=fopen("input.txt","r");
f2=fopen("opcode.txt","r");
f3=fopen("out1.txt","w");
f4=fopen("sym1.txt","w");
while(fscanf(f1,"%s%s%s",lab,opcode,opa)!=EOF)
{
	if(strcmp(lab,"**")==0)
	{
	if(strcmp(opcode,"START")==0)
	{
		fprintf(f3,"%s %s %s",lab,opcode,opa);
		locctr=(atoi(opa));
		
	}
	else
	{
		rewind(f2); 
		x=0;
		while(fscanf(f2,"%s%s",opcode1,opa1)!=EOF)
		{
		if(strcmp(opcode,opcode1)==0)
		{
		x=1;
		}
		}
		if(x==1)
		{
		fprintf(f3,"\n %d %s %s %s",locctr,lab,opcode,opa);
		locctr=locctr+3;
		}
	}
	}
	else
	{
	if(strcmp(opcode,"RESW")==0)
	{
	fprintf(f3,"\n %d %s %s %s",locctr,lab,opcode,opa);
	fprintf(f4,"\n %d %s",locctr,lab);
	locctr=locctr+(3*(atoi(opa)));
	}
	else if(strcmp(opcode,"WORD")==0)
	{
	fprintf(f3,"\n %d %s %s %s",locctr,lab,opcode,opa);
	fprintf(f4,"\n %d %s",locctr,lab);
	locctr=locctr+3;
	}
	else if(strcmp(opcode,"BYTE")==0)
	{
	fprintf(f3,"\n %d %s %s %s",locctr,lab,opcode,opa);
	fprintf(f4,"\n %d %s",locctr,lab);
	locctr=locctr+1;
	}
	else if(strcmp(opcode,"RESB")==0)
	{
	fprintf(f3,"\n %d %s %s %s",locctr,lab,opcode,opa);
	fprintf(f4,"\n %d %s",locctr,lab);
	locctr=locctr+1;
	}
	else
	{
	fprintf(f3,"\n %d %s %s %s",locctr,lab,opcode,opa);
	fprintf(f4,"\n %d %s",locctr,lab);
	locctr=locctr+(atoi(opa));
	}
	}
}
}
≈===================
INPUT FILES

input.txt
** START 2000
** LDA FIVE
** STA ALPHA
** LDCH CHARZ
** STCH C1
ALPHA RESW 1
FIVE WORD 5
CHARZ BYTE C'Z'
C1 RESB 1
** END **

opcode.txt
START *
LDA 03
STA 0F
LDCH 53
STCH 57
END 

OUTPUT FILES

out1.txt

** START 2000
 2000 ** LDA FIVE
 2003 ** STA ALPHA
 2006 ** LDCH CHARZ
 2009 ** STCH C1
 2012 ALPHA RESW 1
 2015 FIVE WORD 5
 2018 CHARZ BYTE C'Z'
 2019 C1 RESB 1
 2020 ** END **

sym1.txt

 2012 ALPHA
 2015 FIVE
 2018 CHARZ
 2019 C1
