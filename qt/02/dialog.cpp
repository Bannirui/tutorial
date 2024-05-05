#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->connect(this->ui->radioButton_black, SIGNAL(clicked()), this, SLOT(set_font_color()));
    this->connect(this->ui->radioButton_red, SIGNAL(clicked()), this, SLOT(set_font_color()));
    this->connect(this->ui->radioButton_blue, SIGNAL(clicked()), this, SLOT(set_font_color()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btn_clear_clicked()
{
    this->ui->plainTextEdit->clear();
}


void Dialog::on_checkBox_underline_clicked(bool checked)
{
    QFont font = this->ui->plainTextEdit->font();
    font.setUnderline(checked);
    this->ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBox_italic_clicked(bool checked)
{
    QFont font = this->ui->plainTextEdit->font();
    font.setItalic(checked);
    this->ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBox_bold_clicked(bool checked)
{
    QFont font = this->ui->plainTextEdit->font();
    font.setBold(checked);
    this->ui->plainTextEdit->setFont(font);
}

void Dialog::set_font_color()
{
    QPalette p = this->ui->plainTextEdit->palette();
    if(this->ui->radioButton_black->isChecked())
    {
        p.setColor(QPalette::Text, Qt::black);
    }
    else if(this->ui->radioButton_blue->isChecked())
    {
        p.setColor(QPalette::Text, Qt::blue);
    }
    else if(this->ui->radioButton_red->isChecked())
    {
        p.setColor(QPalette::Text, Qt::red);
    }
    else {}
    this->ui->plainTextEdit->setPalette(p);
}

