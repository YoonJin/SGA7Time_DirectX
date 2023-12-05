#pragma once

#include "../IObserver.h"
#include "../Graphics.h"
#include "Renderer_ConstantBuffer.h"
#include "Renderer_Types.h"

class Renderer final : public IObserver
{
public:
	Renderer(class Context* const context);
	~Renderer();

	bool Initialize() override;
	void Update() override;
	void ReceivedNotify() override;

	void UpdateRenderables(class BaseScene* const scene);

private:
	void CreateConstantBuffers();
	void CreateRasterizerStates();
	void CreateBlendStates();

	void UpdateCameraBuffer();
	void UpdateObjectBuffer();
	void UpdateAnimationBuffer();

	void UpdateTextureBuffer();

private:
	void PassMain();

private:
	class Graphics* graphics = nullptr;
	class CameraComponent* camera = nullptr;
	std::shared_ptr<class D3D11_Pipeline> pipeline;

	CameraBuffer cpu_camera_buffer;
	std::shared_ptr<class D3D11_ConstantBuffer> gpu_camera_buffer;

	TransformBuffer cpu_object_buffer;
	std::shared_ptr<class D3D11_ConstantBuffer> gpu_object_buffer;

	AnimationBuffer cpu_animation_buffer;
	std::shared_ptr<class D3D11_ConstantBuffer> gpu_animation_buffer;

	TextureBuffer cpu_texture_buffer;
	std::shared_ptr<class D3D11_ConstantBuffer>gpu_texture_buffer;

private:
	std::map<RasterizerStateType, std::shared_ptr<class D3D11_RasterizerState>> rasterizers;
	std::map<BlendStateType, std::shared_ptr<class D3D11_BlendState>> blend_states;

	std::unordered_map<RenderableType, std::vector<class Actor*>> renderables;
};

