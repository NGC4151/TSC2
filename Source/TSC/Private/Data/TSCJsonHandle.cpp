// shut up


#include "Data/TSCJsonHandle.h"
#include <Common/TSCHelper.h>

TSCJsonHandle::TSCJsonHandle()
{
	SaveDataFileName = FString("SaveData.json");
	RelativePath = FString("RES/ConfigData/");
}

void TSCJsonHandle::SaveDataRead(FString& Culture, float& MusicVol, float& SoundVol, TArray<FString>& SaveDataList)
{
	//加载json文件中的数据，保存到字符串
	FString JsonValue;
	LoadStringFromJsonFile(SaveDataFileName, RelativePath, JsonValue);

	//解析出来的数据
	TArray<TSharedPtr<FJsonValue>>JsonParsed;
	//读取JsonValue中的数据
	TSharedRef<TJsonReader<TCHAR>>JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValue);

	if (FJsonSerializer::Deserialize(JsonReader,JsonParsed))
	{
		//获取数据
		Culture = JsonParsed[0]->AsObject()->GetStringField(FString("Culture"));
		MusicVol = JsonParsed[1]->AsObject()->GetNumberField(FString("MusicVolume"));
		SoundVol = JsonParsed[2]->AsObject()->GetNumberField(FString("SoundVolume"));

		//获取存档数据
		TArray<TSharedPtr<FJsonValue>>SaveDataArray = JsonParsed[3]->AsObject()->GetArrayField(FString("SaveData"));
		for (int i=0;i<SaveDataArray.Num();++i)
		{
			FString SavaDataName = SaveDataArray[i]->AsObject()->GetStringField(FString::FromInt(i));
			SaveDataList.Add(SavaDataName);
		}
	}
	else
	{
		TSSCHelper::Debug(FString("SaveData Deserialize failed!"),FColor::Yellow,20.f);
	}
}

bool TSCJsonHandle::LoadStringFromJsonFile(const FString& FileName, const FString& FileRelativePath, FString& ResultString)
{
	if (!FileName.IsEmpty())
	{
		//获取绝对路径
		FString AbsoPath = FPaths::ProjectContentDir() + RelativePath + FileName;
		if (FPaths::FileExists(AbsoPath))
		{
			if (FFileHelper::LoadFileToString(ResultString,*AbsoPath))
			{
				return true;
			}
			else {
				TSSCHelper::Debug(FString("Load Error:") + AbsoPath,FColor::Yellow,20.f);
			}
		}
		else
		{
			TSSCHelper::Debug(FString("Not Found This File:") + AbsoPath, FColor::Yellow,20.f);
		}
	}
	return false;
}

