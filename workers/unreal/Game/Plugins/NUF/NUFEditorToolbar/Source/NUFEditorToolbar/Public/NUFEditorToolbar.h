// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"
#include "TickableEditorObject.h"

class FToolBarBuilder;
class FMenuBuilder;
class FUICommandList;

DECLARE_LOG_CATEGORY_EXTERN(LogNUFEditor, Log, All);

class FNUFEditorToolbarModule : public IModuleInterface, public FTickableEditorObject
{
public:
	FNUFEditorToolbarModule();

	void StartupModule() override;
	void ShutdownModule() override;
	void PreUnloadCallback() override;

	/** FTickableEditorObject interface */
	void Tick(float DeltaTime) override;
	bool IsTickable() const override
	{
		return true;
	}

	TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FNUFEditorToolbarModule, STATGROUP_Tickables);
	}

private:
	void RegisterSettings();
	void UnregisterSettings();
	bool HandleSettingsSaved();

	void MapActions(TSharedPtr<FUICommandList> PluginCommands);
	void SetupToolbar(TSharedPtr<FUICommandList> PluginCommands);
	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);

	void CreateSnapshotButtonClicked();

private:
	TSharedPtr<FUICommandList> PluginCommands;
};