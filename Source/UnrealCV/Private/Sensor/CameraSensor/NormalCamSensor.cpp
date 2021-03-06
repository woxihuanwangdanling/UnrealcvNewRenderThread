#include "UnrealCVPrivate.h"
#include "NormalCamSensor.h"

UNormalCamSensor::UNormalCamSensor(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	FString NormalPPMaterialPath = TEXT("Material'/UnrealCV/WorldNormal.WorldNormal'");
	ConstructorHelpers::FObjectFinder<UMaterial> Material(*NormalPPMaterialPath);

	// this->SurfaceNormalPPMaterial = Material.Object;
	// SetPostProcessMaterial(SurfaceNormalPPMaterial);
	SetPostProcessMaterial(Material.Object);
}

void UNormalCamSensor::OnRegister()
{
	Super::OnRegister();

	TextureTarget = NewObject<UTextureRenderTarget2D>(this);
	bool bUseLinearGamma = false;
	TextureTarget->InitCustomFormat(FilmWidth, FilmHeight, EPixelFormat::PF_B8G8R8A8, bUseLinearGamma);
	this->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
	this->bCaptureEveryFrame = true;
	this->bCaptureOnMovement = false;
}
