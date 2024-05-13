
#pragma once

#include "CoreMinimal.h"
#include "NodeFactory.h"

class FNodeFactoryPatch : FNodeFactory
{
public:
	static FConnectionDrawingPolicy* CreateConnectionPolicy_Hook(const UEdGraphSchema* Schema, int32 InBackLayerID, int32 InFrontLayerID, float ZoomFactor, const FSlateRect& InClippingRect, FSlateWindowElementList& InDrawElements, UEdGraph* InGraphObj);
};
