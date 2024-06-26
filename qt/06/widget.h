#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
	class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
 Q_OBJECT

 public:
	Widget(QWidget* parent = nullptr);
	~Widget();

 private:
	Ui::Widget* ui;
 private slots:
	void on_pushButton_4_clicked();
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_checkBox_clicked(bool checked);
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_comboBox_2_currentIndexChanged(int index);
};
#endif // WIDGET_H
