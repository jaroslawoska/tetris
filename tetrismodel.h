#ifndef TETRISMODEL_H
#define TETRISMODEL_H

#include <array>
#include <QAbstractTableModel>
#include <QPoint>
#include <QtQml/qqml.h>

class TetrisModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT

    Q_ENUMS(Roles)
public:
    enum Roles {
        CellRole
    };

    QHash<int, QByteArray> roleNames() const override {
        return {
            { CellRole, "value" }
        };
    }

    explicit TetrisModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    Q_INVOKABLE void nextStep();
    Q_INVOKABLE void clear();

private:
    static constexpr int width = 10;
    static constexpr int height = 22;
    static constexpr int size = width * height;

    using StateContainer = std::array<bool, size>;
    StateContainer m_screenState;

    static std::size_t cellIndex(const QPoint &coordinates);
};

#endif // TETRISMODEL_H
