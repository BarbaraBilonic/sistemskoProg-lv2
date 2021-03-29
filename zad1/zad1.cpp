#include<windows.h>
#include <io.h>
#include <stdio.h>
#include <direct.h>

int main(int argc,  const char *argv[]) {
	
	int fileCounter = 0, dirCounter = 0;
	char startingDir[_MAX_PATH];
	if (argc != 2) {
		printf("Usage: cp dir");
		return 1;
	}

	_getcwd(startingDir, _MAX_PATH);
	_chdir(argv[1]);
	
	_finddata_t fileinfo;
	intptr_t handle = _findfirst("*", &fileinfo);
	if (handle == -1) {
		printf("Error finding filer or directories.");
		return 0;
	}
	do
	{
		if (strcmp(fileinfo.name, ".") == 0 || strcmp(fileinfo.name, "..") == 0)
			continue;
		if (fileinfo.attrib & _A_SUBDIR) {

			dirCounter++;
		}
		else {

			fileCounter++;
			
		}

	} while (_findnext(handle, &fileinfo) == 0);
	printf("Number of files: %d\n", fileCounter);
	printf("Number of directories: %d\n", dirCounter);
	_chdir(startingDir);
	_findclose(handle);
	return 0;

}

