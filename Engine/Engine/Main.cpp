#include <crtdbg.h>
#include "Engine.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 3433; //mem debugging
	ENGINE;
	ENGINE->LoadTileMap("maps/map02.txt");
	ENGINE->Run();
	ENGINE->Release();
	_CrtDumpMemoryLeaks();
	return 0;
}