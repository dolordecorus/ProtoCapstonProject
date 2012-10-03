#ifndef FIELDDESCRIPTORCONTAINER_H
#define FIELDDESCRIPTORCONTAINER_H

//protobuf
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>

//Qt
#include <QWidget>

using namespace std;

class FieldDescriptorContainer
{
    protected:
        bool m_subfield;
        FieldDescriptorContainer * parent;

    public:
        virtual QWidget * getWidget(QWidget *parent = 0) = 0;
        virtual QWidget * getParent() = 0;
        virtual string getValue() = 0;
        virtual void setValue(string object) = 0;
        virtual string toString() = 0;

        bool isSubField()
        {
            return m_subfield;
        }
        void setSubfield(bool sub)
        {
            m_subfield = sub;
        }
        void setFieldParent(FieldDescriptorContainer * parent)
        {
            this->parent = parent;
        }
        FieldDescriptorContainer * getFieldParent()
        {
            if(m_subfield)
            {
                return parent;
            }

            return NULL;
        }
};

#endif // FIELDDESCRIPTORCONTAINER_H
