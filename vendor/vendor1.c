#include "publisher_main.h"
#include "MQTTClient.h"
#include "subscribe_main.h"
#include"pubsub_opts.h"
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


bool checkIfModeIsPub(char* mode)
{
	if (strcmp(mode, "pub") == 0)
		return true;
	return false;
}
bool checkIfModeIssub(char* mode)
{
	if (strcmp(mode, "sub") == 0)
		return true;
	return false;
}
//bool checkIfArgumentCountGreaterThanTwo(int argc)
//{
//	if (argc > 2)
//		return true;
//	return false;
//
//}
//
//void callPublisherMainWhenModeIsPub(char* mode, char* argvnew[],int argcnew)
//{
//	if (checkIfModeIsPub(mode))
//	{
//		PUBLISHmain(argcnew, argvnew);
//	}
//
//}
//void callSubscriberMainWhenModeIsSub(char* mode, char* argvnew[], int argcnew)
//{
//	if (checkIfModeIssub(mode))
//	{
//		SUBSCRIBEmain(argcnew, argvnew);
//	}
//
//}
//void PrintErrorMessageIfIncorrectOptionEntered(char* mode)
//{
//	if (!(checkIfModeIsPub || checkIfModeIssub))
//	{
//		printf("Enter either sub or pub ");
//		exit(1);
//	}
//}

void getUserDetails(char ch,char patientName[],char consumables[],char procedure[],char*argvPub[],int argvPubCount)
{
	
	while (ch == 'Y')
	{
		printf("Enter the PatientName:");
		fgets(patientName, sizeof(patientName), stdin);
		argvPub[2] = "Patient/Name";
		argvPub[4] = patientName;
		PUBLISHmain(argvPubCount, argvPub);
		printf("Enter the Consumables Used:");
		fgets(consumables, sizeof(consumables), stdin);
		argvPub[2] = "Patient/Consumables";
		argvPub[4] = consumables;
		PUBLISHmain(argvPubCount, argvPub);
		printf("Enter the Procedure:");
		fgets(procedure, sizeof(procedure), stdin);
		//strcat(patientProcedure,patientName);
		argvPub[2] = "Patient/Procedure";
		argvPub[4] = procedure;
		PUBLISHmain(argvPubCount, argvPub);
		printf("Do you wanr to continue? enter (Y-yes/N-No)");

		ch = getchar();
		while ((getchar()) != '\n');
	}

		
}

int main(int argc, char* argv[])
{
	
	
	char* argvSub[5] = { argv[0],"-t","Patient/#" ,"-i","id1","-c","tcp://mqtt.eclipse.org:1883"};
	int argvSubCount=7;
	
	char* argvPub[5]= { argv[0],"-t","","-m","","-c","tcp://mqtt.eclipse.org:1883"};
	int argvPubCount = 7;

	char patientName[20];
	char consumables[20];
	char  procedure[20];
	char ch = 'Y';
	if (checkIfModeIsPub(argv[1]))
	{
		getUserDetails(ch,patientName, consumables, procedure, argvPub, argvPubCount);
	}
	else
	{
		
		SUBSCRIBEmain(argvSubCount, argvSub);
	}

	
	return 0;
	
		



	
}
