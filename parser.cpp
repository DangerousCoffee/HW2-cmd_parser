#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>


int main (int argc, char *argv[]){

	const char* short_opt = "hvf:m::";

	const struct option long_opt[] = {
		{"help",no_argument,NULL,'h'},
		{"version",no_argument,NULL,'v'},
		{"file",required_argument,NULL,'f'},
		{"message",optional_argument,NULL,'m'},
		{NULL,0,NULL,0}
	};

	int curr;
	int opt_index;
	int help_flag = 0;
	int ver_flag = 0;
	int file_flag = 0;
	int mes_flag = 0;
	char* val;
	

	while ((curr=getopt_long(argc,argv,short_opt,
		long_opt,&opt_index))!=-1){

		switch(curr){
			case 'h': {
				if(help_flag == 0) {
					printf("ARG: Help\n");
				}
				help_flag = 1;
				break;
			};
			case 'v': {
				if(ver_flag == 0) {
					printf("ARG: Version\n");
				}
				ver_flag = 1;
				break;
			};
	
			case 'f': {
				if(file_flag == 0) {
					printf("ARG: File, Value:\n");
					val = strtok(optarg, ",");
					while (val != NULL)
					{
						printf("%s\n", val);
						val = strtok(NULL, ",");
					}
				}
				file_flag == 1;
				break;
			};
			
			case 'm': {
				if(mes_flag == 0) {
					if (optarg != NULL) {
						printf("ARG: Message, Value = %s\n",optarg);
					} else {
						printf("ARG: Message, Value = NULL\n");
					}
				}
				mes_flag = 1;
				break;
			};
			
			case '?': default: {
				printf("found unknown option\n");
				break;
			};
		};
	};
	return 0;
};