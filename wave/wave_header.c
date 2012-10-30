/*
 *	Lucio Mitsuru Seki	379883
 * */

#include <stdio.h>
#include <stdlib.h>
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
	printf("Subchunk2Size: %ld\n\n", header->Subchunk2Size);
}

void decimar_header(HeaderType *inHeader, int decimacao, FILE* output){
	HeaderType outHeader = *inHeader;
	
	outHeader.Subchunk2Size /= decimacao;
	outHeader.ChunkSize = outHeader.Subchunk1Size + outHeader.Subchunk2Size;
	outHeader.SampleRate /= decimacao;
	outHeader.ByteRate = outHeader.SampleRate * outHeader.NumChannels * outHeader.BitsPerSample / 8;

	fwrite(&outHeader, sizeof(HeaderType), 1, output);
}

void decimar_dados(char* data, HeaderType* inHeader, int decimacao, FILE* output){
	int i, lim;
	
	// quantidade de iteracoes para realizar
	lim = inHeader->Subchunk2Size / (inHeader->BlockAlign * decimacao);

	// copia amostras pulando intervalos de decimacao
	for(i = 0; i < lim; i++){
		fwrite(data + inHeader->BlockAlign * inHeader->NumChannels * i * decimacao / 2, inHeader->BlockAlign, 1, output);
	}
}
