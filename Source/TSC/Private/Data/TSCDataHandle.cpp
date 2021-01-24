// shut up


#include "Data/TSCDataHandle.h"
#include "Internationalization/Internationalization.h"
#include "Data/TSCSingleton.h"
#include "Data/TSCJsonHandle.h"
#include <Common/TSCHelper.h>



TSharedPtr<TSCDataHandle>TSCDataHandle::DataInstance = NULL;

void TSCDataHandle::Initialize()
{
	if (!DataInstance.IsValid())
	{
		DataInstance = Create();
	}
}

TSharedPtr<TSCDataHandle> TSCDataHandle::Get()
{
	Initialize();
	return DataInstance;
}

TSCDataHandle::TSCDataHandle()
{
	//初始化存档数据
	InitSavaData();
}

TSharedRef<TSCDataHandle> TSCDataHandle::Create()
{
	TSharedRef<TSCDataHandle>DataRef = MakeShareable(new TSCDataHandle());

	return DataRef;
 }

void TSCDataHandle::ChangeLanguage(ECultrueTeam Cultrue)
{
	switch (Cultrue)
	{
	case ECultrueTeam::EN:
		FInternationalization::Get().SetCurrentCulture(TEXT("en"));
		break;
	case ECultrueTeam::ZH:
		FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
		break;
	}

	CurrentCultrue = Cultrue;

	TSCSingleton<TSCJsonHandle>::Get()->UpDataSaveData(GetEnumValueAsString<ECultrueTeam>(FString("ECultrueTeam"), CurrentCultrue), MusicVolume, SoundVolume, &SaveDataList);
}

void TSCDataHandle::SetVolume(float MusicVol, float SoundVol)
{
	if (MusicVol>0)
	{
		MusicVolume = MusicVol;
	}

	if (SoundVol>0)
	{
		SoundVolume = SoundVol;
	}

	TSCSingleton<TSCJsonHandle>::Get()->UpDataSaveData(GetEnumValueAsString<ECultrueTeam>(FString("ECultrueTeam"), CurrentCultrue), MusicVolume, SoundVolume, &SaveDataList);
}

//通过一个字符串获取枚举值
template<typename TEnum>
FString TSCDataHandle::GetEnumValueAsString(const FString& Name, TEnum Value)
{
	//这里应该是通过枚举名在什么地方找到对应的枚举，然后返回一个该枚举的指针
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	//如果枚举没找到，则返回错误信息
	if (!EnumPtr)
	{
		return FString("InValid");
	}
	return EnumPtr->GetNameStringByIndex((int32)Value);
}

//通过一个字符串
template<typename TEnum>
TEnum TSCDataHandle::GetEnumValueFromString(const FString& Name, FString Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr)
	{
		return TEnum(0);
	}
	return (TEnum)EnumPtr->GetIndexByName(FName(*FString(Value)));
}

void TSCDataHandle::InitSavaData()
{
	FString Culture;
	TSCSingleton<TSCJsonHandle>::Get()->SaveDataRead(Culture, MusicVolume, SoundVolume, SaveDataList);

	//初始化语言
	ChangeLanguage(GetEnumValueFromString<ECultrueTeam>(FString("ECultrueTeam"), Culture));

	/*输出下存档数据
	TSSCHelper::Debug(Culture + FString("--") + FString::SanitizeFloat(MusicVolume)+ FString("--")
		+ FString::SanitizeFloat(SoundVolume), FColor::Yellow, 20.f);
	for (TArray<FString>::TIterator It(SaveDataList); It; ++It)
	{
		TSSCHelper::Debug(*It, FColor::Yellow, 20.f);
	}

	*/
}
