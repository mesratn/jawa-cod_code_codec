#include "CodecRender.hpp"

const float					CodecRender::_scale 				= 4.f;
const sf::Vector2u	CodecRender::_spriteSize 		= sf::Vector2u(52, 89);
const sf::Vector2f	CodecRender::_positions[2]	= {sf::Vector2f(30.f, 30.f) * _scale, sf::Vector2f(236.f, 30.f) * _scale};

CodecRender::CodecRender()
	: mysf::GraphicRender()
{
	_gls.resize(2);

	_gls[0].add(&_background);
	_gls[1].add(&_talker[0]);
	_gls[1].add(&_talker[1]);
}

CodecRender::~CodecRender()
{
	for (unsigned int i = Resource::Texture::First; i < Resource::Texture::Size; ++i)
		_thl.unload(i);
}

bool CodecRender::init()
{
	if (_dialogue.parse("resources/missions/mission01.csv") == false)
		return false;

	if (_thl.setDefault("resources/images/default.png") == false)
		return false;

	_thl.load(Resource::Texture::Codec, 		"resources/images/codec.png");
	_thl.load(Resource::Texture::Snake, 		"resources/images/talker_snake.png");
	_thl.load(Resource::Texture::Otacon, 		"resources/images/talker_otacon.png");
	_thl.load(Resource::Texture::Campbell,	"resources/images/talker_campbell.png");
	_thl.load(Resource::Texture::Meryl, 		"resources/images/talker_meryl.png");
	_thl.load(Resource::Texture::Naomi, 		"resources/images/talker_naomi.png");
	_thl.load(Resource::Texture::Mei, 			"resources/images/talker_mei.png");
	_thl.load(Resource::Texture::Miller, 		"resources/images/talker_miller.png");
	_thl.load(Resource::Texture::Wolf, 			"resources/images/talker_wolf.png");
	_thl.load(Resource::Texture::Jim, 			"resources/images/talker_jim.png");

	_background.sprite().setTexture(_thl[Resource::Texture::Codec]);
	_background.sprite().setScale(_scale, _scale);

	_talker[0].sprite().setTexture(_thl[Resource::Texture::Campbell]);
	_talker[1].sprite().setTexture(_thl[Resource::Texture::Snake]);
	for (unsigned int i = 0; i < 2; ++i)
	{
		_talker[i].sprite().setTextureRect(sf::IntRect(0, 0, _spriteSize.x, _spriteSize.y));
		_talker[i].setPosition(_positions[i]);
		_talker[i].sprite().setScale(_scale, _scale);
	}
	return true;
}

mysf::GraphicRender * CodecRender::update(const sf::Time & deltaTime, const mysf::Event & event)
{
	if (event.isClosed() || event.key().isDown(sf::Keyboard::Escape))
		return 0;

	_spl.removeStoppedSounds();
  _gls.update(deltaTime, event);
	return this;
}
