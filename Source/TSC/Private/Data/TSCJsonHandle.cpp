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

void TSCJsonHandle::UpDataSaveData(FString Culture, float MusicVol, float SoundVol, TArray<FString>* SaveDataList)
{
	TSharedPtr<FJsonObject>Jsonobject = MakeShareable(new FJsonObject);

	TArray<TSharedPtr<FJsonValue>>BaseDataArray;

	TSharedPtr<FJsonObject>CultureObj= MakeShareable(new FJsonObject);
	CultureObj->SetStringField("Culture", Culture);
	TSharedPtr<FJsonValueObject>CultureValue = MakeShareable(new FJsonValueObject(CultureObj));

	TSharedPtr<FJsonObject>MusicVolObj = MakeShareable(new FJsonObject);
	MusicVolObj->SetNumberField("MusicVolume", MusicVol);
	TSharedPtr<FJsonValueObject>MusicVolValue = MakeShareable(new FJsonValueObject(MusicVolObj));

	TSharedPtr<FJsonObject>SoundVolObj = MakeShareable(new FJsonObject);
	SoundVolObj->SetNumberField("SoundVolume", SoundVol);
	TSharedPtr<FJsonValueObject>SoundVolValue = MakeShareable(new FJsonValueObject(SoundVolObj));

	TArray<TSharedPtr<FJsonValue>>SaveDataArray;

	for (int i=0;i<SaveDataList->Num();++i)
	{
		TSharedPtr<FJsonObject>SaveDataItem = MakeShareable(new FJsonObject);
		SaveDataItem->SetStringField(FString::FromInt(i), (*SaveDataList)[i]);
		TSharedPtr<FJsonValueObject>SaveDataValue = MakeShareable(new FJsonValueObject(SaveDataItem));
		SaveDataArray.Add(SaveDataValue);
	}

	TSharedPtr<FJsonObject>SavedataObj = MakeShareable(new FJsonObject);
	SavedataObj->SetArrayField("SaveData", SaveDataArray);
	TSharedPtr<FJsonValueObject>SaveDataValue = MakeShareable(new FJsonValueObject(SavedataObj));

	BaseDataArray.Add(CultureValue);
	BaseDataArray.Add(MusicVolValue);
	BaseDataArray.Add(SoundVolValue);
	BaseDataArray.Add(SaveDataValue);

	Jsonobject->SetArrayField("T", BaseDataArray);

	FString jsonStr;
	GetJsonObjToJsonStr(Jsonobject, &jsonStr);

	// TSSCHelper::Debug(FString("Origin Str: ") + jsonStr, FColor::Yellow);

	jsonStr.RemoveAt(0, 8);
	jsonStr.RemoveFromEnd(FString("}"));

	TSSCHelper::Debug(FString("New Str: ") + jsonStr, FColor::Yellow);

	WriteDataToSaveDataFile(jsonStr, RelativePath, SaveDataFileName);

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

bool TSCJsonHandle::GetJsonObjToJsonStr(const TSharedPtr<FJsonObject>& JsonObj,FString* const JsonStr)
{
	if (JsonObj.IsValid()&&JsonObj->Values.Num()>0)
	{
		TSharedRef<TJsonWriter<TCHAR>>JsonWriter = TJsonWriterFactory<TCHAR>::Create(JsonStr);
		FJsonSerializer::Serialize(JsonObj.ToSharedRef(), JsonWriter);
		return true;
	}
	return false;
}

bool TSCJsonHandle::WriteDataToSaveDataFile(const FString& JsonStr, const FString& FileRelativePath, const FString& FileName)
{
	if (!JsonStr.IsEmpty())
	{
		if (!FileName.IsEmpty())
		{
			FString AbsoPath = FPaths::ProjectContentDir() + FileRelativePath + FileName;
			//保存数据至json文件
			if (FFileHelper::SaveStringToFile(JsonStr,*AbsoPath))
			{
				TSSCHelper::Debug(FString("Save data to --> ") + AbsoPath + FString(" Success!"),FColor::Yellow);
				return true;
			}
			else
			{
				TSSCHelper::Debug(FString("Save data to --> ") + AbsoPath + FString(" Failed!"), FColor::Yellow);
			}
		}
	}
	return false;
}

