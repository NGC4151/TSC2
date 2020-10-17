// shut up


#include "Data/TSCDataHandle.h"



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

