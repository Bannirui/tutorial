//
// Created by dingrui on 2024/6/29.
//

#include "TPerson.h"

TPerson::TPerson(QString name, QObject* parent)
	: QObject(parent), m_name(name)
{

}
TPerson::TPerson(QString name, qint8 age, QObject* parent)
	: QObject(parent), m_name(name), m_age(age)
{

}
TPerson::~TPerson()
{
	qDebug("TPerson类对象被删除");
}
QString TPerson::getName()
{
	return this->m_name;
}
int TPerson::getAge()
{
	return this->m_age;
}
void TPerson::setAge(qint8 age)
{
	if (this->m_age != age)
	{
		this->m_age = age;
		// 发送信号
		this->ageChanged(this->m_age);
	}
}
void TPerson::incAge()
{
	this->m_age++;
	// 发送信号
	emit this->ageChanged(this->m_age);
}
