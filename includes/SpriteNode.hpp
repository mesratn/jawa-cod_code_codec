#ifndef SPRITE_NODE_HPP_
# define SPRITE_NODE_HPP_

# include <iostream>

# include "SceneNode.hpp"
# include "Event.hpp"

class SpriteNode : public mysf::SceneNode
{
public:
	SpriteNode();
	SpriteNode(const SpriteNode & o) = delete;
	SpriteNode & operator=(const SpriteNode & o) = delete;
	virtual ~SpriteNode();

	sf::Sprite & sprite();
	const sf::Sprite & sprite() const;

protected:
	virtual void	updateCurrent(const sf::Time & deltaTime, const mysf::Event & event);
	virtual void	drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;

protected:
	sf::Sprite _sprite;
};

#endif // !SPRITE_NODE_HPP_
