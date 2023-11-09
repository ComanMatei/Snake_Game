#include "Snake.h"


Snake::Snake() : snakeBody(std::list<sf::Sprite>(4))
{
    snakeHead = --snakeBody.end();
    snakeTail = snakeBody.begin();
}

Snake::~Snake()
{
}

void Snake::Init(const sf::Texture& texture)
{
    float x = 16.f;
    for (auto& piece : snakeBody)
    {
        piece.setTexture(texture);
        piece.setPosition({ x, 16.f });
        x += 16.f;
    }
}

void Snake::Move(const sf::Vector2f& direction)
{
    snakeTail->setPosition(snakeHead->getPosition() + direction);
    snakeHead = snakeTail;
    ++snakeTail;

    if (snakeTail == snakeBody.end())
    {
        snakeTail = snakeBody.begin();
    }
}

bool Snake::IsOn(const sf::Sprite& other) const
{
    return other.getGlobalBounds().intersects(snakeHead->getGlobalBounds());
}

void Snake::Grow(const sf::Vector2f& direction)
{
    sf::Sprite newPiece;
    newPiece.setTexture(*(snakeBody.begin()->getTexture()));
    newPiece.setPosition(snakeHead->getPosition() + direction);

    snakeHead = snakeBody.insert(++snakeHead, newPiece);
}

bool Snake::IsSelfIntersecting() const
{
    bool flag = false;

    for (auto piece = snakeBody.begin(); piece != snakeBody.end(); ++piece)
    {
        if (snakeHead != piece)
        {
            flag = IsOn(*piece);

            if (flag)
            {
                break;
            }
        }
    }

    return flag;
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& piece : snakeBody)
    {
        target.draw(piece);
    }
}