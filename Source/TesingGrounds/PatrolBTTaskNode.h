// Copyright Game Dream Co.,Ltd

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "PatrolBTTaskNode.generated.h"


UCLASS()
class TESINGGROUNDS_API UPatrolBTTaskNode : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:
	UPROPERTY(EditAnywhere, Category = "Setup")
	struct FBlackboardKeySelector IndexKey;
	UPROPERTY(EditAnywhere, Category = "Setup")
	struct FBlackboardKeySelector ActorKey;
};
