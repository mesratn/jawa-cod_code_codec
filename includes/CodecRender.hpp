#ifndef CODEC_RENDER_HPP_
# define CODEC_RENDER_HPP_

# include "GraphicRender.hpp"
# include "ResourceHolder.hpp"

# include "Dialogue.hpp"
# include "SpriteNode.hpp"
# include "Resource.hpp"

class CodecRender : public mysf::GraphicRender
{
public:
	CodecRender();
	CodecRender(const CodecRender &) = delete;
	CodecRender & operator=(const CodecRender &) = delete;
	virtual ~CodecRender();

	virtual bool init();
  virtual mysf::GraphicRender * update(const sf::Time & deltaTime, const mysf::Event & event);

protected:
	Dialogue									_dialogue;

	mysf::TextureHolder 			_thl;
	SpriteNode								_background;
	SpriteNode								_talker[2];

	static const float				_scale;
	static const sf::Vector2u	_spriteSize;
	static const sf::Vector2f _positions[2];
};

#endif // !CODEC_RENDER_HPP_
