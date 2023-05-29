#include <Newspace.h>
class ExampleLayer :public Newspace::Layer
{
public:
	ExampleLayer() : Layer("example")
	{}
	void OnUpdate() override
	{
		NSPACE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Newspace::Event& event) override
	{
		NSPACE_TRACE("{0}", event);
	}
};
class SandBox : public Newspace::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
	}
	~SandBox()
	{

	}
};

Newspace::Application* Newspace::createApplication()
{
	return new SandBox();
}
