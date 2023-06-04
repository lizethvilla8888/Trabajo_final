#ifndef GANASTE_H
#define GANASTE_H

#include <QWidget>

namespace Ui {
class ganaste;
}

class ganaste : public QWidget
{
    Q_OBJECT

public:
    explicit ganaste(QWidget *parent = nullptr);
    ~ganaste();

private:
    Ui::ganaste *ui;
};

#endif // GANASTE_H
