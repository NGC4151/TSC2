// shut up

#pragma once

#include "CoreMinimal.h"
#include "Data/TSCTypes.h"
#include "Json.h"

/**
 * 
 */
class TSC_API TSCJsonHandle
{
public:
	TSCJsonHandle();

	//解析从json文件数据
	void SaveDataRead(FString& Culture, float& MusicVol, float& SoundVol, TArray<FString>& SaveDataList);

private:
	//读取json文件到字符串
	bool LoadStringFromJsonFile(const FString& FileName, const FString& FileRelativePath, FString& ResultString);

private:
	//存档文件名
	FString SaveDataFileName;

	//相对路径
	FString RelativePath;
};
