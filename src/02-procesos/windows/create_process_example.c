#include <stdio.h>
#include <windows.h>

int main(VOID)
{
  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  /* allocate memory */
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));

  /* create child process */
  if (!CreateProcess(
    NULL, /* use command line */
    "C:\\Program Files\\WindowsApps\\Microsoft.Paint_11.2502.161.0_x64__8wekyb3d8bbwe\\PaintApp\\mspaint.exe", /* command */
    NULL, /* don’t inherit process handle */
    NULL, /* don’t inherit thread handle */
    FALSE, /* disable handle inheritance */
    0, /* no creation flags */
    NULL, /* use parent’s environment block */
    NULL, /* use parent’s existing directory */
    &si,
    &pi))
  {
    fprintf(stderr, "Create Process Failed");
    return -1;
  }

  /* parent will wait for the child to complete */
  WaitForSingleObject(pi.hProcess, INFINITE);
  printf("Child Complete");
  
  /* close handles */
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
}


/*
  https://www.mingw-w64.org/getting-started/msys2/
  https://www.msys2.org/

  -->  https://code.visualstudio.com/docs/cpp/config-mingw

  Windows 10 and 11. Find out the version of Paint installed on your system by running this command in PowerShell as administrator:
      Get-AppxPackage -allusers Microsoft.Paint | Select-Object -Property Name, InstallLocation
  The output will look something like this:
      Name              : Microsoft.Paint_11.2502.161.0_x64__8wekyb3d8bbwe
      InstallLocation   : C:\Program Files\WindowsApps\Microsoft.Paint_11.2502.161.0_x64__8wekyb3d8bbwe
*/