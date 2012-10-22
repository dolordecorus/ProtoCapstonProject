#ifndef BOOLEANFIELDDESCRIPTORCONTAINER_H
#define BOOLEANFIELDDESCRIPTORCONTAINER_H

#include <QWidget>
#include <QCheckBox>
#include <QString>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include "FieldDescriptorContainer.h"

//Forward Declarations
template<class Object> class FieldDescriptorContainer;

class BooleanFieldDescriptorContainer : public FieldDescriptorContainer<class Object>
{
    private:
        QCheckBox * m_check;

    public:
        BooleanFieldDescriptorContainer(google::protobuf::FieldDescriptor * field):FieldDescriptorContainer<Object>(field){}
       ~BooleanFieldDescriptorContainer()
        {
            delete m_field;
            delete &m_value;
            delete &m_defaultValue;
        }

        virtual QWidget * getWidget(QWidget * parent = 0);
        virtual QWidget * getParent();
        virtual Object * getValue();
        virtual void setValue(Object * value);
        virtual QString toString();
        //virtual buildMsg();
};

#endif // BOOLEANFIELDDESCRIPTORCONTAINER_H
