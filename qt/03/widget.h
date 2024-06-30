//
// Created by dingrui on 2024/6/29.
//

#ifndef INC_03__WIDGET_H_
#define INC_03__WIDGET_H_

#include <QWidget>

// 前向声明
class TPerson;

QT_BEGIN_NAMESPACE
namespace Ui
{
	class widget;
}
QT_END_NAMESPACE

class widget : public QWidget
{
 Q_OBJECT

 public:
	explicit widget(QWidget* parent = nullptr);
	~widget() override;

 private:
	TPerson* boy;
	TPerson* girl;

 private slots:
	// 信号槽函数 需要实现
	void do_ageChanged(int age);
	void do_spinChanged(int val);

	void on_btnBoyInc_clicked();
	void on_btnGirlInc_clicked();
	void on_btnClear_clicked();
	void on_btnClassInfo_clicked();
 private:
	Ui::widget* ui;
};

#endif //INC_03__WIDGET_H_
