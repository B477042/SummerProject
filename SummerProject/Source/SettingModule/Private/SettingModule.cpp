// Fill out your copyright notice in the Description page of Project Settings.

#include "SettingModule.h"
#include "Logging.h"

#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FSettingModule"

void FSettingModule::StartupModule()
{
}

void FSettingModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSettingModule, SettingModule);