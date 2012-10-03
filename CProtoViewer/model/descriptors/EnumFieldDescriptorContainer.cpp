#include "EnumFieldDescriptorContainer.h"

using namespace google;
using namespace protobuf;
using namespace std;

EnumFieldDescriptorContainer::EnumFieldDescriptorContainer(FieldDescriptor * field)
{
    m_field = field;
    m_name = field->name();
    if(field->has_default_value())
    {
        m_defaultValue = field->default_value_enum();
    }
}

EnumFieldDescriptorContainer::~EnumFieldDescriptorContainer()
{
}

string EnumFieldDescriptorContainer::toString()
{
    return "EnumField name = " + m_name;
}

QWidget * EnumFieldDescriptorContainer::getWidget(QWidget * parent)
{
    if(!m_comboField)
    {
        m_comboField = new QComboBox(parent);
        m_comboField->addItems(getValues());
        if(m_defaultValue)
        {
            m_comboField->setCurrentIndex(m_defaultValue->index());
        }
    }
    else if (m_comboField->parent() != parent)
    {
        m_comboField->setParent(parent);
    }
    return m_comboField;
}

string EnumFieldDescriptorContainer::getValue()
{
    if (m_value)
    {
        return m_value->name();
    }
    else if (m_defaultValue)
    {
        return m_defaultValue->name();
    }

    return m_field->enum_type()->value(0)->name();
}

void EnumFieldDescriptorContainer::setValue(string object)
{
    if(object.empty())
    {
        for( int i = 0; i < m_field->enum_type()->value_count(); ++i)
        {
            if( equals( m_field->enum_type()->value(i)->name(), object) )
            {
                object = m_field->enum_type()->value(i)->name();
                break;
            }
        }
    }
}

QStringList EnumFieldDescriptorContainer::getValues()
{
    QStringList result = QStringList();

    for( int i = 0; i < m_field->enum_type()->value_count(); ++i)
    {
        result[m_field->enum_type()->value(i)->index()] = QString(m_field->enum_type()->value(i)->name().c_str());
    }

    if(m_field->is_optional())
    {
        result += "";
    }

    return result;
}

EnumValueDescriptorProto * EnumFieldDescriptorContainer::buildMsg()
{
    EnumValueDescriptorProto * result;
    result->set_name(m_field->name());

    return result;
}

QWidget * EnumFieldDescriptorContainer::getParent()
{
    if (m_comboField)
    {
        return m_comboField->parentWidget();
    }

    return NULL;
}
