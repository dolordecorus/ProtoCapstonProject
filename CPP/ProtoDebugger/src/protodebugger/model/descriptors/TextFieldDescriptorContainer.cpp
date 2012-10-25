#include "TextFieldDescriptorContainer.h"
#include <sstream>

using namespace std;
using namespace google;
using namespace protobuf;

QWidget * TextFieldDescriptorContainer::getWidget(QWidget * parent)
{

}

QWidget * TextFieldDescriptorContainer::getParent()
{
    if(m_textField != NULL)
    {
       return m_textField->parentWidget();
    }

    return NULL;
}

Object * TextFieldDescriptorContainer::getValue()
{

}

void TextFieldDescriptorContainer::setValue(Object * value)
{

}

QString TextFieldDescriptorContainer::toString()
{
    string str = "TextField name = " + this->m_name;
    return QString(str.c_str());
}

bool TextFieldDescriptorContainer::buildMsg(Message *msg)
{
    return true;
}

