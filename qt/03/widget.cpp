//
// Created by dingrui on 2024/6/29.
//

// You may need to build the project (run Qt uic code generator) to get "ui_widget.h" resolved

#include "widget.h"
#include "ui_widget.h"
#include "TPerson.h"

widget::widget(QWidget* parent) :
	QWidget(parent), ui(new Ui::widget)
{
	ui->setupUi(this);
	this->boy = new TPerson("小明", 10, this);
	this->boy->setProperty("sex", "boy");
	this->girl = new TPerson("小花", 20, this);
	this->girl->setProperty("sex", "girl");
	// 收到spinBox的值 没办法辨别是男孩还是女孩的年龄发生了变化 因此给spinBox添加属性
	this->ui->spinBoy->setProperty("isBoy", true);
	this->ui->spinGirl->setProperty("isBoy", false);
	// 对象年龄发生变化的时候
	connect(this->boy, SIGNAL(ageChanged(int)), this, SLOT(do_ageChanged(int)));
	connect(this->girl, SIGNAL(ageChanged(int)), this, SLOT(do_ageChanged(int)));
	connect(this->boy, SIGNAL(ageChanged(int)), this->ui->spinBoy, SLOT(setValue(int)));
	connect(this->girl, SIGNAL(ageChanged(int)), this->ui->spinGirl, SLOT(setValue(int)));
	// 增加/减少按钮
	connect(this->ui->spinBoy, SIGNAL(valueChanged(int)), this, SLOT(do_spinChanged(int)));
	connect(this->ui->spinGirl, SIGNAL(valueChanged(int)), this, SLOT(do_spinChanged(int)));
	// 元对象信息
	connect(this->ui->btnClassInfo, SIGNAL(clicked()), this, SLOT(on_btnClassInfo_clicked()));
}

widget::~widget()
{
	delete ui;
}
void widget::do_ageChanged(int age)
{
	TPerson* obj = qobject_cast<TPerson*>(sender());
	QString str = QString("姓名=%1 性别=%2 年龄=%3")
		.arg(obj->getName())
		.arg(obj->property("sex").toString())
		.arg(age);
	this->ui->plainTextEdit->appendPlainText(str);
}
void widget::do_spinChanged(int val)
{
	QSpinBox* spinBox = qobject_cast<QSpinBox*>(sender());
	if (spinBox->property("isBoy").toBool())this->boy->setAge(val);
	else this->girl->setAge(val);
}
void widget::on_btnBoyInc_clicked()
{
	boy->incAge();
}
void widget::on_btnGirlInc_clicked()
{
	girl->incAge();
}
void widget::on_btnClear_clicked()
{
	this->ui->plainTextEdit->clear();
}

void widget::on_btnClassInfo_clicked()
{
	const QMetaObject* meta = this->boy->metaObject();
	this->ui->plainTextEdit->appendPlainText(QString("类名称: %1\n").arg(meta->className()));
}