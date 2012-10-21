#include "NumberFieldDescriptorContainer.h"
#include <sstream>

using namespace std;
using namespace google;
using namespace protobuf;

QWidget * NumberFieldDescriptorContainer::getWidget(QWidget * parent)
{
    std::stringstream ss;
    if(m_textField == NULL)
    {
        m_textField = new QTextEdit(parent);

        if (m_type == FieldDescriptor::CPPTYPE_DOUBLE)
        {
            ss << (double)(long) m_value;
            m_textField->setText(QString::fromStdString(ss.str()));
        }
        else if (m_type == FieldDescriptor::CPPTYPE_FLOAT)
        {
            ss << (float)(int) m_value;
            m_textField->setText(QString::fromStdString(ss.str()));
        }
        else if (m_type == FieldDescriptor::CPPTYPE_INT32)
        {
            m_textField->setText(QString((int)m_value));
        }
        else if (m_type == FieldDescriptor::CPPTYPE_INT64)
        {
            ss << (long)m_value ;
            m_textField->setText(QString::fromStdString(ss.str()));
        }
        else if (m_type == FieldDescriptor::CPPTYPE_UINT32)
        {
            m_textField->setText(QString((unsigned int)m_value));
        }
        else if (m_type == FieldDescriptor::CPPTYPE_UINT64)
        {
            ss << (unsigned long)m_value ;
            m_textField->setText(QString::fromStdString(ss.str()));
        }
    }
    else if (m_textField->parentWidget() != parent)
    {
        m_textField->setParent(parent);
    }

    return m_textField;
}

QWidget * NumberFieldDescriptorContainer::getParent()
{
    if(m_textField != NULL)
    {
       return m_textField->parentWidget();
    }

    return NULL;
}

Object * NumberFieldDescriptorContainer::getValue()
{
    return this->m_value;
}

void NumberFieldDescriptorContainer::setValue(Object * value)
{
   this->m_value = value;
}

QString NumberFieldDescriptorContainer::toString()
{
    string str = "NumberField name = " + this->m_name;
    return QString(str.c_str());
}
