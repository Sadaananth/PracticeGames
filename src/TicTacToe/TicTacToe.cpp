#include "TicTacToe.hpp"

#include <array>
#include <iostream>

TicTacToe::TicTacToe()
{
    m_titleText.setString("Player 1's turn");
    if(!m_titleFont.loadFromFile("src/TicTacToe/resources/AntiCorona.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    m_titleText.setFont(m_titleFont);
    m_titleText.setCharacterSize(50);
    m_titleText.setPosition(sf::Vector2f(20, 20));
    m_titleText.setFillColor(sf::Color::Yellow);

    m_titleEndVerticalLine.setSize(sf::Vector2f(width(), space_width));
    m_titleEndVerticalLine.setPosition(sf::Vector2f(0, title_height));
    m_titleEndVerticalLine.setFillColor(sf::Color::White);

    m_firstVerticalLine.setSize(sf::Vector2f(space_width, boardHeight()));
    m_firstVerticalLine.setPosition(sf::Vector2f(cell_width, boardStart()));
    m_firstVerticalLine.setFillColor(sf::Color::White);
    
    m_secondVerticalLine.setSize(sf::Vector2f(space_width, boardHeight()));
    m_secondVerticalLine.setPosition(sf::Vector2f(cell_width + space_width + cell_width, boardStart()));
    m_secondVerticalLine.setFillColor(sf::Color::White);
    
    m_firstHorizontalLine.setSize(sf::Vector2f(width(), space_width));
    m_firstHorizontalLine.setPosition(sf::Vector2f(0, boardStart() + cell_height));
    m_firstHorizontalLine.setFillColor(sf::Color::White);
    
    m_secondHorizontalLine.setSize(sf::Vector2f(width(), space_width));
    m_secondHorizontalLine.setPosition(sf::Vector2f(0, boardStart() + cell_height + space_width + cell_height));
    m_secondHorizontalLine.setFillColor(sf::Color::White);

    m_thirdHorizontalLine.setSize(sf::Vector2f(width(), space_width));
    m_thirdHorizontalLine.setPosition(sf::Vector2f(0, boardStart() + boardHeight()));
    m_thirdHorizontalLine.setFillColor(sf::Color::White);

    m_restartButtonBox.left = width() / 2 - restartButtonWidth / 2;
    m_restartButtonBox.right = m_restartButtonBox.left + restartButtonWidth;
    m_restartButtonBox.top = boardStart() + boardHeight() + space_width + 20;
    m_restartButtonBox.bottom = m_restartButtonBox.top + restartButtonHeight;

    m_restartButton.setSize(sf::Vector2f(restartButtonWidth, restartButtonHeight));
    m_restartButton.setPosition(m_restartButtonBox.left, m_restartButtonBox.top);
    m_restartButton.setFillColor(sf::Color::Blue);

    m_restartText.setString("Restart");
    m_restartText.setFont(m_titleFont);
    m_restartText.setCharacterSize(30);
    m_restartText.setPosition(width() / 2 - 50, m_restartButtonBox.top);
    m_restartText.setFillColor(sf::Color::White);

    for(uint8_t index = 0; index < m_box.size(); index++) {
        m_box[index].left = (index % 3) * cell_width + (index % 3) * space_width;
        m_box[index].right = m_box[index].left + cell_width;
        m_box[index].top = (index / 3) * cell_height + (index / 3) * space_width + boardStart();
        m_box[index].bottom = m_box[index].top + cell_height;
    }

    m_indexHighlightRectangle.setSize(sf::Vector2f(cell_width, cell_height));
    m_indexHighlightRectangle.setOutlineThickness(10);
    m_indexHighlightRectangle.setOutlineColor(sf::Color::Magenta);
    m_indexHighlightRectangle.setFillColor(sf::Color::Black);
    updateHighLightRectangle();
}

TicTacToe::~TicTacToe()
{

}

uint32_t TicTacToe::width() const
{
    static uint32_t local_width = cell_width * 3 + 2 * space_width;
    return local_width;
}

uint32_t TicTacToe::height() const
{
    static uint32_t local_height = boardHeight() + boardStart() + footer_height;
    return local_height;
}

uint32_t TicTacToe::boardHeight() const
{
    static uint32_t local_height = cell_height * 3 + 2 * space_width;
    return local_height;
}

uint32_t TicTacToe::boardStart() const
{
    static uint32_t local_height =  title_height + space_width;
    return local_height;
}

void TicTacToe::draw(sf::RenderWindow& window)
{
    window.draw(m_titleText);
    window.draw(m_titleEndVerticalLine);
    window.draw(m_firstVerticalLine);
    window.draw(m_secondVerticalLine);
    window.draw(m_firstHorizontalLine);
    window.draw(m_secondHorizontalLine);
    window.draw(m_thirdHorizontalLine);
    window.draw(m_restartButton);
    window.draw(m_restartText);
    window.draw(m_indexHighlightRectangle);

    for(auto& circle : m_o_list) {
        window.draw(circle.o);
    }

    for(auto& x_ : m_x_list) {
        window.draw(x_.x[0]);
        window.draw(x_.x[1]);
    }

    window.draw(m_winner_line);
}

void TicTacToe::mouseButtonPressed(const sf::Event& event)
{
    uint32_t x = event.mouseButton.x;
    uint32_t y = event.mouseButton.y;

    if(y > boardStart() + boardHeight()) {
        handleFooterPressed(x, y);
        return;
    }

    if(m_x_list.size() + m_o_list.size() >= 9) {
        return;
    }

    if(m_now_x) {
        if(updateX(x, y)) {
            m_now_x = !m_now_x;
        }
    } else {
        if(updateO(x, y)) {
            m_now_x = !m_now_x;
        }
    }
}

void TicTacToe::keyButtonPressed(const sf::Event& event)
{
    switch(event.key.code) {
        case sf::Keyboard::Enter:
            if(m_now_x) {
                updateX(m_box[m_index_active].right - 20, m_box[m_index_active].bottom - 20);
                m_now_x = !m_now_x;
            } else {
                updateO(m_box[m_index_active].right - 20, m_box[m_index_active].bottom - 20);
                m_now_x = !m_now_x;
            }
            break;
        case sf::Keyboard::Right:
            m_index_active = (m_index_active + 1) % 9;
            updateHighLightRectangle();
            break;
        case sf::Keyboard::Left:
            m_index_active = (m_index_active - 1) % 9;
            updateHighLightRectangle();
            break;
        case sf::Keyboard::Down:
            m_index_active = (m_index_active + 3) % 9;
            updateHighLightRectangle();
            break;
        case sf::Keyboard::Up:
            m_index_active = (m_index_active - 3) % 9;
            updateHighLightRectangle();
            break;
        default:
            break;
    }
}

uint8_t TicTacToe::getBoxIndex(uint32_t x, uint32_t y)
{
    for(uint8_t index = 0; index < m_box.size(); index++) {
        if(x > m_box[index].left &&
            x <= m_box[index].right && 
            y > m_box[index].top &&
            y <= m_box[index].bottom)
            {
                return index;
            }
    }

    return -1;
}

bool TicTacToe::updateX(uint32_t x, uint32_t y)
{
    uint32_t offset = 20;
    if(auto index = getBoxIndex(x, y); index >= 0) {
        x_object local_x_object;
        local_x_object.x[0].setSize(sf::Vector2f(10, cell_height + 20));
        local_x_object.x[0].setFillColor(sf::Color::Yellow);
        local_x_object.x[0].rotate(-45);

        local_x_object.x[1].setSize(sf::Vector2f(10, cell_height + 20));
        local_x_object.x[1].setFillColor(sf::Color::Yellow);
        local_x_object.x[1].rotate(45);

        local_x_object.x[0].setPosition(sf::Vector2f(m_box[index].left + offset, m_box[index].top + offset));
        local_x_object.x[1].setPosition(sf::Vector2f(m_box[index].right - offset, m_box[index].top + offset));
        local_x_object.index = index;

        m_x_list.emplace_back(local_x_object);

        m_titleText.setString("Player 2's turn");

        validateWin();

        return true;
    }

    return false;
}

bool TicTacToe::updateO(uint32_t x, uint32_t y)
{
    uint32_t offset = 20;
    if(auto index = getBoxIndex(x, y); index >= 0) {
        o_object local_o_object;
        local_o_object.o.setRadius((cell_width / 2) - 20);
        local_o_object.o.setFillColor(sf::Color::Black);
        local_o_object.o.setOutlineThickness(10);
        local_o_object.o.setOutlineColor(sf::Color::Yellow);

        local_o_object.o.setPosition(sf::Vector2f(sf::Vector2f(m_box[index].left + offset, m_box[index].top + offset)));
        local_o_object.index = index;

        m_o_list.emplace_back(local_o_object);

        m_titleText.setString("Player 1's turn");

        validateWin();

        return true;
    }

    return false;
}

void TicTacToe::updateHighLightRectangle()
{
    m_indexHighlightRectangle.setPosition(sf::Vector2f(m_box[m_index_active].left, m_box[m_index_active].top));
}

void TicTacToe::validateWin()
{
    if(m_x_list.size() < 3 && m_o_list.size() < 3) {
        return;
    }

    std::array<bool, 9> visited{};
    auto createWinRectangle = [this](std::array<bool, 9>& visited) {
        bool win{true};
        if(visited[0] && visited[1] && visited[2]) {
            m_winner_line.setSize(sf::Vector2f(3 * cell_height, 20));
            m_winner_line.setPosition(m_box[0].left + 10, m_box[0].top + cell_height / 2);
            m_winner_line.setFillColor(sf::Color::Green);
            m_winner_line.setRotation(0);
        } else if(visited[3] && visited[4] && visited[5]) {
            m_winner_line.setSize(sf::Vector2f(3 * cell_height, 20));
            m_winner_line.setPosition(m_box[3].left + 10, m_box[3].top + cell_height / 2);
            m_winner_line.setFillColor(sf::Color::Green);
            m_winner_line.setRotation(0);
        } else if(visited[6] && visited[7] && visited[8]) {
            m_winner_line.setSize(sf::Vector2f(3 * cell_height, 20));
            m_winner_line.setPosition(m_box[6].left + 10, m_box[6].top + cell_height / 2);
            m_winner_line.setFillColor(sf::Color::Green);
            m_winner_line.setRotation(0);           
        } else if(visited[0] && visited[3] && visited[6]) {
            m_winner_line.setSize(sf::Vector2f(3 * cell_height, 20));
            m_winner_line.setPosition(m_box[0].left + cell_width / 2, m_box[0].top + 10);
            m_winner_line.setFillColor(sf::Color::Green);
            m_winner_line.setRotation(90);            
        } else if(visited[1] && visited[4] && visited[7]) {
            m_winner_line.setSize(sf::Vector2f(3 * cell_height, 20));
            m_winner_line.setPosition(m_box[1].left + cell_width / 2, m_box[1].top + 10);
            m_winner_line.setFillColor(sf::Color::Green);
            m_winner_line.setRotation(90);            
        } else if(visited[2] && visited[5] && visited[8]) {
            m_winner_line.setSize(sf::Vector2f(3 * cell_height, 20));
            m_winner_line.setPosition(m_box[2].left + cell_width / 2, m_box[2].top + 10);
            m_winner_line.setFillColor(sf::Color::Green);
            m_winner_line.setRotation(90);            
        } else if(visited[0] && visited[4] && visited[8]) {
            m_winner_line.setSize(sf::Vector2f(4 * cell_height, 20));
            m_winner_line.setPosition(m_box[0].left + 10, m_box[0].top + 10);
            m_winner_line.setFillColor(sf::Color::Green);
            m_winner_line.setRotation(45);            
        } else if(visited[2] && visited[4] && visited[6]) {
            m_winner_line.setSize(sf::Vector2f(4 * cell_height, 20));
            m_winner_line.setPosition(m_box[2].right - 10, m_box[2].top + 10);
            m_winner_line.setFillColor(sf::Color::Green);
            m_winner_line.setRotation(135);
        } else {
            win = false;
        }

        m_win = win;
    };
    if(m_now_x) {
        for(auto x : m_x_list) {
            visited[x.index] = true;
        }
        createWinRectangle(visited);
        if(m_win) {
            m_titleText.setString("Congrats Player 1 win");
        }
    } else {
        for(auto o : m_o_list) {
            visited[o.index] = true;
        }
        createWinRectangle(visited);
        if(m_win) {
            m_titleText.setString("Congrats Player 2 win");
        }
    }
}

void TicTacToe::handleFooterPressed(uint32_t x, uint32_t y)
{
    if(x >= m_restartButtonBox.left 
        && x <= m_restartButtonBox.right
        && y >= m_restartButtonBox.top
        && y <= m_restartButtonBox.bottom) {
            m_titleText.setString("Player 1's turn");
            m_now_x = true;
            m_o_list.clear();
            m_x_list.clear();
            m_winner_line.setSize(sf::Vector2f(0,0));
            m_index_active = 0;
            updateHighLightRectangle();
        }
}
