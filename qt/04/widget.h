//
// Created by dingrui on 2024/6/30.
//

#ifndef INC_04__WIDGET_H_
#define INC_04__WIDGET_H_

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
	explicit Widget(QWidget* parent = nullptr);
	~Widget() override;

 private:
	Ui::Widget* ui;

 private slots:
	void on_btnGetCharUnicode_clicked();
	void on_btnClear_clicked();
	void on_btnCharFeat_clicked();
	void on_btnConvLatin_clicked();
	void on_btnConvUtf16_clicked();
	void on_btnCmpQChar_clicked();
};

#endif //INC_04__WIDGET_H_
