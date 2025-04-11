#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  char commandLine[MAX_PATH * 2];
  char *defaultImagePath = "C:\\Users\\Usuario\\Proyectos\\utn-so\\recursos\\img\\Evolv.jpg";

  /* Check if image path was provided */
  if (argc != 2) {
    printf("Usage: %s <path-to-image>\n", argv[0]);
    printf("Example: %s C:\\Users\\Pictures\\image.jpg\n", argv[0]);
    printf("Or use 'default' to open the default image");
    return 1;
  }

  /* Initialize STARTUPINFO structure. Allocate memory */
  ZeroMemory(&si, sizeof(si));  // Clear all fields to 0
  si.cb = sizeof(si);           // Set structure size for Windows
  ZeroMemory(&pi, sizeof(pi));  // Clear process information structure

  printf("Image Path: %s\n", argv[1]);
  printf("Default Image Path: %s\n", defaultImagePath);

  /* prepare command line with image path */
  if (strcmp(argv[1], "default") == 0) {
    snprintf(commandLine, sizeof(commandLine),
      "C:\\Program Files\\WindowsApps\\Microsoft.Paint_11.2502.161.0_x64__8wekyb3d8bbwe\\PaintApp\\mspaint.exe \"%s\"",
      defaultImagePath);
  } else {
    snprintf(commandLine, sizeof(commandLine),
      "C:\\Program Files\\WindowsApps\\Microsoft.Paint_11.2502.161.0_x64__8wekyb3d8bbwe\\PaintApp\\mspaint.exe \"%s\"",
      argv[1]);
  }

  /* create child process */
  if (!CreateProcess(NULL, /* use command line */
    commandLine,    /* command with image path */
    NULL,          /* don't inherit process handle */
    NULL,          /* don't inherit thread handle */
    FALSE,         /* disable handle inheritance */
    0,            /* no creation flags */
    NULL,         /* use parent's environment block */
    NULL,         /* use parent's existing directory */
    &si,
    &pi))
  {
    fprintf(stderr, "Create Process Failed\n");
    return -1;
  }

  /* parent will wait for the child to complete */
  WaitForSingleObject(pi.hProcess, INFINITE);
  printf("Child Complete");

  /* close handles */
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
}
