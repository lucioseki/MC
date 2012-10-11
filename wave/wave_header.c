#include <stdio.h>
#include "wave_header.h"

void show_header(HeaderType *header){
	long label;

	label = header->ChunkID;
	printf("ChunkID: %c%c%c%c\n", label, label >> 8, label >> 16, label >> 24);
	printf("ChunkSize: %ld\n", header->ChunkSize);

	label = header->Format;
	printf("Format: %c%c%c%c\n", label, label >> 8, label >> 16, label >> 24);

	label = header->Subchunk1ID;
	printf("Subchunk1ID: %c%c%c%c\n", label, label >> 8, label >> 16, label >> 24);
	printf("Subchunk1Size: %ld\n", header->Subchunk1Size);
	printf("AudioFormat: %hu\n", header->AudioFormat);
	printf("NumChannels: %hu\n", header->NumChannels);
	printf("SampleRate: %ld\n", header->SampleRate);
	printf("ByteRate: %ld\n", header->ByteRate);
	printf("BlockAlign: %hu\n", header->BlockAlign);
	printf("BitsPerSample: %hu\n", header->BitsPerSample);

	label = header->Subchunk2ID;
	printf("Subchunk2ID: %c%c%c%c\n", label, label >> 8, label >> 16, label >> 24);
	printf("Subchunk2Size: %ld\n", header->Subchunk2Size);
}
