#include "game.h"
#include <QString>
#include <QDebug>
Game::Game(Type type)
{
    m_output = new int[Game::LOGIC_SIZE.width() * Game::LOGIC_SIZE.height()];
    m_state  = new int[Game::LOGIC_SIZE.width() * Game::LOGIC_SIZE.height()];
    m_type = type;
    init();

}

Game::~Game()
{
    delete [] m_output;
    delete [] m_state;
}

void Game::init()
{
    memset(m_output, 0, Game::LOGIC_SIZE.width() * Game::LOGIC_SIZE.height() * sizeof(int));
    memset(m_state, 0,  Game::LOGIC_SIZE.width() * Game::LOGIC_SIZE.height() * sizeof(int));
    //  here you can set pattern


    auto set = [this](int x, int y, QString s)
    {
        int p = 0;
        for (auto c : s)
        {
            int a;
            if(c == '#')
            {
                a = 1;
            }
            else
            {
                a = 0;
            }
            this->m_state[y*Game::LOGIC_SIZE.width() + x + p] = a;
            p++;
        }
    };

    if(m_type == Type::Random)
    {
        for (int i = 0; i < Game::LOGIC_SIZE.width() * Game::LOGIC_SIZE.height(); i++)
        {
            m_state[i] = rand() % 2;
        }
    }

    else if(m_type == Type::Pentomino)
    {
        // R-Pentomino
        //        set(80, 50, "  ## ");
        //        set(80, 51, " ##  ");
        //        set(80, 52, "  #  ");
        setPattern(80, 50, "  ## ");
        setPattern(80, 51, " ##  ");
        setPattern(80, 52, "  #  ");
    }

    else if(m_type == Type::GosperGliderGun)
    {
        // Gosper Glider Gun
        set(60, 45, "........................#............");
        set(60, 46, "......................#.#............");
        set(60, 47, "............##......##............##.");
        set(60, 48, "...........#...#....##............##.");
        set(60, 49, "##........#.....#...##...............");
        set(60, 50, "##........#...#.##....#.#............");
        set(60, 51, "..........#.....#.......#............");
        set(60, 52, "...........#...#.....................");
        set(60, 53, "............##.......................");
    }

    else if(m_type == Type::InfiniteGrowth)
    {
        // Infinite Growth
        set(20, 50, "########.#####...###......#######.#####");
    }

    else if(m_type == Type::Custom)
    {
        // Custom Pattern (population: 5)
        setPattern(60, 45, "..................#..................");
        setPattern(60, 46, ".................##..................");
        setPattern(60, 47, "..................##................");
    }


    m_image = QImage(Game::LOGIC_SIZE.width(), Game::LOGIC_SIZE.width(), QImage::Format_RGB32);
    m_image.fill(QColor(Qt::black));
}

void Game::update()
{


    // Store output state
    for (int i = 0; i < Game::LOGIC_SIZE.width()*Game::LOGIC_SIZE.height(); i++)
        m_output[i] = m_state[i];

    for (int x = 1; x < Game::LOGIC_SIZE.width() - 1; x++)
        for (int y = 1; y < Game::LOGIC_SIZE.height() - 1; y++)
        {
            // The secret of artificial life =================================================
            int nNeighbours =	cell(x - 1, y - 1) + cell(x - 0, y - 1) + cell(x + 1, y - 1) +
                              cell(x - 1, y + 0) +          0         + cell(x + 1, y + 0) +
                              cell(x - 1, y +	1) + cell(x + 0, y + 1) + cell(x + 1, y + 1);

            if (cell(x, y) == 1)
                m_state[y*Game::LOGIC_SIZE.width() + x] = nNeighbours == 2 || nNeighbours == 3;
            else
                m_state[y*Game::LOGIC_SIZE.width() + x] = nNeighbours == 3;
            // ===============================================================================


            if (cell(x, y) == 1)
            {
                m_image.setPixelColor(x, y, QColor(Qt::white));
            }
            else
            {
                m_image.setPixelColor(x, y, QColor(Qt::black));
            }
        }
}

QImage Game::image() const
{
    return m_image;
}

void Game::setType(Type type)
{
    m_type = type;
}

void Game::print()
{
    for (int i = 0; i < Game::LOGIC_SIZE.width() * Game::LOGIC_SIZE.height(); i++)
    {
        if(m_state[i])
            qDebug() << i << " " << m_state[i];
    }
}

void Game::setPattern(int x, int y, QString pattern)
{
    int p = 0;
    for (auto c : pattern)
    {
        int a;
        if(c == '#')
        {
            a = 1;
        }
        else
        {
            a = 0;
        }
        this->m_state[y*Game::LOGIC_SIZE.width() + x + p] = a;
        p++;
    }
}

int Game::cell(int x, int y) const
{
    return m_output[y * Game::LOGIC_SIZE.width() + x];
}
