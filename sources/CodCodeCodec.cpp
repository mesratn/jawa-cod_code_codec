#include "CodCodeCodec.hpp"

CodCodeCodec::CodCodeCodec()
	: mysf::Engine()
{
	_window.create(sf::VideoMode(1280, 960), "CodCodeCodec");
}

CodCodeCodec::~CodCodeCodec()
{

}

bool CodCodeCodec::init(int /* ac */, char ** /* av */)
{
	_grender = new CodecRender;

	_event.key().setEventType(mysf::EventType::OnPressed);
	return _grender->init();
}
