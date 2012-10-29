#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wave_header.h"

int main(int argc, char** argv){
	HeaderType header;
	char* data;

	if(argc < 2 || argc > 3){
		printf("Usage: main <input.wav> [output.wav]\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "rb");
	if(!fp){
		perror(argv[1]);
		return 1;
	}
	fread(&header, sizeof(header), 1, fp);
	show_header(&header);
	
	if(argc > 2){
		data = malloc(header.Subchunk2Size);

		fread(data, header.Subchunk2Size, 1, fp);
		fclose(fp);

		fp = fopen(argv[2], "wb");
		if(!fp){
			perror(argv[1]);
			return 1;
		}

		fwrite(&header, sizeof(header), 1, fp);
		fwrite(data, header.Subchunk2Size, 1, fp);
	}

	fclose(fp);

	return 0;
}
