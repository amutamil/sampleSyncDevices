#include "subscribe_main.h"

 
int wildCardCheckInTopicName(struct pubsub_opts opts)
{
	if (strchr(opts.topic, '#') || strchr(opts.topic, '+'))
		return 1;
	return 0;
}
//Change 5
char* CheckconnectionToWhichHost(struct pubsub_opts opts)
{
	char* url;
	if (opts.connection)
		url = opts.connection;
	else
	{
		url = malloc(100);
		sprintf(url, "%s:%s", opts.host, opts.port);
	}
	return url;
}

//change 6
//void printUrlIfVerboseIsTrue(const char* url, struct pubsub_opts opts)
//{
//	if (opts.verbose)
//		printf("URL is %s\n", url);
//}


//change 9
//void printMQTTClientErrorMessage(int rc, struct pubsub_opts opts)
//{
//	if (rc != MQTTCLIENT_SUCCESS)
//	{
//		if (!opts.quiet)
//			fprintf(stderr, "Failed to create client, return code: %s\n", MQTTClient_strerror(rc));
//		exit(EXIT_FAILURE);
//	}
//}

//change 11
bool CheckConnectionSuccessOrNot(MQTTClient client, struct pubsub_opts opts)
{
	if (myconnect(client, &opts) != MQTTCLIENT_SUCCESS)
		return 1;
	return 0;
}

//change 13
//bool PrintAndExitIfRcNotEqualToClientSuccessAndQos(int rc, struct pubsub_opts opts)
//{
//	if (rc != MQTTCLIENT_SUCCESS && rc != opts.qos)
//	{
//		if (!opts.quiet)
//			fprintf(stderr, "Error %d subscribing to topic %s\n", rc, opts.topic);
//		return true;
//	}
//	return false;
//}



//change 17
//void PassingMQttpropertiesToLogProperties(MQTTClient_message* message, struct pubsub_opts opts)
//{
//	
//
//	if (message->struct_version == 1 && opts.verbose)
//		logProperties(&message->properties);
//}

////change 18
//void connectClientToServer(int rc, MQTTClient client, struct pubsub_opts opts)
//{
//	if (rc != 0)
//		myconnect(&client, &opts);
//}

