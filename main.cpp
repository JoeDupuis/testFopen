#include <stdio.h>

int main(){

	#ifdef USE_VFS

	#endif


	FILE * pFile;


	printf("Mode: 'r'\n");
	pFile = fopen ("directoryTest/test.txt", "r");
	if (pFile==NULL){
		printf("File mode r pFile==NULL\n");
	}
	else{
		printf("File mode r open successfully\n");
		fseek(pFile, 0, SEEK_END);
		printf("Seek don't crash\n");
	    fclose (pFile);
	}

	pFile = fopen ("directoryTest", "r");
	if (pFile==NULL){
		printf("directoryTest mode r pFile==NULL\n");
	}
	else{
		printf("directoryTest mode r open successfully\n");
		fseek(pFile, 0, SEEK_END);
		printf("Seek don't crash\n");
	    fclose (pFile);
	}


		printf("\n\n\n");


	printf("Mode: 'w'\n");
	pFile = fopen ("directoryTest/test.txt", "w");
	if (pFile==NULL){
		printf("File mode w pFile==NULL\n");
	}
	else{
		printf("File mode w open successfully\n");
		fseek(pFile, 0, SEEK_END);
		printf("Seek don't crash\n");
	    fclose (pFile);
	}

	pFile = fopen ("directoryTest", "w");
	if (pFile==NULL){
		printf("directoryTest mode w pFile==NULL\n");
	}
	else{
		printf("directoryTest mode w open successfully\n");
		fseek(pFile, 0, SEEK_END);
		printf("Seek don't crash\n");
	    fclose (pFile);
	}




	


	printf("\n\n\n");


	printf("Unexisting directory : \n");

	pFile = fopen ("unexistringDir", "r");
	if (pFile==NULL){
		printf("unexistringDir mode r pFile==NULL\n");
	}
	else{
		printf("unexistringDir mode r open successfully\n");
		fseek(pFile, 0, SEEK_END);
		printf("Seek don't crash\n");
	    fclose (pFile);
	}

		pFile = fopen ("unexistringDir", "w");
	if (pFile==NULL){
		printf("unexistringDir mode w pFile==NULL\n");
	}
	else{
		printf("unexistringDir mode w open successfully\n");
		fseek(pFile, 0, SEEK_END);
		printf("Seek don't crash\n");
	    fclose (pFile);
	}
	return 0;
}