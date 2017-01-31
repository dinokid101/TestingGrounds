// Copyright Game Dream Co.,Ltd

#include "TesingGrounds.h"
#include "PatrolBTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolComponent.h"

EBTNodeResult::Type UPatrolBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	auto PatrolTargets = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolComponent>()->PatrolPoints;
	if (PatrolTargets.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("NO PATROL TARGET!"));
		return EBTNodeResult::Failed; 
	}
	BlackboardComp->SetValueAsObject(ActorKey.SelectedKeyName, PatrolTargets[Index++]);
	if (Index >= PatrolTargets.Num())
	{
		BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, 0);
	}
	else
	{
		BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);
	}
	return EBTNodeResult::Succeeded;
}