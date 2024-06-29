//
// Created by dingrui on 2024/6/29.
//

#ifndef INC_03__TPERSON_H_
#define INC_03__TPERSON_H_

#include <QObject>

class TPerson : public QObject
{
 Q_OBJECT
 public:
	explicit TPerson(QString name, QObject* parent = nullptr);
	explicit TPerson(QString name, qint8 age, QObject* parent = nullptr);
	~TPerson();
	QString getName();
	int getAge();
	void setAge(qint8 age);
	void incAge();
 signals:
	// signals不需要实现
	// 年龄发生了变化要把信号传出去
	void ageChanged(int age);
 private:
	QString m_name;
	quint8 m_age = 10;
	quint8 m_score = 80;
};

#endif //INC_03__TPERSON_H_
