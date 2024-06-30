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
	connect(this->ui->dial, &QSlider::valueChanged, this, &Widget::do_value_changed);
	connect(this->ui->horizontalSlider, &QSlider::valueChanged, this, &Widget::do_value_changed);
	connect(this->ui->horizontalScrollBar, &QSlider::valueChanged, this, &Widget::do_value_changed);
}

Widget::~Widget()
{
	delete ui;
}
void Widget::do_value_changed(int v)
{
	this->ui->dial->setValue(v);
	this->ui->horizontalSlider->setValue(v);
	this->ui->horizontalScrollBar->setValue(v);
	this->ui->progressBar->setValue(v);
}
void Widget::on_checkBox_clicked(bool checked)
{
	this->ui->progressBar->setTextVisible(checked);
}
void Widget::on_checkBox_2_clicked(bool checked)
{
	this->ui->progressBar->setInvertedAppearance(checked);
}
void Widget::on_radioButton_clicked()
{
	this->ui->progressBar->setFormat("%p%");
}
void Widget::on_radioButton_2_clicked()
{
	this->ui->progressBar->setFormat("%v%");
}