#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For exit()

int main()
{
	FILE *fptr2, *fp1, *fp;
	char filename[10], filecontent[1000], x[] = {"Hii, This is AbhiShek Yadav."}, c, d;
	printf("Enter the filename to open for reading \n");
	scanf("%s", filename);
	fflush(stdin);
	printf("file creation process is sucess");
	printf("\n now you can enter your content in file.\n");
	gets(filecontent);

	fp1 = fopen(filename, "w");
	fputs(x, fp1);
	fputs("\n---------------------------\n", fp1);
	fclose(fp1);

	fptr2 = fopen(filename, "a+");
	if (fptr2 == NULL)
	{
		printf("Cannot open file %s \n");
		exit(0);
	}

	if (strlen(filecontent) > 0)
		fputs(filecontent, fptr2);
	fclose(fptr2);
	fptr2 = fopen(filename, "r");
	if (fptr2 == NULL)
	{
		printf("Cannot open file %s \n");
		exit(0);
	} 

char  a [15] = "copy_of_";
 strcat(a,filename);
 
fp = fopen(a, "w");
	printf("display the content of the file \n copy the content of file %s into copy_of_ab \n ", filename);
	for (c = fgetc(fptr2); c != EOF; c = fgetc(fptr2))
	{
		fputc(c, fp);
		printf("%c", c);
	}
	fclose(fptr2);
	fclose(fp);
	return 0;
}