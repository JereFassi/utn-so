#include <stdio.h>
#include <string.h>
#include <windows.h>

static void printWindowsError(const char *context)
{
  DWORD errorCode = GetLastError();
  LPSTR messageBuffer = NULL;

  FormatMessageA(
    FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL,
    errorCode,
    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
    (LPSTR)&messageBuffer,
    0,
    NULL);

  fprintf(stderr, "%s (error %lu)", context, errorCode);

  if (messageBuffer != NULL) {
    fprintf(stderr, ": %s", messageBuffer);
    LocalFree(messageBuffer);
  } else {
    fprintf(stderr, "\n");
  }
}

static int buildDefaultImagePath(char *buffer, size_t bufferSize)
{
  char executablePath[MAX_PATH];
  char repoRelativePath[MAX_PATH * 2];
  char *lastSlash = NULL;

  if (GetModuleFileNameA(NULL, executablePath, MAX_PATH) == 0) {
    return 0;
  }

  lastSlash = strrchr(executablePath, '\\');
  if (lastSlash == NULL) {
    return 0;
  }

  *lastSlash = '\0';

  snprintf(
    repoRelativePath,
    sizeof(repoRelativePath),
    "%s\\..\\..\\..\\recursos\\img\\Evolv.jpg",
    executablePath);

  return GetFullPathNameA(repoRelativePath, (DWORD)bufferSize, buffer, NULL) != 0;
}

static int findPaintPath(char *buffer, size_t bufferSize)
{
  DWORD result = SearchPathA(NULL, "mspaint.exe", NULL, (DWORD)bufferSize, buffer, NULL);

  if (result != 0 && result < bufferSize) {
    return 1;
  }

  return snprintf(buffer, bufferSize, "C:\\Windows\\System32\\mspaint.exe") > 0;
}

int main(int argc, char *argv[])
{
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  char commandLine[MAX_PATH * 4];
  char defaultImagePath[MAX_PATH * 2];
  char paintPath[MAX_PATH];
  char *imagePath = NULL;

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

  if (!buildDefaultImagePath(defaultImagePath, sizeof(defaultImagePath))) {
    fprintf(stderr, "Could not resolve default image path.\n");
    return 1;
  }

  if (!findPaintPath(paintPath, sizeof(paintPath))) {
    fprintf(stderr, "Could not locate mspaint.exe.\n");
    return 1;
  }

  if (strcmp(argv[1], "default") == 0) {
    imagePath = defaultImagePath;
  } else {
    imagePath = argv[1];
  }

  if (GetFileAttributesA(imagePath) == INVALID_FILE_ATTRIBUTES) {
    fprintf(stderr, "Image file not found: %s\n", imagePath);
    return 1;
  }

  printf("Image Path: %s\n", imagePath);
  printf("Paint Path: %s\n", paintPath);

  /* prepare command line with image path */
  snprintf(commandLine, sizeof(commandLine), "\"%s\" \"%s\"", paintPath, imagePath);

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
    printWindowsError("Create Process Failed");
    return -1;
  }

  /* parent will wait for the child to complete */
  WaitForSingleObject(pi.hProcess, INFINITE);
  printf("Child Complete");

  /* close handles */
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
}
