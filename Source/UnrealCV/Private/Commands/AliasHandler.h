#pragma once
#include "CommandHandler.h"

class FAliasCommandHandler : public FCommandHandler
{
public:
	void RegisterCommands();

	/** vrun : run UE4 built-in commands */
	FExecStatus VRun(const TArray<FString>& Args);

	/** vexec : run UE4 blueprint
		Can support arguments, but can not support return value
	*/
	FExecStatus VExec(const TArray<FString>& Args);

	FExecStatus VExecWithOutput(const TArray<FString>& Args);
};
