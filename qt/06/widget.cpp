#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent), ui(new Ui::Widget)
{
	ui->setupUi(this);
}

Widget::~Widget()
{
	delete ui;
}

void Widget::on_pushButton_4_clicked()
{
	this->ui->plainTextEdit->clear();
}

void Widget::on_pushButton_clicked()
{
	this->ui->comboBox->clear();
	for (int i = 1; i <= 10; i++)
	{
		this->ui->comboBox->addItem(QString("item%1").arg(i));
	}
}

void Widget::on_pushButton_2_clicked()
{
	this->ui->comboBox->clear();
}

void Widget::on_pushButton_3_clicked()
{
	this->ui->comboBox_2->clear();
	QMap<QString, int> map;
	map.insert("淮安", 1);
	map.insert("苏州", 2);
	map.insert("上海", 3);
	foreach(const QString& city, map.keys())
		this->ui->comboBox_2->addItem(city, map[city]);
}

void Widget::on_checkBox_clicked(bool checked)
{
	this->ui->comboBox->setEditable(checked);
}


void Widget::on_comboBox_currentTextChanged(const QString &arg1)
{
    this->ui->plainTextEdit->appendPlainText(arg1);
}


void Widget::on_comboBox_2_currentIndexChanged(int index)
{
    QString str=this->ui->comboBox_2->currentText()+", "+this->ui->comboBox_2->currentData().toString();
    this->ui->plainTextEdit->appendPlainText(str);
}

