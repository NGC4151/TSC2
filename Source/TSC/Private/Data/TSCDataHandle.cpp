// shut up


#include "Data/TSCDataHandle.h"
#include "Internationalization/Internationalization.h"



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
	//默认设置游戏语言为中文
	CurrentCultrue = ECultrueTeam::ZH;
	//
	MusicVolume = 0.5f;
	SoundVolume = 0.5f;
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
}

