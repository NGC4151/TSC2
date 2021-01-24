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

	//更新存档数据
	void UpDataSaveData(FString Culture, float MusicVol, float SoundVol, TArray<FString>* SaveDataList);

private:
	//读取json文件到字符串
	bool LoadStringFromJsonFile(const FString& FileName, const FString& FileRelativePath, FString& ResultString);

	//将jsonObject转换为json格式的字符串
	bool GetJsonObjToJsonStr(const TSharedPtr<FJsonObject>& JsonObj, FString* const JsonStr);

	//保存数据至存档
	bool WriteDataToSaveDataFile(const FString& JsonStr, const FString& FileRelativePath, const FString& FileName);

private:
	//存档文件名
	FString SaveDataFileName;

	//相对路径
	FString RelativePath;
};
