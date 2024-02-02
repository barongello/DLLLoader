#include <Windows.h>

#define BUF_SIZE 256

void LoadDLLs()
{
  char *path  = (char *)malloc(sizeof(char) * BUF_SIZE);
  char *index = (char *)malloc(sizeof(char) * BUF_SIZE);

  unsigned int i = 0;

  while (true)
  {
    itoa(i++, index, 10);

    GetPrivateProfileStringA(
      "Paths",
      index,
      "",
      path,
      BUF_SIZE,
      "./DLLLoader.ini"
    );

    if (strlen(path) == 0)
    {
      break;
    }

    LoadLibraryA(path);
  }

  free(index);
  free(path);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  if (fdwReason == DLL_PROCESS_ATTACH)
  {
    LoadDLLs();
  }

  return TRUE;
}
