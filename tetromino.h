#ifndef TETROMINO_H
#define TETROMINO_H

#include <QObject>
#include <QColor>

class Tetromino : public QObject
{
    Q_OBJECT
public:
    explicit Tetromino(QObject *parent = nullptr);
    Tetromino(Tetromino & tetromino);
    Tetromino & operator=(Tetromino &tetromino);
    bool inside(int x_max, int y_max);
    void clear();
    void moveLeft();
    void moveRight();
    void moveDown();
    void rotate();
    bool getPos(bool val, int posX, int posY);
    QColor getTetrominoColor();

private:
    int rotate(int px, int py);
    void genATetromino();

private:
    int m_posX = 0;
    int m_posY = 0;
    int m_rotation = 0;
    QColor m_color;

    static constexpr int m_width = 4;
    static constexpr int m_height = 4;
    static constexpr int m_size = m_width * m_height;
    static const int MAX_TERMINOS = 6;

    using TetrominoContainer = std::array<bool, m_size>;
    TetrominoContainer m_container;
    QColor m_tetrominoColors[MAX_TERMINOS] = {QColorConstants::Blue,
                                              QColorConstants::Red,
                                              QColorConstants::Yellow,
                                              QColorConstants::Gray,
                                              QColorConstants::Red,
                                              QColorConstants::Green};

    TetrominoContainer m_tetromino[MAX_TERMINOS] = {{false, false, false, true,
                                                     false, false, false, true,
                                                     false, false, false, true,
                                                     false, false, true, true},
                                                    {false, false, false, false,
                                                    false, true, true, false,
                                                    false, true, true, false,
                                                    false, false, false, false},
                                                    {false, false, false, true,
                                                    false, false, false, true,
                                                    false, false, false, true,
                                                    false, false, false, true},
                                                    {false, false, false, false,
                                                    false, false, false, false,
                                                    false, false, false, true,
                                                    false, false, true, true},
                                                    {false, false, false, false,
                                                    false, false, false, false,
                                                    false, false, false, true,
                                                    false, false, true, true},
                                                    {false, false, false, false,
                                                    false, false, false, false,
                                                    false, false, true, false,
                                                    false, true, true, true}};


};

#endif // TETROMINO_H
