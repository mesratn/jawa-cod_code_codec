#include "SpriteNode.hpp"

SpriteNode::SpriteNode()
{

}

SpriteNode::~SpriteNode()
{

}

sf::Sprite & SpriteNode::sprite()
{
	return _sprite;
}

const sf::Sprite & SpriteNode::sprite() const
{
	return _sprite;
}

void SpriteNode::updateCurrent(const sf::Time & /* deltaTime */, const mysf::Event & /* event */)
{

}

void SpriteNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}
