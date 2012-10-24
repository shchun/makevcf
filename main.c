#include <stdio.h>
#include <string.h>

void printVcardItem(char* name, char* telnum, char* telnum2) 
{
	printf("BEGIN:VCARD\n");
	printf("VERSION:2.1\n");
	printf("FN;CHARSET=UTF-8:%s\n", name);
	printf("N;CHARSET=UTF-8:%s;;;;\n", name);
	printf("TEL;TYPE=HOME:%s\n", telnum);
	printf("TEL;TYPE=CELL:%s\n", telnum2);
	printf("END:VCARD\n");
}
int main(int argc, char* argv[])
{
	char lbuf[200] = {0, };

	char name[100] = {0, };
	char telnum[100] = {0, };
	char telnum2[100] = {0, };

	while (fgets(lbuf, sizeof(lbuf), stdin)) {

		//printf("lbuf = [%s]\n", lbuf);
		sscanf(lbuf, "%s %s %s", name, telnum, telnum2);

		//printf("name = %s, telnum = %s, telnum2 = %s\n", name, telnum,
		//		telnum2);
		printVcardItem(name, telnum, telnum2);
		memset(lbuf, 0x0, sizeof(lbuf));
		memset(name, 0x0, sizeof(name));
		memset(telnum, 0x0, sizeof(telnum));
		memset(telnum2, 0x0, sizeof(telnum2));
	}

	return 1;
}


