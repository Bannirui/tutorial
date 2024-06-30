//
// Created by dingrui on 2024/6/30.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Widget.h" resolved

#include "widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget* parent) :
	QWidget(parent), ui(new Ui::Widget)
{
	ui->setupUi(this);
	// 信号与槽连接
}

Widget::~Widget()
{
	delete ui;
}

void Widget::on_btnGetCharUnicode_clicked()
{
	QString str = this->ui->lineEditStr->text();
	if (str.isEmpty()) return;
	for (qint16 i = 0; i < str.size(); i++)
	{
		QChar ch = str.at(i);
		char16_t unicode = ch.unicode();
		QString chStr(ch);
		QString info = chStr + QString::asprintf("\t Unicode编码=0x%X", unicode);
		this->ui->plainTextEdit->appendPlainText(info);
	}
}

void Widget::on_btnClear_clicked()
{
	this->ui->plainTextEdit->clear();
}

void Widget::on_btnCharFeat_clicked()
{
	QString str = this->ui->lineEditChar->text();
	if (str.isEmpty()) return;
	QChar ch = str.at(0);
	char16_t unicode = ch.unicode();
	QString info = str + QString::asprintf("\t Unicode编码=0x%X", unicode);
	this->ui->plainTextEdit->appendPlainText(info);

	this->ui->checkIsDigit->setChecked(ch.isDigit());
	this->ui->checkIsLetter->setChecked(ch.isLetter());
	this->ui->checkIsLLetterOrNumber->setChecked(ch.isLetterOrNumber());
	this->ui->checkIsUpper->setChecked(ch.isUpper());
	this->ui->checkIsLower->setChecked(ch.isLower());
	this->ui->checkIsMark->setChecked(ch.isMark());
	this->ui->checkIsSpace->setChecked(ch.isSpace());
	this->ui->checkIsSymbol->setChecked(ch.isSymbol());
	this->ui->checkIsPunct->setChecked(ch.isPunct());
}
void Widget::on_btnConvLatin_clicked()
{
	this->ui->plainTextEdit->appendPlainText("not support");
}
void Widget::on_btnConvUtf16_clicked()
{
	this->ui->plainTextEdit->appendPlainText("not support");
}
void Widget::on_btnCmpQChar_clicked()
{
	this->ui->plainTextEdit->appendPlainText("not support");
}
