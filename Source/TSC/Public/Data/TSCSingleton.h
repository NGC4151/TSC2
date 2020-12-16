// shut up

#pragma once

#include "CoreMinimal.h"

/**
 * 模板单例
 */
template<class T>
class TSC_API TSCSingleton
{
public:
	static TSharedPtr<T>Get();

private:
	static void Initialize();

	static TSharedRef<T>Create();

private:
	static TSharedPtr<T> TInstance;
};

//初始化模板单例实例为空
template<class T>
TSharedPtr<T> TSCSingleton<T>::TInstance = NULL;

template<class T>
void TSCSingleton<T>::Initialize()
{
	//判断TInstance是否存在，不存在则创建
	if (!TInstance.IsValid())
	{
		TInstance = Create();
	}
}

template<class T>
TSharedRef<T> TSCSingleton<T>::Create()
{
	TSharedRef<T>TRef = MakeShareable(new T());
	return TRef;
}

template<class T>
TSharedPtr<T> TSCSingleton<T>::Get()
{
	Initialize();
	return TInstance;
}
