#include <stdio.h>
#include "wave_header.h"

void show_header(HeaderType *header){
	printf("ChunkID: %.4s\n", &(header->ChunkID));
	printf("ChunkSize: %ld\n", header->ChunkSize);
	printf("Format: %.4s\n", &(header->Format));
	printf("Subchunk1ID: %.4s\n", &(header->Subchunk1ID));
	printf("Subchunk1Size: %ld\n", header->Subchunk1Size);
	printf("AudioFormat: %hu\n", header->AudioFormat);
	printf("NumChannels: %hu\n", header->NumChannels);
	printf("SampleRate: %ld\n", header->SampleRate);
	printf("ByteRate: %ld\n", header->ByteRate);
	printf("BlockAlign: %hu\n", header->BlockAlign);
	printf("BitsPerSample: %hu\n", header->BitsPerSample);
	printf("Subchunk2ID: %.4s\n", &(header->Subchunk2ID));
	printf("Subchunk2Size: %ld\n", header->Subchunk2Size);
}
