#include <Newspace.h>
#include "imgui/imgui.h"

class ExampleLayer :public Newspace::Layer
{
public:
	ExampleLayer() : Layer("example")
	{}
	void OnUpdate() override
	{
		//NSPACE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Newspace::Event& event) override
	{
		//if (event.GetEventType() == Newspace::EventType::KeyPressed)
		//{
		//	Newspace::KeyPressedEvent& e = (Newspace::KeyPressedEvent&)event;
		//	if (e.GetKeyCode() == HZ_KEY_TAB)
		//		NSPACE_TRACE("Tab key is pressed (event)!");
		//	NSPACE_TRACE("(char)e.GetKeyCode()");
		//}
	}

	
	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

};
class SandBox : public Newspace::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Newspace::ImGuiLayer());
	}
	~SandBox()
	{

	}
};

Newspace::Application* Newspace::createApplication()
{
	return new SandBox();
}
