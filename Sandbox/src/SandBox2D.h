#pragma once

#include "Newspace.h"



class Sandbox2D : public Newspace::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Newspace::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Newspace::Event& e) override;
private:
	Newspace::OrthographicCameraController m_CameraController;

	// Temp
	Newspace::Ref<Newspace::VertexArray> m_SquareVA;
	Newspace::Ref<Newspace::Shader> m_FlatColorShader;

	Newspace::Ref<Newspace::Texture2D> m_CheckerboardTexture;
	Newspace::Ref<Newspace::Framebuffer> m_Framebuffer;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};