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
    QColor getPos(QColor val, int posX, int posY);

private:
    int rotate(int px, int py);
    void genATetromino();

private:
    int m_posX = 0;
    int m_posY = 0;
    int m_rotation = 0;

    static constexpr int m_width = 4;
    static constexpr int m_height = 4;
    static constexpr int m_size = m_width * m_height;
    static const int MAX_TERMINOS = 6;

    using TetrominoContainer = std::array<QColor, m_size>;
    TetrominoContainer m_container;
    TetrominoContainer m_tetromino[MAX_TERMINOS] = {{QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Blue,
                                                     QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Blue,
                                                     QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Blue,
                                                     QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Blue, QColorConstants::Blue},

                                                    {QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray,
                                                    QColorConstants::Gray, QColorConstants::Yellow, QColorConstants::Yellow, QColorConstants::Gray,
                                                    QColorConstants::Gray, QColorConstants::Yellow, QColorConstants::Yellow, QColorConstants::Gray,
                                                    QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray},

                                                    {QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Red,
                                                    QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Red,
                                                    QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Red,
                                                    QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Red},

                                                    {QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray,
                                                    QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray,
                                                    QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Green,
                                                    QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Green, QColorConstants::Green},

                                                    {QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray,
                                                    QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray,
                                                    QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Black,
                                                    QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Black, QColorConstants::Black},

                                                    {QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray,
                                                    QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Gray,
                                                    QColorConstants::Gray, QColorConstants::Gray, QColorConstants::Cyan, QColorConstants::Gray,
                                                    QColorConstants::Gray, QColorConstants::Cyan, QColorConstants::Cyan, QColorConstants::Cyan}};


};

#endif // TETROMINO_H
