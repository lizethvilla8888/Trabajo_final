#ifndef PERDIO_H
#define PERDIO_H

#include <QWidget>

namespace Ui {
class perdio;
}

class perdio : public QWidget
{
    Q_OBJECT

public:
    explicit perdio(QWidget *parent = nullptr);
    ~perdio();

private:
    Ui::perdio *ui;
};

#endif // PERDIO_H
