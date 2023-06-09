#include <stdio.h>
#include <stdlib.h>
#include "waifu2x.h"


__declspec(dllexport)
void* Waifu2xInit(const char *mode, const int noise_level, const char *model_dir, const char *process, const int crop_size = 128, const int batch_size = 1)
{
	Waifu2x *obj = new Waifu2x();

	char *argv[] = { "" };

	if (obj->init(1, argv, mode, noise_level, model_dir, process, crop_size, batch_size) != Waifu2x::eWaifu2xError_OK)
	{
		delete obj;
		return nullptr;
	}

	return obj;
}

__declspec(dllexport)
bool Waifu2xProcess(void *waifu2xObj, int factor, const uint32_t* source, uint32_t* dest, int width, int height)
{
	if (!waifu2xObj)
		return false;

	Waifu2x *obj = (Waifu2x *)waifu2xObj;

	return obj->waifu2x(factor, source, dest, width, height) == Waifu2x::eWaifu2xError_OK;
}

__declspec(dllexport)
void Waifu2xDestory(void *waifu2xObj)
{
	if (waifu2xObj)
	{
		Waifu2x *obj = (Waifu2x *)waifu2xObj;
		delete obj;
	}
}
