#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btn_clear_clicked();

    void on_checkBox_underline_clicked(bool checked);

    void on_checkBox_italic_clicked(bool checked);

    void on_checkBox_bold_clicked(bool checked);

    void set_font_color();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
