/*初级C程序员最容易踩得坑代码5*/
//遍历打印指定目录下的所有文件和文件夹
/*程序功能没有问题，但是是递归函数，在申请内存时会重复申请，会导致堆栈空间耗光，出现崩溃，解决方案不用重复申请dir_path,在根函数中申请足够大空间就行。
*/
//一般函数的局部数组、结构体对象大小，总共最好不要超过256个字节
void dir_printf(char *dir)
{
#define _MAX_PATH 4096
	DIR *dp;
	struct dirent *entry;
	char dir_path[_MAX_PATH];
	struct stat statbuf;
	if(!dir){
		fprintf(stderr, "dir_printf: dir is null\n");
		return;
	}
	//去除路径最后的/号，如有
	int i = strlen(dir) - 1;
	while(i >= 0 && dir[i] == '/'){
		dir[i] = 0;
		i --;	
	}
	if ((dp = opendir(dir)) == NULL) 	{
		fprintf(stderr, "Can`t open directory %s\n", dir);
		return;
	}	
	while((entry = readdir(dp)) != NULL) 	{
		if(strcmp(entry->d_name, "..") == 0
			|| strcmp(entry->d_name, ".") == 0){
			continue;
		}
		
		snprintf(dir_path, sizeof(dir_path), "%s/%s", dir, entry->d_name);
		lstat(dir_path, &statbuf);	
		if(S_ISDIR(statbuf.st_mode)){
			printf("[DIR] %s\r\n", dir_path);
			dir_printf(dir_path);
		}
		else{
			printf("[FILE] %s\r\n", dir_path);
		}
	}
	closedir(dp);
}
