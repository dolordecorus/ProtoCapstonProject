#include "NumberFieldDescriptorContainer.h"

using namespace std;
using namespace google;
using namespace protobuf;

QWidget * NumberFieldDescriptorContainer::getWidget(QWidget * parent)
{
    if(m_textField == NULL)
    {
        m_textField = new QTextEdit(parent);
        m_textField->setText(QString(this->getValue()));
    }
    else if (m_textField->parent() != parent)
    {
        m_textField->setParent(parent);
    }

    return m_textField;
}

QWidget * NumberFieldDescriptorContainer::getParent()
{
    if(m_textField != NULL)
    {
       return m_textField->parent();
    }

    return NULL;
}

Object NumberFieldDescriptorContainer::getValue()
{
    return this->m_value;
}

void NumberFieldDescriptorContainer::setValue(Object value)
{
   this->m_value = value;
}

QString NumberFieldDescriptorContainer::toString()
{
    string str = "NumberField name = " + this->m_name;
    return QString(str.c_str());
}
