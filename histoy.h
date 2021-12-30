#ifndef HISTOY_H
#define HISTOY_H

#include <QWidget>

namespace Ui {
class histoy;
}

class histoy : public QWidget
{
    Q_OBJECT

public:
    explicit histoy(QWidget *parent = nullptr);
    ~histoy();

private:
    Ui::histoy *ui;
};

#endif // HISTOY_H
