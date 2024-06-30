//
// Created by dingrui on 2024/6/30.
//

#ifndef INC_05__WIDGET_H_
#define INC_05__WIDGET_H_

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;
};


#endif //INC_05__WIDGET_H_
